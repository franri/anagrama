
#include "anagramas_bintree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXPAL 32
/*  Busca la palabra en el árbol, retorna puntero si la encuentra, NULL si no lo hace
    El argumento raiz es la raiz del árbol existente, o NULL si aún no hay árbol
    El argumento pal es la palabra a buscar (debe calcularse la clave)
*/


void generarclave(char *clave, char *pal, int maxpal);

int palabraEstaEnLista( LN* nodo, char* pal  ) {
    if( strcmp( nodo->pal, pal  ) == 0 ) {
        return 1;
    } else {
        while( nodo->sig != NULL  ) {
            nodo = nodo->sig;
            if( strcmp(nodo->pal, pal) == 0 ) {
                return 1;
            }
        }
        return 0;
    }
}


TN* tree_buscar_pal_recursivo( TN* raiz, char* pal, char* clave  ) {

    if( raiz == NULL ) {
        return NULL;
    } else {
        if(strcmp(clave, (raiz->clave)) == 0) {
            if(palabraEstaEnLista(raiz->palabras, pal)) {
                return raiz;
            } else {
                return NULL;
            }
        } else if( strcmp(clave, (raiz->clave)) < 0 ) {
            return tree_buscar_pal_recursivo( raiz->izq, pal, clave);
        } else if( strcmp(clave, (raiz->clave)) > 0 ) {
            return tree_buscar_pal_recursivo(raiz->der, pal, clave);
        }
    }
    return NULL;
}

TN * tree_buscar_pal(TN *raiz, char *pal) {
    char* clave = malloc(MAXPAL);
    generarclave(clave, pal, MAXPAL);
    raiz = tree_buscar_pal_recursivo(raiz, pal, clave);
    free(clave);
    return raiz;
}
