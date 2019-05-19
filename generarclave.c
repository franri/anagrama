#include <string.h>

void ordenar( char* clave, int largo  ) {

    int cantidadDePasadas = largo - 1 ;


    int hayQueSeguir = 1;

    while( cantidadDePasadas-- > 0 && hayQueSeguir  ) {

        hayQueSeguir = 0;

        char* puntero = clave;

        while( *(puntero + 1) != '\0' ) {
            if( *puntero > *(puntero + 1) ) {
                char temp;
                temp = *(puntero + 1 );
                *(puntero + 1) = *puntero;
                *puntero = temp;
                hayQueSeguir = 1;
            }
            puntero++;
        }

    }

}

void generarclave(char *clave, char *pal, int maxpal) {

    strcpy(clave, pal);
    int len =  strlen(pal);
    ordenar( clave, len );

}

