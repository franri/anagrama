#include "anagramas_bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXPAL 32
/*  Agrega una palabra a una lista. Devuelve el puntero a la lista (eventualmente modificado)
    El argumento lista es el cabezal a la lista existente, o NULL si aún no hay lista
    El argumento pal es la palabra a insertar.
    Recordar crear memoria para insertar tanto el nodo como la palabra.
*/

void generarclave(char *clave, char *pal, int maxpal);

LN* listNode( char* palabra  ) {

    LN* node = malloc(sizeof(LN));
    node->pal = strdup( palabra );
    node->sig = NULL;

    return node;
}


void list_agregar_pal_recursivo(LN* lista, char* pal ) {
    if( strcmp(lista->pal, pal) == 0  ) {
        return; // si ya existe la palabra, no hace nada
    } else if( lista->sig == NULL  ) {
        lista->sig = listNode(pal);
        return;
    } else {
        list_agregar_pal_recursivo(lista->sig, pal);
    }


}

LN * list_agregar_pal(LN *lista, char *pal) {
    if(lista == NULL) {
        return listNode( pal );
    } else {
        list_agregar_pal_recursivo(lista, pal);
        return lista;
    }
}
