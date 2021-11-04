#include "Pila.h"

/*
 * Inicializamos la estructura de la pila, ponemos el valor de frente en NULL y el contador de objetos en 0
 */
int crear(struct pila *p) {
	p->frente = NULL;
	p->tamano = 0;
	return 1;
}

int apilar(struct pila *p, structNodo* nodoPtr){
	/* Creamos un elemento nuevecito para meterlo en la pila
	 * y que el usuario no pudeda luego hacerle nada!
	 * Copiamos los datos del usuario en nuestro nuevo elemento.
	 */
	struct elemento *nuevo = (struct elemento *) malloc(sizeof(struct elemento));
	// Si por cualquier situacion el OS no puede asignarnos mas memoria la variable queda en NULL, si este
	// es el caso nosotros regresaremos un -1 indicando que la operacion fallo.
	if (nuevo == NULL) { return -1; }
	nuevo->dato = nodoPtr;
	nuevo->next = NULL;

	/* Ahora metemos ese nuevo elemento en la pila,
	 * ahora cualquier cambio que haga el usuario no nos afectara
	 * en nada
	 */
	
	nuevo->next = p->frente;
	p->frente = nuevo;
	p->tamano++;

    // printf("\nInicio apilar...");

    // printf("\nValor: %s, Hijo izq: %s, Hijo der: %s ", nodoPtr->valor, nodoPtr->hijoIzq, nodoPtr-> hijoDer);

    // printf("\nFin apilar... \n");


	return 1;
}

structNodo* desapilar(struct pila *p){
    structNodo* aux;
	// si la pila esta vacia retornamos -1
	if (estaVacia(*p) ) { return NULL; }
	// COPIAMOS el dato a retornar al usuario.
	aux = p->frente->dato;
	p->tamano--;
	p->frente = p->frente->next;

    // printf("\nInicio desapilar... ");

    // printf("\nValor: %s, Hijo izq: %s, Hijo der: %s", aux->valor, aux->hijoIzq, aux-> hijoDer);

    // printf("\nFin desapilar... ");
    return aux;
}

int estaVacia(struct pila p){
	if (p.tamano == 0) { return 1; }
	//if (p.frente == NULL) { return 1; }
	return 0;
}

int tamano(struct pila p){
	return p.tamano;
}