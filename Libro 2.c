#include <stdio.h>
#include <stdlib.h>

typedef struct Pila
{
	int dato;
	struct Pila* sig;
}Nodo;

Nodo* crearNodo();
Nodo* empilar(Nodo*,Nodo*);
void mostrarPila(Nodo* );

void main()
{
	Nodo* p;
	Nodo* tope;
	int op;
	int i;
	
	i=0;
	tope=NULL;
	
	do
	{
		p=crearNodo();
		
		printf(" \nNodo %i: ",i+1);
		scanf("%i",&p->dato);
		
		tope=empilar(p,tope);
		i++;
		
		do
		{
			printf("\n_Desea seguir empilando? (1.Si, 0:No): ");
			scanf("%i",&op);
		}while(op<0 || op>1);
		
	}while(op!=0);
	
	mostrarPila(tope);
}

Nodo* empilar(Nodo* p, Nodo* tope)
{
	p->sig=tope;
	
	tope=p;
	p=NULL;
	
	return tope;
}

Nodo* crearNodo()
{
	Nodo* nodo;
	
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	
	return nodo;
}

void mostrarPila(Nodo* tope)
{
	Nodo* aux;
	
	aux=tope;
	
	printf("\n");
	
	do
	{
		printf(" %i\n _\n",aux->dato);
		aux=aux->sig;	
	}while(aux!=NULL);
	
	printf(" NULL");	
}
