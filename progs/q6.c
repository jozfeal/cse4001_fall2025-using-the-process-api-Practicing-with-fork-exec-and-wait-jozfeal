#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        fprintf(stderr, "Child running first\n");
    } else {
	// store the return value of waitpid
	// this time we are specifying the process to wait for
	int rc_wait = waitpid(rc, NULL, 0);
	fprintf(stderr, "Parent running after wait\n");
	// print result of wait to find out
	fprintf(stderr, "%d\n", rc_wait);
    }
    return 0;
}

