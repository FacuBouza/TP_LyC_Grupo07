#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Simbolos {
    char* nombre;
    char* tipoDato;
    char* valor;
    char* longitud;
    char* token;
} structSimbolo;

extern int cantActual;
extern int cantLimite;

structSimbolo simbolos[2000];

void agregarSimbolo(char* nombre, char* tipoDato, char* valor, int longitud, char* token);
int getCantActual();