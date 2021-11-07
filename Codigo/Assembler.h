#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pila.h"
#include "Simbolos.h"

int generarAssembler();
int copiarVariablesAssembler(FILE* pf);
int copiarBodyAssembler(FILE* pfAssem);
int generarBodyAssembler(structNodo* nodo);
int recorrerArbolAssembler(FILE* pf, structNodo* nodo);
void realizarOperacion(FILE* fp,structNodo* nodo);
int esOperacionAritmetica(char* operador);
int esAsignacion(char* operador);
char* getOperacion(char* operador);
int getNumAux();
int esComparacion(char* valor);
char* getComparacion(char* comparador);
char* getEtiqueta();
int getNumEtiqueta();
char* getDisplay(structNodo* nodo);
int esOperador(structNodo* nodo);