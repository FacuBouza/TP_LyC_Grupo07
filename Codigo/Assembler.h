#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pila.h"
#include "Simbolos.h"

int generarAssembler();
int copiarVariablesAssembler(FILE* pf);
int generarBodyAssembler(FILE* pf, structNodo* nodo);
void realizarOperacion(FILE* fp,structNodo* nodo);
int esOperacionAritmetica(char* operador);
int esAsignacion(char* operador);
char* getOperacion(char* operador);
int getNumAux();