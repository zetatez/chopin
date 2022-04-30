/* See LICENSE file for copyright and license details. */
// chopin.c

/* Author: lorenzo */
/* E-mail: lorenzo<zetatez@icloud.com> */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <libgen.h>
#include <string.h>
#include "./config.h"
#include "./chopin.h"

#define MAX_CMD_LENGTH 4086
#define MAX_FIL_LENGTH 2048
enum Action {NOACTION=0,OPEN,EXEC,CP,MV,RM};

int main(int argc, char *argv[]) {
    enum Action action = NOACTION;
    char *file = NULL;

    // parse args
    struct option longopts[] = {
        { "open"    , no_argument, 0, 'o' },
        { "exec"    , no_argument, 0, 'e' },
        { "cp"      , no_argument, 0, 'c' },
        { "mv"      , no_argument, 0, 'm' },
        { "rm"      , no_argument, 0, 'r' },
        { "help"    , no_argument, 0, 'h' },
        { "version" , no_argument, 0, 'v' }
    };

    int opt = 0;
    while ((opt = getopt_long(argc, argv, ":oecmrhv", longopts, NULL)) != -1) {
        switch(opt) {
            case 'o': action = OPEN                                                    ; break;
            case 'e': action = EXEC                                                    ; break;
            case 'c': action = CP                                                      ; break;
            case 'm': action = MV                                                      ; break;
            case 'r': action = RM                                                      ; break;
            case 'h': help()                                                           ; break;
            case 'v': version()                                                        ; break;
            default : fprintf(stderr, "%s: option '%c' is invalid\n", argv[0], optopt) ; break;
        }
    }

    // get file: fail if file name contains space. you should not use space in your folder name or file name!
    if (optind < argc) {
        do {
            file = argv[optind];
        } while(++optind < argc);
    }

    if (!strlen(file)) {
        return 0;
    }

    // action
    int flag = -1;
    switch (action) {
        case NOACTION:
            printf("No action was specified, exit!\n");
            break;
        case OPEN:
            flag = magic_open(file); break;
        case EXEC:
            flag = magic_exec(file); break;
        case CP:
            flag = magic_cp(file)  ; break;
        case MV:
            flag = magic_mv(file)  ; break;
        case RM:
            flag = magic_rm(file)  ; break;
        default:
            printf("NO ACTION! exit.\n");
            break;
    }

    return (flag == 0) ? EXIT_SUCCESS: EXIT_FAILURE;
}

int magic_open(const char *filename) {
    if (!filename) {
        return 1;
    }

    char cmd[MAX_CMD_LENGTH] = "";

    char *filenamebk = NULL;
    filenamebk = malloc(strlen(filename)+1);
    if (!filenamebk) {
        return -1;
    }
    strcpy(filenamebk, filename);

    // get mime type
    FILE *ptr = NULL;
    char *mime_type = NULL;
    mime_type = malloc(128);
    if (!mime_type) {
        return -1;
    }

    sprintf(cmd, "file --dereference --brief --mime-type \"%s\"", filename);
    ptr = popen(cmd, "r");
    fgets(mime_type, 128, ptr);
    pclose(ptr);
    // print mime_type to stdout
    // fputs(mime_type, stdout);

    char *tmp = NULL;
    if ((tmp = strstr(mime_type, "\n"))) { *tmp = '\0'; }

    // get base_name, dir_name, suffix
    char *base_name = NULL;
    char *suffix    = NULL;
    base_name = basename(filenamebk);
    suffix = strrchr(base_name, '.');

    int flag = 0;
    cmd[0] = '\0';
    if (NULL != suffix) {
        for (int i=0; NULL != open_map[i].key; i++) {
            if ( 0 == strcmp(open_map[i].key, suffix)) {
                flag = 1;
                if (open_map[i].flag) {
                    sprintf(cmd, "(%s \"%s\" &);exit", open_map[i].value, filename);
                } else {
                    sprintf(cmd, "%s \"%s\"", open_map[i].value, filename);
                }
                puts(cmd);
                system(cmd);
                break;
            }
        }
    }

    // use open_else_map setting if not found in open_map
    cmd[0] = '\0';
    if (NULL == suffix || !flag) {
        for (int i=0; NULL != open_else_map[i].key; i++) {
            if ( 0 == strcmp(open_else_map[i].key, mime_type)) {
                if (open_else_map[i].flag) {
                    sprintf(cmd, "(%s \"%s\" &);exit", open_else_map[i].value, filename);
                } else {
                    sprintf(cmd, "%s \"%s\"", open_else_map[i].value, filename);
                }
                puts(cmd);
                system(cmd);
                break;
            }
        }
    }

    // free
    free(mime_type);
    mime_type = NULL;
    free(filenamebk);
    filenamebk = NULL;

    return 0;
}

int magic_exec(const char *filename) {
    if (!filename) {
        return 1;
    }
    char cmd[MAX_CMD_LENGTH] = "";

    char *filenamebk = NULL;
    filenamebk = malloc(strlen(filename)+1);
    if (!filenamebk) {
        return -1;
    }
    strcpy(filenamebk, filename);

    // get base_name, suffix
    char *base_name = NULL;
    char *suffix    = NULL;
    base_name = basename(filenamebk);
    suffix = strrchr(base_name, '.');

    cmd[0] = '\0';
    if (NULL != suffix) {
        for (int i=0; NULL != exec_map[i].key; i++) {
            if ( 0 == strcmp(exec_map[i].key, suffix)) {
                sprintf(cmd, exec_map[i].value, filename);
                puts(cmd);
                system(cmd);
                break;
            }
        }
    } else {
        for (int i=0; NULL != exec_else_map[i].key; i++) {
            if ( 0 == strcmp(exec_else_map[i].key, "*")) {
                sprintf(cmd, exec_else_map[i].value, filename);
                puts(cmd);
                system(cmd);
                break;
            }
        }
    }
    
    // free
    free(filenamebk);
    filenamebk = NULL;

    return 0;
}

int magic_cp(const char *filename) {
    if (!filename) {
        return 1;
    }

    extern const char *cp_opt;
    char cmd[MAX_CMD_LENGTH] = "";

    char *filenamebk = NULL;
    filenamebk = malloc(strlen(filename)+1);
    if (!filenamebk) {
        return -1;
    }
    strcpy(filenamebk, filename);

    char *dir_name  = NULL;
    dir_name  = dirname(filenamebk);

    cmd[0] = '\0';
    sprintf(cmd, "cp %s %s %s/", cp_opt, filename, dir_name);
    printf("%s", cmd);
    char *new_base_name = NULL;
    size_t len;
    getline(&new_base_name, &len, stdin);
    strcat(cmd, new_base_name);

    // puts(cmd);
    system(cmd);

    // free
    free(filenamebk);
    filenamebk = NULL;

    return 0;
}

int magic_mv(const char *filename) {
    if (!filename) {
        return 1;
    }

    extern const char *mv_opt;
    char cmd[MAX_CMD_LENGTH] = "";
    
    char *filenamebk = NULL;
    filenamebk = malloc(strlen(filename)+1);
    if (!filenamebk) {
        return -1;
    }
    strcpy(filenamebk, filename);

    char *dir_name  = NULL;
    dir_name  = dirname(filenamebk);

    cmd[0] = '\0';
    sprintf(cmd, "mv %s %s %s/", mv_opt, filename, dir_name);
    printf("%s", cmd);
    char *new_base_name = NULL;
    size_t len;
    getline(&new_base_name, &len, stdin);
    strcat(cmd, new_base_name);

    // puts(cmd);
    system(cmd);
    
    // free
    free(filenamebk);
    filenamebk = NULL;

    return 0;
}

int magic_rm(const char *filename) {
    if (!filename) {
        return 1;
    }

    extern const char *rm_opt;
    char cmd[MAX_CMD_LENGTH] = "";
    
    char *filenamebk = NULL;
    filenamebk = malloc(strlen(filename)+1);
    if (!filenamebk) {
        return -1;
    }
    strcpy(filenamebk, filename);

    cmd[0] = '\0';
    sprintf(cmd, "rm %s \"%s\"", rm_opt, filename);

    puts(cmd);
    system(cmd);

    // free
    free(filenamebk);
    filenamebk = NULL;

    return 0;
}

void help() {
    fprintf(stderr, "%s", "Usage: chopin [-vhoecmr] [FILE]\n");
    fprintf(stderr, "%s", "  -o, --open         open a file with your default settings automatically\n");
    fprintf(stderr, "%s", "  -e, --exec         exec a file with your default settings automatically\n");
    fprintf(stderr, "%s", "  -c, --cp           cp a file\n");
    fprintf(stderr, "%s", "  -m, --mv           mv a file\n");
    fprintf(stderr, "%s", "  -r, --rm           rm a file\n");
    fprintf(stderr, "%s", "  -h, --help         help\n");
    fprintf(stderr, "%s", "  -v, --version      version\n");
    exit(EXIT_FAILURE);
}

void version() {
    printf("chopin-1.0\n");
    exit(EXIT_SUCCESS);
}

