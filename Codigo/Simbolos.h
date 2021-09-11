#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Simbolos {
    char* lexema;
    char* tipoDato;
    char* valor;
    char* longitud;
    char* token;
} structSimbolo;

int cantActual = 1;
int cantLimite = 40;

structSimbolo simbolos[40];

void agregarSimbolo(char* lexema, char* tipoDato, char* valor, int longitud, char* token);

void agregarSimbolo(char* lexema, char* tipoDato, char* valor, int longitud, char* token){
    simbolos[cantActual].lexema = (char*) malloc(31);
    strcpy(simbolos[cantActual].lexema, lexema);
    simbolos[cantActual].tipoDato = tipoDato;
    simbolos[cantActual].valor = (char*) malloc(31);
    strcpy(simbolos[cantActual].valor, valor); 
    simbolos[cantActual].longitud = (char*) malloc(31);
    itoa(longitud, simbolos[cantActual].longitud, 10);
    simbolos[cantActual].token = token;
    cantActual++;
}