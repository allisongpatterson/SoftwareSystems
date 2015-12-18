/* Example code for Software Systems at Olin College.

Head-First C Chapter 03 Coding Exercise
Allison Patterson

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char buf[20];
    size_t nbytes;
    int fd;
    int ch;
    int n;
    int append;

    append = 0;
    nbytes = sizeof(buf);

    while ((ch = getopt(argc, argv, "ai")) != -1) {
        switch((char)ch) {
            case 'a':
                append = 1;
                break;
            default:
                fprintf(stderr, "unrecognized option");
        }
    }

    argc -= optind;
    argv += optind;

    if (append) {
        fd = open(argv[0], O_WRONLY | O_CREAT | O_APPEND);
    } else {
        fd = open(argv[0], O_WRONLY | O_CREAT | O_TRUNC);
    }

    while((n = read(STDIN_FILENO, buf, nbytes)) > 0) {
        write(STDOUT_FILENO, buf, n);
        write(fd, buf, n);
    }

    close(fd);
    return 0;
}