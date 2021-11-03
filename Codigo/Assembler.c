#include "Assembler.h"

int generarAssembler(structNodo* startPtr){
    FILE* pf;

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
    if(nodo->hijoIzq != NULL){
        if(!esHoja(nodo->hijoIzq)){
            generarBodyAssembler(pf, nodo->hijoIzq);
        } else if(!esHoja(nodo->hijoDer)){
            generarBodyAssembler(pf, nodo->hijoDer);
        }
        generarBodyAssembler(pf, nodo->hijoDer);
        generarBodyAssembler(pf, nodo->hijoIzq);
    }

    fprintf(pf, "\n%-20s", nodo->valor);


// typedef struct nodo{
//     char valor[150];
//     struct nodo* hijoDer;
//     struct nodo* hijoIzq;
// }structNodo;
    return 1;
}