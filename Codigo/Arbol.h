#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char valor[150];
    struct nodo* hijoDer;
    struct nodo* hijoIzq;
}structNodo;

structNodo* crearHoja(const char* elemento);
structNodo* crearNodo(const char* raiz, structNodo* nodoIzq, structNodo* nodoDer);
structNodo* crearNodo2(structNodo* nodoRaiz, structNodo* nodoIzq, structNodo* nodoDer);

void preorden(structNodo *nodo);
void inorden(structNodo *nodo);
void postorden(structNodo *nodo);

void liberarMemoria(structNodo* );
void llenarGragh(structNodo* , FILE*, int );
void escribirGragh(structNodo*);
int esHoja(structNodo *hoja);
void generarIntermedia(structNodo* padre);
void escribirIntermedia(FILE* file, structNodo* nodo);