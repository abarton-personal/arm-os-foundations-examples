#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

    pid_t child_pid, pid;
    int status;

    child_pid = fork();

    if(child_pid == 0){
        //child process
        pid = getpid();
        printf("I'm child process %d\n", pid);
        printf("...sleep for 10 seconds, then exit with status 42\n");
        sleep(10);
        exit(42);
    }
    else if (child_pid > 0){
        //parent process
        pid = wait(&status);
        if(WIFEXITED(status)){
            printf("Parent discovers child exit with status: %d\n", WEXITSTATUS(status));
        }
    }
    else {
        perror("fork failed");
        exit(1);
    }
    return 0;


}
