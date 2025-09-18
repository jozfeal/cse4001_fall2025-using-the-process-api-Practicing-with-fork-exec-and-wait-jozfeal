#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    // variable to check for change
    int x = 100;

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child value of x: %d\n", x);
	x = 150;
	printf("Child value of x after change: %d\n", x);
    } else {
        printf("Parent value of x: %d\n", x);
	x = 50;
	printf("Parent value of x after change: %d\n", x);
    }
    return 0;
}

