#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

void h(int sig){
    if(sig == 16) printf("PING\n");
    if(sig == 17) printf("PONG\n");
    sleep(1);
    signal(16, h);
    signal(17, h);
}

void main(){
    int pid;
    if((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        signal(17, h);
        while (1)
        {
            kill(getppid(), 16);
            pause();
        }
    }
    else{
        signal(16, h);
        while (1)
        {
            kill(pid, 17);
            pause();
        }
        
    }
}