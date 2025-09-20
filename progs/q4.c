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
        //exec("/bin/ls");
	execl("/bin/ls", "ls", (char *)NULL);
	
        //execle("/bin/ls","ls", (char *)NULL);
	//execlp("/bin/ls", (char *)NULL);
	//execv("/bin/ls", (char *)NULL);
	//execvp("/bin/ls", (char *)NULL);
	//execvpe("/bin/ls", (char *)NULL);
    } else {
	int rc_wait = wait(NULL);
    }
    return 0;
}

