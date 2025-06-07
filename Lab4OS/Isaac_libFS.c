#include "Isaac_libFS.h"
#include <stdio.h>      // fprintf()
#include <string.h>     // strerror()
#include <errno.h>      // errno
#include <fcntl.h>      // open() flags
#include <unistd.h>     // read(), write(), close(), unlink()

int fileCreate(const char* filename) {
    int fd = open(filename, O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        fprintf(stderr, "fileCreate(%s) failed: %s\n",
            filename, strerror(errno));
    }
    return fd;
}

int fileOpen(const char* filename) {
    int fd = open(filename, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "fileOpen(%s) failed: %s\n",
            filename, strerror(errno));
    }
    return fd;
}

ssize_t fileRead(int fd, void* buf, size_t count) {
    ssize_t n = read(fd, buf, count);
    if (n < 0) {
        fprintf(stderr, "fileRead(fd=%d) failed: %s\n",
            fd, strerror(errno));
    }
    return n;
}

ssize_t fileWrite(int fd, const void* buf, size_t count) {
    ssize_t n = write(fd, buf, count);
    if (n < 0) {
        fprintf(stderr, "fileWrite(fd=%d) failed: %s\n",
            fd, strerror(errno));
    }
    return n;
}

int fileClose(int fd) {
    int rc = close(fd);
    if (rc < 0) {
        fprintf(stderr, "fileClose(fd=%d) failed: %s\n",
            fd, strerror(errno));
    }
    return rc;
}

int fileDelete(const char* filename) {
    int rc = unlink(filename);
    if (rc < 0) {
        fprintf(stderr, "fileDelete(%s) failed: %s\n",
            filename, strerror(errno));
    }
    return rc;
}
