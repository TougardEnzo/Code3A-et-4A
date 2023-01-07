#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

//problème si l'on crée un fichier dont le nom existe déja

int main(int argc, char **argv)
{
    struct stat sb;
    char CharactMDP[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789&é'(-è_çà)=";
	int desc;

	FILE *docu;
	docu = fopen(argv[1],"w");
	
	if(argv[1] == NULL)
    {
		printf("argument manquant\n");
	}
	else
    {
		if((desc=open(argv[1],O_RDONLY|O_CREAT))<0)
		{
			perror("erreur à l'ouverture");
		}
		else
        {
			chmod(argv[1],S_IRUSR);
			close(desc);
		}
	}

	long int UID = sb.st_uid;
	char *Date;
    char Pwd[11];
    char *user = getlogin();
	Date = ctime(&sb.st_ctime);
	srand(time(NULL));

	for(int i = 0;i <10;i++)
    {
		Pwd[i] = CharactMDP[rand()%70];
	}
	fprintf(docu,"<New_User>\n\t<Username>%s</Username>\n\t<date>%s</date>\n\t<uid>%ld</uid>\n\t<MDP>%s</MDP>\n</New_User>",user,Date,UID,Pwd);
    fclose(docu);
	chmod(argv[1], 400);
}