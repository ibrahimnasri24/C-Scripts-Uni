#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void play(int i)
{
    printf("Player %d plays\n",i);
    sleep(3);
    printf("End player %d\n",i);
    exit(1);
}
void main(int argc, char **argv)
{
    int i = 0;
    printf("Parent %d\n",getpid());
    while(fork() || i > 4)
    {
        i++;
    }
    printf("%d\n",getpid());
    exit(1);
}