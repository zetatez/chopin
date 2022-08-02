/* See LICENSE file for copyright and license details. */
// chopin.c

/* Author: lorenzo */
/* E-mail: lorenzo<zetatez@icloud.com> */

#include <cstdio>
#include <getopt.h>
#include <iostream>
#include <map>
#include <string.h>
#include <string>

struct OpenRule {
  std::string mine_type;
  std::string action;
  bool background;
};

struct ExecRule {
  std::string ext;
  std::string action;
};

typedef std::map<std::string, OpenRule> OpenMap;
typedef std::map<std::string, ExecRule> ExecMap;

enum Action {
  NOACTION = 0,
  MagicOpen,
  MagicExec,
  MagicCopy,
  MagicMove,
  MagicRemove
};

std::string replace(std::string, const std::string &, const std::string &);
int magicOpen(const std::string filename);
int magicExec(const std::string filename);
int magicCopy(const std::string filename);
int magicMove(const std::string filename);
int magicRemove(const std::string filename);
void help();
void version();

#include "./config.h"

int main(int argc, char *argv[]) {
  enum Action action = NOACTION;
  std::string filename;

  struct option longopts[] = {
      {"open",    no_argument, 0, 'o'},
      {"exec",    no_argument, 0, 'e'},
      {"copy",    no_argument, 0, 'c'},
      {"move",    no_argument, 0, 'm'},
      {"remove",  no_argument, 0, 'r'},
      {"help",    no_argument, 0, 'h'},
      {"version", no_argument, 0, 'v'}};

  int opt = 0;
  while ((opt = getopt_long(argc, argv, ":oecmrhv", longopts, NULL)) != -1) {
    switch (opt) {
    case 'o':
      action = MagicOpen;
      break;
    case 'e':
      action = MagicExec;
      break;
    case 'c':
      action = MagicCopy;
      break;
    case 'm':
      action = MagicMove;
      break;
    case 'r':
      action = MagicRemove;
      break;
    case 'h':
      help();
      return EXIT_SUCCESS;
    case 'v':
      version();
      return EXIT_SUCCESS;
    default:
      std::cout << "chopin: option -";
      std::cout << (char)optopt;
      std::cout << " is invalid" << std::endl;
      return EXIT_FAILURE;
    }
  }

  if (optind < argc) {
    do {
      filename = argv[optind];
    } while (++optind < argc);
  }

  if (!filename.length()) {
    return EXIT_FAILURE;
  }
  filename = replace(filename, " ", "\\ ");
  filename = replace(filename, "(", "\\(");
  filename = replace(filename, ")", "\\)");

  int flag = -1;
  switch (action) {
  case MagicOpen:
    flag = magicOpen(filename);
    break;
  case MagicExec:
    flag = magicExec(filename);
    break;
  case MagicCopy:
    flag = magicCopy(filename);
    break;
  case MagicMove:
    flag = magicMove(filename);
    break;
  case MagicRemove:
    flag = magicRemove(filename);
    break;
  default:
    std::cout << "No Action" << std::endl;
  }

  return (flag == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

std::string replace(std::string str, const std::string &from,
                    const std::string &to) {
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos +=
        to.length(); // Handles case where 'to' is a substring of 'from'
  }
  return str;
}

std::string exec(std::string command) {
  char buffer[128];
  std::string result = "";

  // open pipe to file
  FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }

  // read till end of process:
  while (!feof(pipe)) {
    if (fgets(buffer, 128, pipe) != NULL)
      result += buffer;
  }

  pclose(pipe);
  return result;
}

std::string get_file_prefix(const std::string &filename) {
  std::string prefix = "";
  size_t last_index = filename.find_last_of("/");
  if (last_index == std::string::npos) {
    return "./";
  }
  prefix = filename.substr(0, last_index + 1);
  return prefix;
}

std::string get_file_extension(const std::string &filename) {
  std::string extension = "";
  size_t last_index = filename.find_last_of(".");
  if (last_index == std::string::npos) {
    return ""; // no extension
  }
  extension = filename.substr(last_index + 1);
  return extension;
}

std::string get_file_mine_type(const std::string &filename) {
  std::string cmd = "file --mime-type --brief " + filename;
  std::string mine_type = exec(cmd);
  mine_type.erase(mine_type.find_last_not_of("\n\r\t") + 1);
  return mine_type;
}

int magicOpen(const std::string filename) {
  if (filename.length() == 0) {
    return 1;
  }

  std::string cmd = "";
  /* std::string ext = get_file_extension(filename); */
  std::string mineType = get_file_mine_type(filename);

  // line search
  for (auto &item : open_rules) {
    if (item.mine_type == mineType) {
      cmd = item.action;
      cmd = cmd + " " + filename;
      if (item.background) {
        cmd = cmd + " &";
      }
      std::cout << cmd << std::endl;
      system(cmd.c_str());
      return EXIT_SUCCESS;
    }
  }
  std::cout << "Not match any action" << std::endl;

  /* OpenMap open_map; */
  /* for (auto &item : open_rules) { */
  /*     open_map[item.mine_type] = item; */
  /* } */

  /* if (open_map.find(mineType) != open_map.end()) { */
  /*     cmd = open_map[mineType].action; */
  /*     cmd = cmd + " " + filename; */
  /*     if (open_map[mineType].background) { */
  /*         cmd = cmd + " &"; */
  /*     } */
  /*     std::cout << cmd << std::endl; */
  /*     system(cmd.c_str()); */
  /* } else { */
  /*     std::cout << "No action" << std::endl; */
  /* } */

  return EXIT_FAILURE;
}

int magicExec(const std::string filename) {
  if (filename.length() == 0) {
    return 1;
  }

  char cmd[1024];
  std::string ext = get_file_extension(filename);
  /* std::string mineType = get_file_mine_type(filename); */

  // line search
  for (auto &item : exec_rules) {
    if (item.ext == ext) {
      sprintf(cmd, item.action.c_str(), filename.c_str());
      std::cout << cmd << std::endl;
      system(cmd);
      return EXIT_SUCCESS;
    }
  }
  std::cout << "Not match any action" << std::endl;

  /* ExecMap exec_map; */
  /* for (auto &item : exec_rules) { */
  /*     exec_map[item.ext] = item; */
  /* } */

  /* if (exec_map.find(ext) != exec_map.end()) { */
  /*     sprintf(cmd, exec_map[ext].action.c_str(), filename.c_str()); */
  /*     std::cout << cmd << std::endl; */
  /*     system(cmd); */
  /* } else { */
  /*     std::cout << "No action" << std::endl; */
  /* } */

  return EXIT_SUCCESS;
}

int magicCopy(const std::string filename) {
  if (filename.length() == 0) {
    return 1;
  }

  char cmd[1024];
  std::string ext = get_file_extension(filename);
  std::string prefix = get_file_prefix(filename);

  sprintf(cmd, "cp %s %s %s", copy_opt, filename.c_str(), prefix.c_str());
  std::cout << cmd;
  char *new_filename = NULL;
  size_t len;
  getline(&new_filename, &len, stdin);
  strcat(cmd, new_filename);
  system(cmd);

  return EXIT_SUCCESS;
}

int magicMove(const std::string filename) {
  if (filename.length() == 0) {
    return 1;
  }

  char cmd[1024];
  std::string ext = get_file_extension(filename);
  std::string prefix = get_file_prefix(filename);

  sprintf(cmd, "mv %s %s %s", move_opt, filename.c_str(), prefix.c_str());
  std::cout << cmd;
  char *new_filename = NULL;
  size_t len;
  getline(&new_filename, &len, stdin);
  strcat(cmd, new_filename);
  system(cmd);

  return EXIT_SUCCESS;
}

int magicRemove(const std::string filename) {
  if (filename.length() == 0) {
    return 1;
  }

  char cmd[1024];
  std::string ext = get_file_extension(filename);
  std::string prefix = get_file_prefix(filename);

  sprintf(cmd, "rm %s %s", remove_opt, filename.c_str());
  std::cout << cmd << std::endl;
  system(cmd);

  return EXIT_SUCCESS;
}

void help() {
  std::string helpstr = "\
    NAME\n\
        chopin - A cli tool that greatly improves your work efficiency.\n\
    \n\
    SYNOPSIS\n\
        chopin [-vhoecmr] file\n\
    \n\
    DESCRIPTION\n\
        chopin is a tool for cli to open, exec, cp, mv, rm file automatically.\n\
    \n\
    OPTIONS\n\
        -v     prints version information to cli and exit.\n\
    \n\
        -o     open a file with your default settings automatically.\n\
    \n\
        -e     exec a script with your default settings automatically.\n\
    \n\
        -c     copy a file.\n\
    \n\
        -m     move a file.\n\
    \n\
        -r     remove a file.\n\
    \n\
    CUSTOMIZATION\n\
        chopin is customized by creating a custom config.h and recompiling the source code. This keeps it fast, secure and simple.\n\
    \n\
    BUGS\n\
        Send all bug reports with a patch to zetatez@icloud.com. \n\
    \n";

  std::cout << helpstr << std::endl;
  exit(EXIT_SUCCESS);
}

void version() {
  std::cout << "chopin-";
  std::cout << (char*)VERSION;
  std::cout << std::endl;
  exit(EXIT_SUCCESS);
}
