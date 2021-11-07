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

int getCantSimbolos(){
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

void fueDeclarada(const char* nombre){
    int i;
    int aparece = 0;
    printf("\nChequeo a ver si declaré la variable: %s", nombre);
    for(i = 0; i < cantActual; i++)
        if(strcmpi(simbolos[i].nombre, nombre) == 0){
            aparece = 1;
            break;
        }
    
    if(aparece == 0){
        printf("\nSYNTAX ERROR: No se declaro la variable");
        exit(1);
    }
}

int existeConstante(const char* nombre){
    int i;
    int aparece = 0;
    printf("\nChequeo a ver si declaré la constante: %s", nombre);
    for(i = 0; i < cantActual; i++)
        if(strcmpi(simbolos[i].nombre, nombre) == 0){
            aparece = 1;
            break;
        }
    return aparece;
}

void seRepite(const char* nombre){
    int i;
    int aparece = 0;
    //     int posLastID = 0;
    // int posFirstID = 0;
    printf("\nChequeo a ver si se repite la variable: %s", nombre);
    for(i = 0; i < posLastID - 1; i++){
        if(strcmpi(vecVariables[i].nombre, nombre) == 0){
            aparece = 1;
            break;
        }
    }
    printf("Imprimiendo lista de variables \n");
    for(i = 0; i < posLastID; i++){
        printf("%s\n", vecVariables[i].nombre);
    }
    
    if(aparece == 1){
        printf("\nSYNTAX ERROR: La variable se repite");
        exit(1);
    }
}

char* getTipoByNombre(const char* nombre){
    int i;
    int aparece = 0;
    printf("\nBusco tipo de la variable: %s", nombre);
    for(i = 0; i < cantActual; i++)
        if(strcmpi(simbolos[i].nombre, nombre) == 0)
            return simbolos[i].tipoDato;
    return NULL;
}

void validarTiposAsignacion(const char* var1, const char* var2){
  char* type1 = getTipoByNombre(var1);
  char* type2 = getTipoByNombre(var2);

  if(strcmpi(type1, type2) != 0){
    printf("\nError de compilacion: Las variables son de distinto tipo !");
    exit(1);
  }
}