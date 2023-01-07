#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ret_words(char words) { 
    char str[50];
    int cont = 0;
    char tempo = malloc(sizeoftempo);
    if(tempo == NULL){
        return -1;
    }
    do {
        tempo = realloc(tempo,(cont + 1) * sizeof *tempo);
        if(tempo == NULL){
            return -1;
        } 
        tempo[cont] = malloc(strlen(str) + 1);
        cont++;
    } while (scanf("%49s",tempo[cont - 1]) == 1
      && getchar() != '\n');

    *words = tempo;
    return cont;
}
int main()
{ 
    char **words;

    int ret;
    puts("entre quelque chose");
    putchar('>');
    ret = ret_words(&words);
    for(int i = 0; i < ret; i++)
        printf("Word %d: %s\n",i + 1, words[i]);

    printf("Word cont: %d", ret);
}