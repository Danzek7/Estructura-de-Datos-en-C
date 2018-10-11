#include <stdio.h>
#include <stdlib.h>
//Algoritmo Garwick

typedef struct Nodo
{
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* crearNodo();
Nodo* empilar(Nodo*,Nodo*); //pasar pila y tope
//Nodo* desempilar(Nodo*); //pasar tope
int pilaVacia(Nodo*);
void mostrarPila(Nodo*);

void main()
{
	Nodo* p;
	Nodo* tope;
	int i;
	int cantNodos;
	
	tope=NULL;
	
	do
	{
		printf ("\nCuantos nodos desea ingresar?: ");
		scanf ("%i",&cantNodos);
	}while(cantNodos<1);
	
	for (i=1;i<=cantNodos;i++)
	{
		p = crearNodo();
		printf ("\n Ingrese dato: ");
		scanf ("%i",&p->dato);
		tope=empilar(p,tope);
	}

	mostrarPila(tope);
	/*tope = desempilar(tope);
	mostrarPila(tope);
*/
}

Nodo* crearNodo()
{
	Nodo* nuevo;

 	nuevo = malloc (sizeof(Nodo));
	nuevo->sig=NULL;

	return  nuevo;
}

Nodo* empilar(Nodo* p,Nodo* tope)
{
	p->sig=tope;
	tope=p;
	p=NULL;
	
	return tope;
	
}
/*
Nodo* desempilar(Nodo* tope)
{
	Nodo* aux;
	aux = tope;
	tope = tope->sig;
	aux->sig=NULL;
	free(aux);
	aux=NULL;
	
	return tope;
}
*/
int pilaVacia(Nodo* tope)
{
	if (tope==NULL)
	{
		return 0;
	}else
	{
		return 1;
	}
}

void mostrarPila(Nodo* tope)
{
	Nodo* aux;
	
	aux=tope;
	printf("\n");
	
	do
	{
		printf (" %i\n _ \n",aux->dato);
		aux=aux->sig;
	}while(aux!=NULL);
	
	printf ("NULL\n");
}
