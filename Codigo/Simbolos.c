#include "Simbolos.h"

int cantActual = 1;
int cantLimite = 1000;

int posLastID = 0;
int posFirstID = 0;

void agregarSimbolo(char* nombre, char* tipoDato, char* valor, int longitud, char* token){
    simbolos[cantActual].nombre = (char*) malloc(31);
    strcpy(simbolos[cantActual].nombre, nombre);
    simbolos[cantActual].tipoDato = (char*) malloc(31);
    strcpy(simbolos[cantActual].tipoDato, tipoDato);
    simbolos[cantActual].valor = (char*) malloc(31);
    strcpy(simbolos[cantActual].valor, valor); 
    simbolos[cantActual].longitud = (char*) malloc(31);
    if(longitud != 0)
        itoa(longitud, simbolos[cantActual].longitud, 10);
    else
        simbolos[cantActual].longitud = "";
    simbolos[cantActual].token = (char*) malloc(31);
    strcpy(simbolos[cantActual].token, token);
    cantActual++;
}

int getCantActual(){
    return cantActual;
}

void agregarVariable(char* nombreID){
    strcpy(vecVariables[posLastID].nombre, nombreID);
    posLastID++;
}

void getNextNombreID(char* nombreID){
    strcpy(nombreID, vecVariables[posFirstID].nombre);
    posFirstID++;
}