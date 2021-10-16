#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char valor[150];
    struct nodo* hijoDer;
    struct nodo* hijoIzq;
}structNodo;

structNodo* crearHoja(char elemento[]);
structNodo* crearNodo(char raiz[], structNodo* nodoIzq, structNodo* nodoDer);