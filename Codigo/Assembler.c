#include "Assembler.h"
int tieneElse = 0;
int cantAux = 0;
int cantElse = 0;
int cantEndif = 0;
structNodo* nodoAux = NULL;
struct pila pilaEstructura;

int generarAssembler(structNodo* startPtr){
    FILE* pf;
    nodoAux = (structNodo*) malloc(sizeof(struct nodo));
    crear(&pilaEstructura);

    pf = fopen("Final.asm", "w+");

    if(pf == NULL){
        printf("Error al abrir el archivo ""Final.asm""");
        return(-1);
    }

    fprintf(pf, ".MODEL LARGE\n");
    fprintf(pf, ".386\n");
    fprintf(pf, ".STACK 200h\n");

    //Genero un archivo auxiliar para el body porque pueden aparecer nuevas variables en la tabla de simbolos
    generarBodyAssembler(startPtr);

    copiarVariablesAssembler(pf);

    fprintf(pf, "\n.CODE\n");
    fprintf(pf, "\nmov AX,@DATA\n");
    fprintf(pf, "mov DS,AX\n");
    fprintf(pf, "mov es,ax\n");

    copiarBodyAssembler(pf);

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

int copiarBodyAssembler(FILE* pfAssem){
    FILE* pfBody = fopen("body.txt", "r");
    char ch;

	if (pfBody == NULL) {
		printf("Error al intentar abrir el archivo body.txt\n");
		return -1;
	}

    while((ch = fgetc(pfBody)) != EOF)
        fputc(ch, pfAssem);

    fclose(pfBody);
    return 1;
}

int generarBodyAssembler(structNodo* nodo){
    FILE* pfBody = fopen("body.txt", "wt+");
    if(pfBody == NULL){
        printf("Error al generar el archivo body del assembler");
        return -1;
    }
    recorrerArbolAssembler(pfBody, nodo);
    fclose(pfBody);
    return 0;
}

int recorrerArbolAssembler(FILE* pf, structNodo* nodo){
    int nodoIf = 0;
    int nodoWhile = 0;
    int numElse = cantElse;
    int numEndif = cantEndif;

    if(nodo != NULL){

        if(strcmp(nodo->valor, "IF") == 0){
            nodoIf = 1;
            if(strcmp(nodo->hijoDer->valor, "Cuerpo") == 0){
                tieneElse = 1;
                apilar(&pilaEstructura, crearHoja("IF_ELSE"));
            } else {
                apilar(&pilaEstructura, crearHoja("IF"));
            }
        }

        //Voy hacia la izquierda
        recorrerArbolAssembler(pf, nodo->hijoIzq);

        if(nodoIf){
            numElse = cantElse;
            fprintf(pf, "then_part:\n");
        }

        //Tiene else, entonces salto incondicionalmente al final del if (falta ponerle el numerito al end_if) y completo el else_part (tambien falta numerito)
        if(strcmp(nodo->valor, "Cuerpo") == 0){
            fprintf(pf, "jmp end_if%d:\n", cantEndif);
            fprintf(pf, "else_part%d:\n", numElse);
        }

        //Voy hacia la derecha
        recorrerArbolAssembler(pf, nodo->hijoDer);

        if(strcmp(nodo->valor, "Cuerpo") == 0){
            fprintf(pf, "end_if%d:\n", numEndif);
        }

        if(esHoja(nodo->hijoIzq) && esHoja(nodo->hijoDer)){
            //Hago la operación del arbol y lo reduzco
            realizarOperacion(pf, nodo);
            nodo->hijoIzq = NULL;
            nodo->hijoDer = NULL;
        }


        // fprintf(pf, "%s\n", nodo->valor);

    }
    return 0;
}

void realizarOperacion(FILE* pf,structNodo* nodo){
    if(esOperacionAritmetica(nodo->valor)){
        if(esAsignacion(nodo->valor)){
            //Hay que determinar si es entero (FILD) o no (FLD)
            fprintf(pf, "fild %s\n", nodo->hijoDer->valor);
            fprintf(pf, "fstp %s\n", nodo->hijoIzq->valor);
        }else{
            //Hay que determinar si es entero (FILD) o no (FLD)
            fprintf(pf, "fild %s\n", nodo->hijoIzq->valor);
            fprintf(pf, "fild %s\n", nodo->hijoDer->valor);
            fprintf(pf, "%s\n", getOperacion(nodo->valor));
            //Hay que determinar si es entero (FISTP) o no (FSTP)
            fprintf(pf, "fistp @aux%d\n", getNumAux());
            fprintf(pf, "ffree\n");

            sprintf(nodo->valor, "@aux%d", cantAux);
        }
    }

    if(esComparacion(nodo->valor)){
        //Hay que determinar si es entero (FILD) o no (FLD)
        fprintf(pf, "fild %s\n", nodo->hijoIzq->valor);
        fprintf(pf, "fcomp %s\n", nodo->hijoDer->valor);
        fprintf(pf, "fstsw ax\n");
        fprintf(pf, "sahf\n");
        fprintf(pf, "%s %s%d\n", getComparacion(nodo->valor), getEtiqueta(), getNumEtiqueta());
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
        return "FADD";
    if(strcmp(operador, "-") == 0)
        return "FSUB";
    if(strcmp(operador, "*") == 0)
        return "FMUL";
    if(strcmp(operador, "/") == 0)
        return "FDIV";
}

int getNumAux(){
    cantAux++;
    char* cadAux = (char*) malloc(sizeof(char)*20);
    sprintf(cadAux, "@aux%d", cantAux );
    agregarSimbolo(cadAux, "FLOAT", "", strlen(cadAux), "ID");
    return cantAux;
}

int esComparacion(char* valor){
    return strcmp(valor, "==") == 0 ||
        strcmp(valor, "!=") == 0 ||
        strcmp(valor, ">") == 0 || 
        strcmp(valor, ">=") == 0 ||
        strcmp(valor, "<") == 0 ||
        strcmp(valor, "<=") == 0;
}

char* getComparacion(char* comparador){
    if(strcmp(comparador, "==") == 0)
        return "JNE";
    if(strcmp(comparador, "!=") == 0)
        return "JE";
    if(strcmp(comparador, ">") == 0)
        return "JBE";
    if(strcmp(comparador, ">=") == 0)
        return "JB";
    if(strcmp(comparador, "<") == 0)
        return "JAE";
    if(strcmp(comparador, "<=") == 0)
        return "JA";
}

char* getEtiqueta(){
    // apilar(&pilaEstructura, crearHoja("IF_ELSE"));
    //         } else {
    //             apilar(&pilaEstructura, crearHoja("IF"));
    // structNodo* nodoAux
    nodoAux = verTopePila(&pilaEstructura);
    if(strcmp(nodoAux->valor, "IF") == 0){
        return "endif_part";
    } else if(strcmp(nodoAux->valor, "IF_ELSE") == 0){
        return "else_part";
    }
}

int getNumEtiqueta(){
    int valor;
    nodoAux = verTopePila(&pilaEstructura);

    if(strcmp(nodoAux->valor, "IF") == 0){
        cantEndif++;
        valor = cantEndif;
    } else if(strcmp(nodoAux->valor, "IF_ELSE") == 0){
        cantElse++;
        cantEndif++;
        valor = cantElse;
    }

    return valor;
}