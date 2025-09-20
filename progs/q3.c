#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child print
	printf("hello\n");
    } else {
	// parent sleeps for a moment to let child print first
	sleep(1.5);
        printf("goodbye\n");
    }
    return 0;
}

