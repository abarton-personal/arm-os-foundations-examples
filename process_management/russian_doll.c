#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MATRYOSHKA 8

int main(){

    pid_t child_pid, pid;
    int status;

    int dollnum = MATRYOSHKA;

    while (dollnum > 0){

        child_pid = fork();
        
        if(child_pid == 0){
            //child process
            pid = getpid();
            printf("I'm child process %d: MATRYOSHKA %d\n", pid, dollnum);
            
        }
        else if (child_pid > 0){
            //parent process
            pid = wait(&status);
            if(WIFEXITED(status)){
                printf("Parent discovers child exit with status: %d\n", WEXITSTATUS(status));
                return 0;
            }
        }
        else {
            perror("fork failed");
            exit(1);
        }

        dollnum--;        

    }

    return 0;


}
