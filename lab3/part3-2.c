#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc,char **argv)
{
    struct stat sb;
    long int inode;
    if(stat(argv[1], &sb) == -1)
    {
        perror("stat");
        exit(EXIT_SUCCESS);
    }
    printf("Inode : %ld\n", (long) sb.st_ino);
    printf("date de derniere modif : %s", ctime(&sb.st_mtime));
    inode = sb.st_ino;
    exit(EXIT_SUCCESS);
}