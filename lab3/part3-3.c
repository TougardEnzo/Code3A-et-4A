#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    if(access(argv[1],F_OK) == 0)
    {
        if(access(argv[1],W_OK) == 0)
        {
            printf("droit d'écrire\n");
        }
        if(access(argv[1],X_OK) == 0)
        {
            printf("droit d'éxécution\n");
        }
        if(access(argv[1],R_OK) == 0)
        {
            printf("droit de lecture\n");
        }
    }
    else
    {
        printf("Le Fichier n'existe pas\n");
    }
}