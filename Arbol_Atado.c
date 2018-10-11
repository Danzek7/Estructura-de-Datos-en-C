#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol
{
	struct NodoArbol* izq;
	int ataduraIzq; //1= hijo
	char dato;
	int ataduraDer; //0= atadura
	struct NodoArbol* der;
}NodoArbol;
