#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void main()
{
    int idtube;
    mknod("mypipe",0600, 0);// pipe creation with permission user=rwx group=rwx others=rwx = 110 000 000 = 0600 (in octal)
    idtube = open("mypipe", O_RDWR);// or O_WRONLY for write, or ORDWR for read & write

}