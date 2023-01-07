#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int re_mots(char words)
{ 
    
    int compteur = 0;
    char temporaire=malloc(sizeoftemporaire);
    char str[50];

    while(temporaire == NULL)
    {
        return -2;
    }

    do
    {
        temporaire = realloc(temporaire,(compteur + 1)*sizeof *temporaire);
        if(temporaire == NULL)
        {
            return -2;
        } 
        temporaire[compteur] = malloc(strlen(str) + 1);
        compteur++;
    }while(scanf("%49s",temporaire[compteur - 1]) == 1 /*scan str et remplit temporaire*/ && getchar() != '\n'); //avec les espcaces
    *words = temporaire;
    return compteur; //retourne le compte de mot
}
int main()
{ 
    char **words; //pointer de pointer pour se deplacer sur la string
    int ret;

    puts("Entre une phrase");
    putchar('>');

    ret = re_mots(&words); //si reussi retourne le compte de mot,et retourne -2 si erreur

    for(int i = 0; i < ret; i++) //print chaque mots
        printf("Word %d: %s\n",i + 1, words[i]);

    printf("nombre de mot: %d", ret); //print le nombre de mot avec le compteur
}