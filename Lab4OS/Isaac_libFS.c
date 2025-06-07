#include "Isaac_libFS.h"
#include "Terminal.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

int fileCreate(const char* filename) {
    int h = TFS_create(filename);
    if (h < 0)
        fprintf(stderr, "fileCreate(%s) failed: %s\n", filename, strerror(errno));
    return h;
}

int fileOpen(const char* filename) {
    int h = TFS_open(filename);
    if (h < 0)
        fprintf(stderr, "fileOpen(%s) failed: %s\n", filename, strerror(errno));
    return h;
}

ssize_t fileRead(int fd, void* buf, size_t cnt) {
    ssize_t n = TFS_read(fd, buf, cnt);
    if (n < 0)
        fprintf(stderr, "fileRead(fd=%d) failed: %s\n", fd, strerror(errno));
    return n;
}

ssize_t fileWrite(int fd, const void* buf, size_t cnt) {
    ssize_t n = TFS_write(fd, buf, cnt);
    if (n < 0)
        fprintf(stderr, "fileWrite(fd=%d) failed: %s\n", fd, strerror(errno));
    return n;
}

int fileClose(int fd) {
    int rc = TFS_close(fd);
    if (rc < 0)
        fprintf(stderr, "fileClose(fd=%d) failed: %s\n", fd, strerror(errno));
    return rc;
}

int fileDelete(const char* filename) {
    int rc = TFS_delete(filename);
    if (rc < 0)
        fprintf(stderr, "fileDelete(%s) failed: %s\n", filename, strerror(errno));
    return rc;
}
