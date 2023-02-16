#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

struct sigaction act;

void sighandler(int signum, siginfo_t *info, void *p) {
    printf("Received signal %d from process %lu\n", signum, (unsigned long)info->si_pid);
    printf("goodbye\n");
}

int main() {
    // instructions for interactive user
    printf("Try kill -2 %lu, or just press CTRL+C\n", (unsigned long)getpid());
    // zero-initialize the sigaction instance
    memset(&act, 0, sizeof(act));
    // set up the callback pointer
    act.sa_sigaction = sighandler;
    // set up the flags, so the signal handler receives relevant info
    act.sa_flags = SA_SIGINFO;
    // install the handler
    sigaction(SIGINT, &act, NULL);
    // wait for something to happen
    sleep(60);
    return 0;
}