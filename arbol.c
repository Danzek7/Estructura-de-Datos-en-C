#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol{
	struct NodoArbol* izq;
	int dato;
	struct NodoArbol* der;
}NodoArbol;

void insertaNodo(NodoArbol*, int);
void inOrden(NodoArbol*);
void preOrden(NodoArbol*);
void postOrden(NodoArbol*);

void main(){
	int i;
	int elemento;
	NodoArbol* nodo;
	nodo=NULL;
}
