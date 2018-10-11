#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol
{
	struct NodoArbol* izq;
	char dato;
	struct NodoArbol* der;
}NodoArbol;

NodoArbol* crearNodo(char );
NodoArbol* agregarIzquierda(NodoArbol* , NodoArbol* );
NodoArbol* agregarDerecha(NodoArbol* , NodoArbol* );
void imprimirNodo(NodoArbol* );
void preOrden(NodoArbol* );
void inOrden(NodoArbol* );
void postOrden(NodoArbol* );

int main()
{
	NodoArbol* raiz;
	
	raiz=crearNodo('I');
	raiz->izq=crearNodo('D');
	
	raiz->izq->izq=crearNodo('A');
	raiz->izq->izq->der=crearNodo('C');
	raiz->izq->izq->der->izq=crearNodo('B');
	
	raiz->izq->der=crearNodo('H');
	raiz->izq->der->izq=crearNodo('E');
	raiz->izq->der->izq->der=crearNodo('F');
	raiz->izq->der->izq->der->der=crearNodo('G');
	
	printf("Pre-orden (raiz-izquierda-derecha):");
	preOrden(raiz);
	printf("\nIn-orden (izquierda-raiz-derecha): ");
	inOrden(raiz);
	printf("\nPost-orden (izquierda-derecha-raiz): ");
	postOrden(raiz);
	
	return 0;	
}

NodoArbol* crearNodo(char dato)
{
	NodoArbol* nodo;
	
	nodo=(NodoArbol*)malloc(sizeof(NodoArbol));
	nodo->dato=dato;
	nodo->izq=NULL;
	nodo->der=NULL;
	
	return nodo;
}

NodoArbol* agregarIzquierda(NodoArbol* nuevo, NodoArbol* raiz)
{
	raiz->izq=nuevo;
	return raiz;
}

NodoArbol* agregarDerecha(NodoArbol* nuevo, NodoArbol* raiz)
{
	raiz->der=nuevo;
	return raiz;
}

void imprimirNodo(NodoArbol* nodo)
{
	if(nodo!=NULL)
	{
		printf("\n %c",nodo->dato);
	}
}

void preOrden(NodoArbol* raiz)
{
	if(raiz!=NULL)
	{
		imprimirNodo(raiz);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void inOrden(NodoArbol* raiz)
{
	if(raiz!=NULL)
	{
		inOrden(raiz->izq);
		imprimirNodo(raiz);
		inOrden(raiz->der);
	}
}
                             
void postOrden(NodoArbol* raiz)
{
	if(raiz!=NULL)
	{
		postOrden(raiz->izq);
		postOrden(raiz->der);
		imprimirNodo(raiz);
	}
}
