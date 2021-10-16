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

structSimbolo simbolos[2000];

typedef struct Variables {
    char nombre[50];
} structVariables;

extern int cantActual;
extern int cantLimite;

structVariables vecVariables[2000];
extern int posLastID;
extern int posFirstID;

void agregarSimbolo(char* nombre, char* tipoDato, char* valor, int longitud, char* token);
void agregarVariable(char nombreID[]);
void agregarTipoVariable(char tipoID[]);
void getNextNombreID(char* nombreID);

void modificarTipoID(char* nombre, char* tipoDato, char* valor, int longitud, char* token);
int getCantActual();