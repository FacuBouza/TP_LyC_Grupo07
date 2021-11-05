#include <stdio.h>
#include <malloc.h> 
#include "Arbol.h"

struct elemento {
	structNodo* dato;
	struct elemento *next;
};

struct pila {
	struct elemento *frente;
	int tamano;
};

int crear(struct pila *);
int apilar(struct pila *p, structNodo* nodoPtr);
structNodo* desapilar(struct pila *p);
int estaVacia(struct pila);
structNodo* verTopePila(struct pila *p);