// Terminal.h
#ifndef TERMINAL_H
#define TERMINAL_H

#include <sys/types.h>
#include <stddef.h>

int    TFS_create(const char* fname);
int    TFS_open(const char* fname);
ssize_t TFS_read(int fd, void* buf, size_t cnt);
ssize_t TFS_write(int fd, const void* buf, size_t cnt);
int    TFS_close(int fd);
int    TFS_delete(const char* fname);

#endif