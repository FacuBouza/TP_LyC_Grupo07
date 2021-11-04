#include "Assembler.h"
int conElse = 0;
int cantAux = 0;

int generarAssembler(structNodo* startPtr){
    FILE* pf;
    struct pila pilaIf;
    struct pila pilaWhile;

    pf = fopen("Final.asm", "w+");

    if(pf == NULL){
        printf("Error al abrir el archivo ""Final.asm""");
        return(-1);
    }

    fprintf(pf, ".MODEL LARGE\n");
    fprintf(pf, ".386\n");
    fprintf(pf, ".STACK 200h\n");

    copiarVariablesAssembler(pf);

    fprintf(pf, "\n.CODE\n");
    fprintf(pf, "\nmov AX,@DATA\n");
    fprintf(pf, "mov DS,AX\n");
    fprintf(pf, "mov es,ax\n");

    generarBodyAssembler(pf, startPtr);

    fprintf(pf, "mov ax,4c00h\n");
    fprintf(pf, "Int 21h\n");
    fprintf(pf, "\nEnd");

    fclose(pf);

    return 1;
}

int copiarVariablesAssembler(FILE* pf){

    fprintf(pf, "\n.DATA\n");
    fprintf(pf, "\n");

    //Armo las variables con la tabla de simbolos
    printf("Valor simbolos:");
    for(int i=1; i<getCantSimbolos(); i++){
        printf("\nNombre: %s, Valor: %s", simbolos[i].nombre, simbolos[i].valor);
        if(strcmp(simbolos[i].valor,"") == 0){
            fprintf(pf, "%-20s%-20s%-20s\n", simbolos[i].nombre, "dd", "?");
        }else{
            fprintf(pf, "%-20s%-20s%-20s\n", simbolos[i].nombre, "dd", simbolos[i].valor);
        }
    }

    return 1;
    
}

int generarBodyAssembler(FILE* pf, structNodo* nodo){
    // fprintf(pf, "\nACA VA A IR EL BODY CUANDO SE HAGA\n");
    int nodoIf = 0;
    int nodoWhile = 0;

    if(nodo != NULL){

        if(strcmp(nodo->valor, "IF") == 0){
            nodoIf = 1;
            if(strcmp(nodo->valor, "Cuerpo") == 0){
                conElse = 1;
            }
        }

        //Voy hacia la izquierda
        generarBodyAssembler(pf, nodo->hijoIzq);

        //Voy hacia la derecha
        generarBodyAssembler(pf, nodo->hijoDer);

        if(esHoja(nodo->hijoIzq) && esHoja(nodo->hijoDer)){
            //Hago la operación del arbol y lo reduzco
            realizarOperacion(pf, nodo);
            nodo->hijoIzq = NULL;
            nodo->hijoDer = NULL;
        }

        fprintf(pf, "\n%-20s", nodo->valor);

    }



// typedef struct nodo{
//     char valor[150];
//     struct nodo* hijoDer;
//     struct nodo* hijoIzq;
// }structNodo;
    return 1;
}

void realizarOperacion(FILE* pf,structNodo* nodo){
    if(esOperacionAritmetica(nodo->valor)){
        if(esAsignacion(nodo->valor)){
            fprintf(pf, "\nMOV R1, %s", nodo->hijoDer->valor);
            fprintf(pf, "\nMOV %s, R1", nodo->hijoIzq->valor);
        }else{
            fprintf(pf, "\nMOV R1, %s", nodo->hijoIzq->valor);
            fprintf(pf, "\n%s R1, %s", getOperacion(nodo->valor), nodo->hijoDer->valor);
            fprintf(pf, "\nMOV @aux%d, R1", getNumAux());
            sprintf(nodo->valor, "@aux%d", cantAux);
        }
    }
}

int esOperacionAritmetica(char* operador){
    return strcmp(operador, "+") == 0 ||
        strcmp(operador, "/") == 0 ||
        strcmp(operador, "*") == 0 || 
        strcmp(operador, "-") == 0 ||
        strcmp(operador, ":=") == 0;
}

int esAsignacion(char* operador){
    return strcmp(operador, ":=") == 0;
}

char* getOperacion(char* operador){
    if(strcmp(operador, "+") == 0)
        return "ADD";
    if(strcmp(operador, "-") == 0)
        return "SUB";
    if(strcmp(operador, "*") == 0)
        return "MUL";
    if(strcmp(operador, "/") == 0)
        return "DIV";
}

int getNumAux(){
    cantAux++;
    char* cadAux = (char*) malloc(sizeof(char)*20);
    sprintf(cadAux, "@aux%d", cantAux );
    agregarSimbolo(cadAux, "FLOAT", "", strlen(cadAux), "ID");
    return cantAux;
}