#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char valor[150];
    struct nodo* hijoDer;
    struct nodo* hijoIzq;
    char* tipo;
}structNodo;

structNodo* crearHoja(const char* elementom, char* tipo);
structNodo* crearNodo(const char* raiz, char* tipo, structNodo* nodoIzq, structNodo* nodoDer);
structNodo* crearNodo2(structNodo* nodoRaiz, char* tipo,structNodo* nodoIzq, structNodo* nodoDer);

void preorden(structNodo *nodo);
void inorden(structNodo *nodo);
void postorden(structNodo *nodo);

void liberarMemoria(structNodo* );
void llenarGragh(structNodo* , FILE*, int );
void escribirGragh(structNodo*);
int esHoja(structNodo *hoja);
void generarIntermedia(structNodo* padre);
void escribirIntermedia(FILE* file, structNodo* nodo);
void procesarDeclaracion();
void validOperatorType(structNodo* nodo);