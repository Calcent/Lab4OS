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