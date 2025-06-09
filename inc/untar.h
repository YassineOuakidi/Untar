#ifndef UNTAR_H
#define UNTAR_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

#define NAME_OFFSET 0
#define MODE_OFFSET 100
#define UID_OFFSET 108
#define GID_OFFSET 116
#define SIZE_OFFSET 124
#define MTIME_OFFSET 136
#define CHKSUM_OFFSET 148
#define TYPEFLAG_OFFSET 156
#define LINKNAME_OFFSET 157
#define MAGIC_OFFSET 257
#define VERSION_OFFSET 263
#define UNAME_OFFSET 265
#define GNAME_OFFSET 297
#define DEVMAJOR_OFFSET 329
#define DEVMINOR_OFFSET 337
#define PREFIX_OFFSET 345

extern int not_done;

struct HEADER
{                              /* byte offset */
  	char *name;               /*   0 */
  	char *mode;                 /* 100 */
  	char *uid;                  /* 108 */
  	char *gid;                  /* 116 */
  	char *size;                /* 124 */
  	char *mtime;               /* 136 */
  	char *chksum;               /* 148 */
  	char typeflag;                /* 156 */
  	char *linkname;           /* 157 */
  	char *magic;                /* 257 */
  	char *version;              /* 263 */
  	char *uname;               /* 265 */
  	char *gname;               /* 297 */
  	char *devmajor;             /* 329 */
  	char *devminor;             /* 337 */
	char *prefix;             /* 345 */
 	                        /* 500 */
};

char *get_header(int fd);
char *ft_strdup(const char *src , size_t len);
char *get_dirname(char *name);
char *get_filename(char *name);

void process(int fd);
void make_header_struct(struct HEADER *header_struct , char *header);

int get_nearest_mult(int n);
int get_mode_decimal(char *mode);
int get_decimal(int octal);
#endif
