#include "Arbol.h"  

structNodo* crearHoja(const char* elemento, char* tipo){
    structNodo* nodo = (structNodo*) malloc(sizeof(struct nodo));
    strcpy(nodo->valor, elemento);
    nodo->tipo = tipo;
    nodo->hijoIzq = NULL;
    nodo->hijoDer = NULL;
    return nodo;
}

// structNodo* crearHoja(int elemento){
//     structNodo* nodo = (structNodo*) malloc(sizeof(struct nodo));
//     char string[50];
//     itoa(elemento, string,10 );
//     strcpy(nodo->valor, elemento);
//     nodo->hijoIzq = NULL;
//     nodo->hijoDer = NULL;
//     return nodo;
// }

structNodo* crearNodo(const char* raiz, char* tipo, structNodo* nodoIzq, structNodo* nodoDer){
    structNodo* nodo = crearHoja(raiz, NULL);
    nodo->tipo = tipo;
    nodo->hijoIzq = nodoIzq;
    nodo->hijoDer = nodoDer;
    return nodo;
}

structNodo* crearNodo2(structNodo* nodoRaiz, char* tipo,structNodo* nodoIzq, structNodo* nodoDer){
    nodoRaiz->tipo  = tipo;
    nodoRaiz->hijoIzq = nodoIzq;
    nodoRaiz->hijoDer = nodoDer;
    return nodoRaiz;
}

void preorden(structNodo *nodo) {
    if (nodo != NULL) {
        printf("%s,", nodo->valor);
        preorden(nodo->hijoIzq);
        preorden(nodo->hijoDer);
    }
}
void inorden(structNodo *nodo) {
    if (nodo != NULL) {
        inorden(nodo->hijoIzq);
        printf("%s,", nodo->valor);
        inorden(nodo->hijoDer);
    }
}
void postorden(structNodo *nodo) {
    if (nodo != NULL) {
        postorden(nodo->hijoIzq);
        postorden(nodo->hijoDer);
        printf("%s,", nodo->valor);
    }
}

void liberarMemoria(structNodo* padre) {
    if(padre == NULL) {
        return;
    }
    liberarMemoria(padre->hijoDer);
    liberarMemoria(padre->hijoIzq);
    free(padre);
    return;
}

void llenarGragh(structNodo* padre, FILE *arch, int numNodo) {
    char* string1 = (char*) malloc(sizeof(char) *50);
    char* string2 = (char*) malloc(sizeof(char) *50);
    if(padre == NULL) {
        return;
    }
    int numHI = numNodo*2+1;
    int numHD = numNodo*2+2;
    
    if(padre->hijoIzq) {
        sprintf(string1, "%s|%s", padre->valor, padre->tipo);
        // printf("%s|%s\n", padre->hijoIzq->valor, padre->hijoIzq->tipo);
        sprintf(string2, "%s|%s", padre->hijoIzq->valor, padre->hijoIzq->tipo);
        fprintf(arch, "\t\"nodo_%d \\n%s\" -> \"nodo_%d \\n%s\"\n", numNodo, string1, numHI, string2);
    }
    if(padre->hijoDer) {
        sprintf(string1, "%s|%s", padre->valor, padre->tipo);
        sprintf(string2, "%s|%s", padre->hijoDer->valor, padre->hijoDer->tipo);
        fprintf(arch, "\t\"nodo_%d \\n%s\" -> \"nodo_%d \\n%s\"\n", numNodo, string1 ,numHD ,string2);
    }
    llenarGragh(padre->hijoIzq, arch, numHI);
    llenarGragh(padre->hijoDer, arch, numHD);
    return;
}

void escribirGragh(structNodo* padre) {
    FILE *archivo;

	archivo = fopen("gragh.dot", "w");
	if (archivo == NULL) {
		return;
	}
    //Escribir plantilla para poder dibujar el grafo
    fprintf(archivo, "%s\n", "digraph G {");
    llenarGragh(padre, archivo, 0);
    fprintf(archivo, "%s", "}");
    
    fclose(archivo);
    return;
}

void generarIntermedia(structNodo* padre){
    FILE* file = fopen("intermedia.txt", "wt");
    escribirIntermedia(file, padre);
    fclose(file);
}

void escribirIntermedia(FILE* file, structNodo* nodo){
    if (nodo != NULL) {
        escribirIntermedia(file, nodo->hijoIzq);
        fprintf(file, "%s\n", nodo->valor);
        // printf("%s,", nodo->valor);
        escribirIntermedia(file, nodo->hijoDer);
    }
}

int esHoja(structNodo *hoja) {
    if (hoja == NULL) {
        return 0;
    }
    return hoja->hijoIzq == NULL && hoja->hijoDer == NULL;
}