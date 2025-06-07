#include "Isaac_libFS.h"
#include <stdio.h> 
#include <string.h>  
#include <errno.h> 
#include <fcntl.h>
#include <unistd.h>

//creates file
int fileCreate(const char* filename) {
    int fd = open(filename, O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        fprintf(stderr, "fileCreate(%s) failed: %s\n",
            filename, strerror(errno));
    }
    return fd;
}

//opens file
int fileOpen(const char* filename) {
    int fd = open(filename, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "fileOpen(%s) failed: %s\n",
            filename, strerror(errno));
    }
    return fd;
}

//reads file
ssize_t fileRead(int fd, void* buf, size_t count) {
    ssize_t n = read(fd, buf, count);
    if (n < 0) {
        fprintf(stderr, "fileRead(fd=%d) failed: %s\n",
            fd, strerror(errno));
    }
    return n;
}

//writes in the file
ssize_t fileWrite(int fd, const void* buf, size_t count) {
    ssize_t n = write(fd, buf, count);
    if (n < 0) {
        fprintf(stderr, "fileWrite(fd=%d) failed: %s\n",
            fd, strerror(errno));
    }
    return n;
}

//closes the file
int fileClose(int fd) {
    int rc = close(fd);
    if (rc < 0) {
        fprintf(stderr, "fileClose(fd=%d) failed: %s\n",
            fd, strerror(errno));
    }
    return rc;
}

//deletes file
int fileDelete(const char* filename) {
    int rc = unlink(filename);
    if (rc < 0) {
        fprintf(stderr, "fileDelete(%s) failed: %s\n",
            filename, strerror(errno));
    }
    return rc;
}
