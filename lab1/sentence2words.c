#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void afficher(char *phrase)
{
	int i=0;
	int j=0;
	int n=0;

	char mots[6][10];

	do{//chargement d ela phrase
		if(phrase[i]!=' ')
		{
			mots[j][n++]=phrase[i];
		}
		else
		{
			mots[j++][n]='\0';
			n=0;

		}
	}while(phrase[i++]!='\0');//permets de savoir quand se termine la phrase
	i=0;
	while(i<6)
	{
		printf("%s\n",mots[i]);
		i++;
	}

	
}
int main(void)
{


	char *phrase=malloc(sizeof(char)); //allocation mémoire
	fgets(phrase);//chargement de la phrase
	afficher(phrase);//appelle la fct afficher pour faire apparaitre la phrase charger précédement
	free(phrase);//libère la mémoire
	return 0;
}