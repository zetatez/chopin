/* See LICENSE file for copyright and license details. */
// chopin.h

/* Author: lorenzo */
/* E-mail: lorenzo<zetatez@icloud.com> */

int magic_open(const char *filename);
int magic_exec(const char *filename);
int magic_cp(const char *filename);
int magic_mv(const char *filename);
int magic_rm(const char *filename);
void help();
void version();

