#include "Arbol.h"

structNodo* crearHoja(char elemento[]){
    structNodo* nodo = (structNodo*) malloc(sizeof(struct nodo));
    strcpy(nodo->valor, elemento);
    nodo->hijoIzq = NULL;
    nodo->hijoDer = NULL;
    return nodo;
}

structNodo* crearNodo(char raiz[], structNodo* nodoIzq, structNodo* nodoDer){
    structNodo* nodo = crearHoja(raiz);
    nodo->hijoIzq = nodoIzq;
    nodo->hijoDer = nodoDer;
    return nodo;
}