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

int cantActual = 1;
int cantLimite = 1000;

structSimbolo simbolos[1000];

void agregarSimbolo(char* nombre, char* tipoDato, char* valor, int longitud, char* token);

void agregarSimbolo(char* nombre, char* tipoDato, char* valor, int longitud, char* token){
    simbolos[cantActual].nombre = (char*) malloc(31);
    strcpy(simbolos[cantActual].nombre, nombre);
    simbolos[cantActual].tipoDato = (char*) malloc(31);
    strcpy(simbolos[cantActual].tipoDato, tipoDato);
    simbolos[cantActual].valor = (char*) malloc(31);
    strcpy(simbolos[cantActual].valor, valor); 
    simbolos[cantActual].longitud = (char*) malloc(31);
    itoa(longitud, simbolos[cantActual].longitud, 10);
    simbolos[cantActual].token = (char*) malloc(31);
    strcpy(simbolos[cantActual].token, token);
    cantActual++;
}