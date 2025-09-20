#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    // close standard output before opening file
    close(STDOUT_FILENO);
    // creating new file for fork
    open("q2.out", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
	// child print statement going into q2.out
        fprintf(stdout, "Child printing\n");
    } else {
	// parent print statement going into q2.out
        fprintf(stdout, "Parent printing\n");
    }
    return 0;
}

