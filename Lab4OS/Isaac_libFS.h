#ifndef ISAAC_LIBFS_H
#define ISAAC_LIBFS_H

#include <stddef.h>
#include <sys/types.h>

int fileCreate(const char* filename);

int fileOpen(const char* filename);

ssize_t fileRead(int fd, void* buf, size_t count);

ssize_t fileWrite(int fd, const void* buf, size_t count);

int fileClose(int fd);

int fileDelete(const char *filename);

#endif