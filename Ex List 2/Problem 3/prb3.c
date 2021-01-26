#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

int n = 0;

void h(int sig){
    n++;
    printf("%d ", n);
    signal(sig, h);
}

void main(){
    int pid;
    if((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        signal(15, h);
        while (n <= 100)
        {
            kill(getppid(), 15);
            pause();
        }
    }
    else{
        signal(15, h);
        while (n < 99)
        {
            pause();
            kill(pid, 15);
        }
        
    }
}