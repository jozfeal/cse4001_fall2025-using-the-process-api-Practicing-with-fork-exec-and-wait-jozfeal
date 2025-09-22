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
	// closing the standard output before printing to see result
	close(STDOUT_FILENO);
        fprintf(stdout, "Child printing\n");
    } else {
	// waiting on child for result to be reflected in parent print too
	int rc = wait(NULL);
        fprintf(stdout, "Parent printing\n");
    }
    return 0;
}
