
#include "anagramas_bintree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXPAL 32

LN* listNode( char* palabra);

LN * list_agregar_pal(LN *lista, char *pal);
char* fgetword_normalizada (FILE *fp, char *word, int maxword);

int main( int argc, char* argv[]  ) {

    if(argc != 2){
        printf("Para usarlo correctamente, escriba ./anagrama <<palabra>>\nGracias.\n");
        exit(-1);
    }

    FILE* dict = fopen("/usr/share/dict/spanish", "r");

    if(dict == NULL) {
        return 1;
    }

    TN* arbol = NULL;

    char* word = malloc(MAXPAL);
//  unsigned long counter = 1;
    while( fgetword_normalizada(dict, word, MAXPAL) != NULL ) {
        arbol = tree_agregar_pal(arbol, word);
//    counter++;
//    if(counter%1000==0  ){
//    printf("%lu: %s\n", counter, word);
//    }
    }

    free(word);

    char* aBuscar = argv[1];

    TN* nodoConCosas = tree_buscar_pal(arbol, aBuscar);

    if(nodoConCosas == NULL ) {
        printf("No existe la palabra en el diccionario\n");
    } else {
        LN* choco = nodoConCosas->palabras;
        if(choco==NULL) {
            printf("No hay palabras en el nodo (imposible que pase)\n");
        } else {
            printf("Hay %d anagramas para %s:\n", nodoConCosas->cantpal, aBuscar);
            while( choco!=NULL  ) {
                printf("%s\n", choco->pal);
                choco=choco->sig;
            }
        }
    }

    return 0;

}
