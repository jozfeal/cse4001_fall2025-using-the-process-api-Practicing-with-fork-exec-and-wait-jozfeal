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
        // first print var to check if it has changed from initialization
	printf("Child value of x: %d\n", x);
	// change value and check again
	x = 150;
	printf("Child value of x after change: %d\n", x);
    } else {
	// same check as child with different value
        printf("Parent value of x: %d\n", x);
	x = 50;
	printf("Parent value of x after change: %d\n", x);
    }
    return 0;
}

