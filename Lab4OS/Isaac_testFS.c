#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Isaac_libFS.h"

#define INTRO_FILE "Introduction.txt"
#define BUF_SIZE    1024

static const char* introText =
	"Hello, I am Isaac, I am a computer science student finishing up their 4th year\n\n"
	"This is file will demonstrate the file system functions. Should be pretty cool (probably not that cool but cool enough)";

void printMenu() {
	puts("\n=== libFS Test Menu ===");
	puts("1) Create Introduction file");
	puts("2) Open Introduction file");
	puts("3) Write Introduction text");
	puts("4) Read and display file contents");
	puts("5) Close file");
	puts("6) Delete Introduction file");
	puts("0) Exit");
	printf("Select an option: ");
}

int main() {
	int choice, fd = -1;
	char buf[BUF_SIZE];
	ssize_t n;

    do {
        //prints the menu
        printMenu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input\n");
            exit(EXIT_FAILURE);
        }
        getchar();

        switch (choice) {
        //creates file with introduction
        case 1:
            fd = fileCreate(INTRO_FILE);
            break;
        //opens the file
        case 2:
            fd = fileOpen(INTRO_FILE);
            break;
        //writes into the file
        case 3:
            if (fd < 0) {
                puts("File not open. Please open first.");
            }
            else {
                fileWrite(fd, introText, strlen(introText));
            }
            break;
        //reads the file
        case 4:
            if (fd < 0) {
                puts("File not open. Please open first.");
            }
            else {
                fileRead(fd, buf, BUF_SIZE - 1);
                buf[BUF_SIZE - 1] = '\0';
                printf("\n--- File Contents ---\n%s\n", buf);
            }
            break;
        //closes the file
        case 5:
            if (fd >= 0) {
                fileClose(fd);
                fd = -1;
            }
            break;
        //deletes the file
        case 6:
            fileDelete(INTRO_FILE);
            break;
        //exits
        case 0:
            break;
        default:
            puts("Unknown option");
        }
    } while (choice != 0);
    //optional exit

    return 0;
}