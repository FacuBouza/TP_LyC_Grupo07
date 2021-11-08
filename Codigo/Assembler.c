#include "Assembler.h"
int tieneElse = 0;
int tieneAnd = 0;
int tieneOr = 0;
int tieneNot = 0;
int cantAux = 0;
int cantThen = 0;
int cantElse = 1;
int cantEndif = 1;
int cantWhile = 0;
int cantEndWhile = 1;
int cantFor = 0;
int cantWhileEsp = 0;
int cantEndWhileEsp = 0;
char* tipoVariable = NULL;

structNodo* nodoAux = NULL;
struct pila pilaEstructura;
struct pila pilaExpresion;

int generarAssembler(structNodo* startPtr){
    FILE* pf;
    tipoVariable = (char*) malloc(sizeof(char)*2);
    nodoAux = (structNodo*) malloc(sizeof(struct nodo));
    crear(&pilaEstructura);
    crear(&pilaExpresion);

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
        printf("\nNombre: %s, Valor: %s, Tipo: %s", simbolos[i].nombre, simbolos[i].valor, simbolos[i].tipoDato);
        if(strcmpi(simbolos[i].tipoDato, "real") == 0)
            strcpy(tipoVariable, "dq");
        else if(strcmpi(simbolos[i].tipoDato, "string") == 0)
            strcpy(tipoVariable, "dt");
        else
            strcpy(tipoVariable, "dd");
        if(strcmp(simbolos[i].valor,"") == 0){
            fprintf(pf, "%-20s%-20s%-20s\n", simbolos[i].nombre, tipoVariable, "?");
        }else{
            fprintf(pf, "%-20s%-20s%-20s\n", simbolos[i].nombre, tipoVariable, simbolos[i].valor);
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
    int nodoFor = 0;
    int nodoWhileEsp = 0;

    int numElse = cantElse - 1;
    int numEndif = cantEndif - 1;
    int numWhile = cantWhile;
    int numEndWhile = cantEndWhile;
    int numFor = cantFor + 1;
    int numWhileEsp = cantWhileEsp + 1;


    if(nodo != NULL){

        printf("Nodo: %s\n", nodo->valor);
        if(strcmp(nodo->valor, "IF") == 0){
            nodoIf = 1;
            if(strcmp(nodo->hijoDer->valor, "CuerpoIf") == 0){
                tieneElse = 1;
                apilar(&pilaEstructura, crearHoja("IF_ELSE", NULL));
            } else {
                apilar(&pilaEstructura, crearHoja("IF", NULL));
            }
        }

        if(strcmp(nodo->valor, "WHILE") == 0){
            nodoWhile = 1;
            apilar(&pilaEstructura, crearHoja("WHILE", NULL));
            cantWhile++;
            numWhile = cantWhile;
            fprintf(pf, "while%d:\n", numWhile);
        }

        if(strcmp(nodo->valor, "FOR") == 0){
            nodoFor = 1;
            apilar(&pilaEstructura, crearHoja("FOR", NULL));
        }

        if(strcmp(nodo->valor, "CuerpoFor") == 0){
            fprintf(pf, "for%d:\n", numFor);

            apilar(&pilaExpresion, nodo->hijoDer);
            nodo->hijoDer = NULL;
        }

        if(strcmp(nodo->valor, "WHILE_ESP") == 0){
            nodoWhileEsp = 1;
            cantWhileEsp++;
            fprintf(pf, "while_esp%d:\n", numWhileEsp);
            apilar(&pilaEstructura, crearHoja("WHILE_ESP", NULL));
        }

        if(nodo->hijoIzq != NULL){
            if(esOperador(nodo->hijoIzq)){
                if(strcmp(nodo->hijoIzq->valor, "OR") == 0){
                    tieneOr = 1;
                } else if (strcmp(nodo->hijoIzq->valor, "AND") == 0){
                    tieneAnd = 1;
                } else {
                    tieneNot = 1;
                }
            }
        }

        //Voy hacia la izquierda
        recorrerArbolAssembler(pf, nodo->hijoIzq);

        if(esOperador(nodo)){
            tieneOr = 0;
            tieneAnd = 0;
            tieneNot = 0;
        }
        
        if(nodoIf){
            numElse = cantElse;
            cantThen++;
            fprintf(pf, "then_part%d:\n", cantThen);
        }

        //Tiene else, entonces salto incondicionalmente al final del if (falta ponerle el numerito al end_if) y completo el else_part (tambien falta numerito)
        if(strcmp(nodo->valor, "CuerpoIf") == 0){
            fprintf(pf, "jmp endif_part%d:\n", numEndif);
            fprintf(pf, "else_part%d:\n", numElse);
        }

        if(nodoWhile){
            fprintf(pf, "start_while%d:\n", numWhile);
        }

        if(nodoWhileEsp){
            fprintf(pf, "JMP endwhile_esp%d:\n", numWhileEsp);
            fprintf(pf, "start_while_esp%d:\n", numWhileEsp);
        }

        //Voy hacia la derecha
        recorrerArbolAssembler(pf, nodo->hijoDer);

        if(nodoIf){
            fprintf(pf, "endif_part%d:\n", numEndif + 1);
        }

        if(nodoWhile){
            fprintf(pf, "JMP while%d:\n", numWhile);
            fprintf(pf, "end_while%d:\n", numEndWhile);
        }

        if(nodoFor){
            recorrerArbolAssembler(pf, desapilar(&pilaExpresion));
            fprintf(pf, "JMP for%d:\n", numFor);
            fprintf(pf, "end_for%d:\n", numFor);
        }

        if(nodoWhileEsp){
            fprintf(pf, "JMP while_esp%d\n", numWhileEsp);
            fprintf(pf, "endwhile_esp%d:\n", numWhileEsp);
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
            if(strcmp(nodo->hijoDer->tipo, "integer") == 0)
                fprintf(pf, "fild %s\n", nodo->hijoDer->valor);
            else
                fprintf(pf, "fld %s\n", nodo->hijoDer->valor);
            fprintf(pf, "fstp %s\n", nodo->hijoIzq->valor);
        }else{
            //Hay que determinar si es entero (FILD) o no (FLD)
            if(strcmp(nodo->hijoIzq->tipo, "integer") == 0){
                fprintf(pf, "fild %s\n", nodo->hijoIzq->valor);
                fprintf(pf, "fild %s\n", nodo->hijoDer->valor);
            } else {
                fprintf(pf, "fld %s\n", nodo->hijoIzq->valor);
                fprintf(pf, "fld %s\n", nodo->hijoDer->valor);
            }
            fprintf(pf, "%s\n", getOperacion(nodo->valor));
            //Hay que determinar si es entero (FISTP) o no (FSTP)
            if(strcmp(nodo->hijoIzq->tipo, "integer") == 0)
                fprintf(pf, "fistp @aux%d\n", getNumAux());
            else
                fprintf(pf, "fstp @aux%d\n", getNumAux());
            fprintf(pf, "ffree\n");

            sprintf(nodo->valor, "@aux%d", cantAux);
        }
    }

    if(esComparacion(nodo->valor)){
        //Hay que determinar si es entero (FILD) o no (FLD)
        if(strcmp(nodo->hijoIzq->tipo, "integer") == 0)
            fprintf(pf, "fild %s\n", nodo->hijoIzq->valor);
        else
            fprintf(pf, "fld %s\n", nodo->hijoIzq->valor);
        fprintf(pf, "fcomp %s\n", nodo->hijoDer->valor);
        fprintf(pf, "fstsw ax\n");
        fprintf(pf, "sahf\n");
        printf("Nodo: %s -> %s -> %s\n Tiene Not?? %d \n", nodo->valor, nodo->hijoIzq->valor, nodo->hijoDer->valor, tieneNot);
        fprintf(pf, "%s %s%d\n", getComparacion(nodo->valor), getEtiqueta(), getNumEtiqueta());
    }

    if(strcmp(nodo->valor, "display") == 0){
        //Hay que determinar si es string (displayString var) o no (displayFloat val)
        fprintf(pf, "%s %s\n", getDisplay(nodo->hijoDer), nodo->hijoDer->valor);
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
    nodoAux = verTopePila(&pilaEstructura);
    if(strcmp(nodoAux->valor, "WHILE_ESP") == 0 || tieneOr || tieneNot){
        if(strcmp(comparador, "==") == 0)
            return "JE";
        if(strcmp(comparador, "!=") == 0)
            return "JNE";
        if(strcmp(comparador, ">") == 0)
            return "JA";
        if(strcmp(comparador, ">=") == 0)
            return "JAE";
        if(strcmp(comparador, "<") == 0)
            return "JB";
        if(strcmp(comparador, "<=") == 0)
            return "JBE";
    } else {
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
}

char* getEtiqueta(){
    // apilar(&pilaEstructura, crearHoja("IF_ELSE"));
    //         } else {
    //             apilar(&pilaEstructura, crearHoja("IF"));
    // structNodo* nodoAux
    nodoAux = verTopePila(&pilaEstructura);
    if(strcmp(nodoAux->valor, "IF") == 0){
        if(tieneOr){
            return "then_part";
        }
        return "endif_part";
    } else if(strcmp(nodoAux->valor, "IF_ELSE") == 0){
        if(tieneOr){
            return "then_part";
        }
        return "else_part";
    } else if(strcmp(nodoAux->valor, "WHILE") == 0){
        if(tieneOr){
            return "start_while";
        }
        return "end_while";
    } else if(strcmp(nodoAux->valor, "FOR") == 0){
        return "end_for";
    } else if(strcmp(nodoAux->valor, "WHILE_ESP") == 0){
        return "start_while_esp";
    }
    return "nada";
}

int getNumEtiqueta(){
    int valor = 0;
    nodoAux = verTopePila(&pilaEstructura);
    // nodoAux = desapilar(&pilaEstructura);
    if(nodoAux != NULL){
        if(strcmp(nodoAux->valor, "IF") == 0){
            valor = cantEndif;
            if(!tieneOr && !tieneAnd){
                cantEndif++;
            }
        } else if(strcmp(nodoAux->valor, "IF_ELSE") == 0){
            valor = cantElse;
            if(!tieneOr && !tieneAnd){
                cantElse++;
                cantEndif++;
            }
        } else if(strcmp(nodoAux->valor, "WHILE") == 0){
            valor = cantEndWhile;
            if(!tieneOr && !tieneAnd){
                cantEndWhile++;
            }
        } else if(strcmp(nodoAux->valor, "FOR") == 0){
            cantFor++;
            valor = cantFor;
        } else if(strcmp(nodoAux->valor, "WHILE_ESP") == 0){
            valor = cantWhileEsp;
        }
    }

    return valor;
}

char* getDisplay(structNodo* nodo){
    //Hay que verificar si es string o no y devolver su instrucción
    if(strcmp(nodo->tipo, "string") == 0)
        return "displayString";
    else
        return "displayFloat";
}

int esOperador(structNodo* nodo){
    return strcmp(nodo->valor, "OR") == 0 ||
        strcmp(nodo->valor, "AND") == 0 ||
        strcmp(nodo->valor, "NOT") == 0;
}