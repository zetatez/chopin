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

// VERSION is already defined in config.mk
// #define VERSION                 "1.0"

/* macros */
#define MAX_CMD_LENGTH          4086
#define MAX_FIL_LENGTH          2048
#define LENGTH(X)               (sizeof X / sizeof X[0])
#define NUM_OPEN_MAP		    (LENGTH(open_map))
#define NUM_OPEN_MAP_ELSE       (LENGTH(open_map_else))
#define NUM_EXEC_MAP		    (LENGTH(exec_map))
#define NUM_EXEC_MAP_ELSE       (LENGTH(exec_map_else))
#define FREE(X)                 free(X); X=NULL

/* enums */
enum Action {NOACTION=0,OP,EX,CP,MV,RM};

/* data structure */
struct KFV {
    const char *key;
    bool flag;
    const char *value;
};

struct KV {
    const char *key;
    const char *value;
};

/* function declarations */
int magic_op(const char *file_name);
int magic_ex(const char *file_name);
int magic_cp(const char *file_name);
int magic_mv(const char *file_name);
int magic_rm(const char *file_name);
void help();
void version();

/* variables */

/* configuration, allows nested code to access above variables */
#include "./config.h"

int
main(int argc, char *argv[]) {
    enum Action action = NOACTION;
    char *file = NULL;

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
            case 'o': action = OP                                                      ; break;
            case 'e': action = EX                                                      ; break;
            case 'c': action = CP                                                      ; break;
            case 'm': action = MV                                                      ; break;
            case 'r': action = RM                                                      ; break;
            case 'h': help()                                                           ; break;
            case 'v': version()                                                        ; break;
            default : fprintf(stderr, "%s: option '%c' is invalid\n", argv[0], optopt) ; break;
        }
    }

    if (optind < argc) {
        do {
            file = argv[optind];
        } while(++optind < argc);
    }

    if (!strlen(file)) { return 0; }

    int flag = -1;
    switch (action) {
        case OP:
            flag = magic_op(file); break;
        case EX:
            flag = magic_ex(file); break;
        case CP:
            flag = magic_cp(file)  ; break;
        case MV:
            flag = magic_mv(file)  ; break;
        case RM:
            flag = magic_rm(file)  ; break;
        default:
            printf("NO ACTION!\n") ; break;
    }

    return (flag == 0) ? EXIT_SUCCESS: EXIT_FAILURE;
}

/* function implementations */
int
magic_op(const char *file_name) {
    if (!file_name) { return 1; }

    char cmd[MAX_CMD_LENGTH] = "";
    char *file_name_bk = NULL;

    file_name_bk = malloc(strlen(file_name)+1);
    if (!file_name_bk) { return -1; }

    strcpy(file_name_bk, file_name);

    // get mime type
    FILE *ptr = NULL;
    char *mime_type = NULL;
    mime_type = malloc(128);
    if (!mime_type) { return -1; }

    sprintf(cmd, "file --dereference --brief --mime-type \"%s\"", file_name);
    ptr = popen(cmd, "r");
    fgets(mime_type, 128, ptr);
    pclose(ptr);
    // fputs(mime_type, stdout);

    char *tmp = NULL;
    if ((tmp = strstr(mime_type, "\n"))) { *tmp = '\0'; }

    char *base_name = NULL;
    char *suffix    = NULL;
    base_name = basename(file_name_bk);
    suffix = strrchr(base_name, '.');

    cmd[0] = '\0';
    int isfind = 0;
    if (NULL != suffix) {
        for (int i=0; i < NUM_OPEN_MAP; i++) {
            if ( 0 == strcmp(open_map[i].key, suffix)) {
                isfind = 1;
                if (open_map[i].flag) {
                    sprintf(cmd, "(%s \"%s\" &);exit", open_map[i].value, file_name);
                } else {
                    sprintf(cmd, "%s \"%s\"", open_map[i].value, file_name);
                }
                puts(cmd);
                system(cmd);
                break;
            }
        }
    }

    if (!isfind) {
        for (int i=0; i < NUM_OPEN_MAP_ELSE; i++) {
            if ( 0 == strcmp(open_map_else[i].key, mime_type)) {
                isfind = 1;
                if (open_map_else[i].flag) {
                    sprintf(cmd, "(%s \"%s\" &);exit", open_map_else[i].value, file_name);
                } else {
                    sprintf(cmd, "%s \"%s\"", open_map_else[i].value, file_name);
                }
                puts(cmd); system(cmd);
                break;
            }
        }
    }

    FREE(mime_type);
    FREE(file_name_bk);
    return isfind ? EXIT_SUCCESS: EXIT_FAILURE;
}

int
magic_ex(const char *file_name) {
    if (!file_name) { return 1; }

    char cmd[MAX_CMD_LENGTH] = "";

    char *file_name_bk = NULL;
    file_name_bk = malloc(strlen(file_name)+1);
    if (!file_name_bk) {
        return -1;
    }
    strcpy(file_name_bk, file_name);

    // get base_name, suffix
    char *base_name = NULL;
    char *suffix    = NULL;
    base_name = basename(file_name_bk);
    suffix = strrchr(base_name, '.');

    cmd[0] = '\0';
    int isfind = 0;
    if (NULL != suffix) {
        for (int i=0; i < NUM_EXEC_MAP; i++) {
            if ( 0 == strcmp(exec_map[i].key, suffix)) {
                isfind = 1;
                sprintf(cmd, exec_map[i].value, file_name);
                puts(cmd); system(cmd);
                break;
            }
        }
    }

    if (!isfind) {
        for (int i=0; NUM_EXEC_MAP_ELSE; i++) {
            if ( 0 == strcmp(exec_map_else[i].key, "*")) {
                isfind = 1;
                sprintf(cmd, exec_map_else[i].value, file_name);
                puts(cmd); system(cmd);
                break;
            }
        }
    }
    
    FREE(file_name_bk);
    return isfind ? EXIT_SUCCESS: EXIT_FAILURE;
}

int
magic_cp(const char *file_name) {
    if (!file_name) { return 1; }

    char cmd[MAX_CMD_LENGTH] = "";
    char *file_name_bk = NULL;

    file_name_bk = malloc(strlen(file_name)+1);
    if (!file_name_bk) { return -1; }

    strcpy(file_name_bk, file_name);

    char *dir_name  = NULL;
    dir_name  = dirname(file_name_bk);

    cmd[0] = '\0';
    sprintf(cmd, "cp %s %s %s/", cp_opt, file_name, dir_name);
    printf("%s", cmd);
    char *new_base_name = NULL;
    size_t len;
    getline(&new_base_name, &len, stdin);
    strcat(cmd, new_base_name);

    // puts(cmd);
    system(cmd);

    FREE(file_name_bk);
    return 0;
}

int
magic_mv(const char *file_name) {
    if (!file_name) { return 1; }

    char cmd[MAX_CMD_LENGTH] = "";
    char *file_name_bk = NULL;

    file_name_bk = malloc(strlen(file_name)+1);
    if (!file_name_bk) { return -1; }

    strcpy(file_name_bk, file_name);

    char *dir_name  = NULL;
    dir_name  = dirname(file_name_bk);

    cmd[0] = '\0';
    sprintf(cmd, "mv %s %s %s/", mv_opt, file_name, dir_name);
    printf("%s", cmd);
    char *new_base_name = NULL;
    size_t len;
    getline(&new_base_name, &len, stdin);
    strcat(cmd, new_base_name);

    // puts(cmd);
    system(cmd);
    
    FREE(file_name_bk);
    return 0;
}

int
magic_rm(const char *file_name) {
    if (!file_name) {
        return 1;
    }

    char cmd[MAX_CMD_LENGTH] = "";
    char *file_name_bk = NULL;
    
    file_name_bk = malloc(strlen(file_name)+1);
    if (!file_name_bk) { return -1; }

    strcpy(file_name_bk, file_name);

    cmd[0] = '\0';
    sprintf(cmd, "rm %s \"%s\"", rm_opt, file_name);

    puts(cmd);
    system(cmd);

    FREE(file_name_bk);
    return 0;
}

void
help() {
    char * helpstr = "\
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
        -c     cp a file.\n\
    \n\
        -m     mv a file.\n\
    \n\
        -r     rm a file.\n\
    \n\
    CUSTOMIZATION\n\
        chopin is customized by creating a custom config.h and recompiling the source code. This keeps it fast, secure and simple.\n\
    \n\
    BUGS\n\
        Send all bug reports with a patch to zetatez@icloud.com. \n\
    \n";

    printf(helpstr);
    exit(EXIT_SUCCESS);
}

void
version() {
    printf("chopin-%s\n", VERSION);
    exit(EXIT_SUCCESS);
}

