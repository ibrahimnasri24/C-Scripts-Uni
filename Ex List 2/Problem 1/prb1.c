#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig(int);
void main()
{
    int i;
    for (i = 1; i <= 30; i++)
        signal(i, sig);
    for (i = 1; i <= 30; i++)
        kill(getpid(), i);
    printf("\n Fin du main.");
}
void sig(int s)
{
    printf("\n Signal %d recu.", s);
    printf("\n Je le rearme.");
    signal(s, sig);
}