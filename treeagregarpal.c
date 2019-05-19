
#include "anagramas_bintree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXPAL 32

/*  Agrega un nodo al árbol. Devuelve el puntero a la raíz (eventualmente modificado)
    El argumento raiz es la raiz del árbol existente, o NULL si aún no hay árbol
    El argumento pal es la palabra a insertar (debe calcularse la clave)
    Recordar crear memoria para insertar tanto el nodo como la palabra.
*/

void generarclave(char *clave, char *pal, int maxpal);

TN* treeNode( char* clave  ) {

    TN* node = malloc(sizeof(TN));
    node->cantpal = 0;
    node->clave = strdup( clave  );
    node->palabras = NULL;
    node->izq = NULL;
    node->der = NULL;

    return node;
}

void agregarPalabra( TN* node, char* pal  ) {
    node->palabras = list_agregar_pal( node->palabras, pal  );
    (node->cantpal)++;
}


void tree_agregar_pal_recursivo( TN* raiz, char* pal, char* clave ) {
    if(strcmp(clave, (raiz->clave)) == 0) {
        agregarPalabra(raiz, pal);
        return;
    } else if( strcmp(clave, (raiz->clave)) < 0 ) {
        if( raiz->izq == NULL ) {
            TN* toAdd = treeNode(clave);
            agregarPalabra( toAdd, pal );
            raiz->izq = toAdd;
            return;
        } else {
            tree_agregar_pal_recursivo(raiz->izq, pal, clave);
        }
    } else if( strcmp(clave, (raiz->clave)) > 0 ) {
        if( raiz->der == NULL ) {
            TN* toAdd = treeNode(clave);
            agregarPalabra( toAdd, pal );
            raiz->der = toAdd;
            return;
        } else {
            tree_agregar_pal_recursivo(raiz->der, pal, clave);
        }
    }
    return;
}

TN * tree_agregar_pal(TN *raiz, char *pal) {
    char* clave = malloc(MAXPAL);
    generarclave(clave, pal, MAXPAL);

    if( raiz == NULL ) {
        TN* toAdd = treeNode(clave);
        agregarPalabra( toAdd, pal );
        free(clave);
        return toAdd;
    } else {
        tree_agregar_pal_recursivo(raiz, pal, clave);
        free(clave);
    }
    return raiz;
}
