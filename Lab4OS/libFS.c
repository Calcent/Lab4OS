#include "libFS.h"
#include "Terminal.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

//creates the file
int fileCreate(const char* filename) {
	int handle = TFS_create(filename);
	if (handle < 0) {
		fprintf(stderr, "fileCreate(%s) failed: %s\n", filename, TFS_strerror(errno));
	}
	return handle;
}

//opens file
int fileOpen(const char* filename) {
	int handle = TFS_open(filename);
	if (handle < 0) {
		fprint(stderr, "fileOpen(%s) failed: %s\n", filename, TFS_strerror(errno));
	}
	return handle;
}

//reads file
ssize_t fileRead(int fd, void* buf, size_t count) {
	ssize_t n = TFS_read(fd, buf, count);
	if (n < 0) {
		fprintf(stderr, "fileRead(fd=%d) failed: %s\n", fd, TFS_strerror(errno));
	}
	return n;
}

