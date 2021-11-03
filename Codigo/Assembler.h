#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pila.h"
#include "Simbolos.h"

int generarAssembler();
int copiarVariablesAssembler(FILE* pf);
int generarBodyAssembler(FILE* pf, structNodo* nodo);