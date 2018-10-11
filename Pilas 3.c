#include <stdlib.h>
#include <stdio.h>


typedef struct Nodo
{
	int dato;
	struct Nodo* sig;
	
}Nodo;

Nodo* crearNodo();
Nodo* empilar(Nodo*,Nodo*);
Nodo* desempilar(Nodo*);
//int pilaVacia(Nodo*);
void  MostrarPila(Nodo*);



void main()
{
	int CantElementos;
	int i;
	Nodo* tope=NULL;
	Nodo* nuevo;
	
	do
	{
		printf("Ingrese Cantidad de elementos para Empilar: ");
		scanf("%d",&CantElementos);
	}while(CantElementos<1);
	
	for(i=1;i<=CantElementos;i++)
	{
		nuevo=crearNodo();
		
	    tope=empilar(nuevo,tope);
	}
	MostrarPila(tope);
	
}


Nodo* CrearNodo()
{
	Nodo* nodo;
	
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	return nodo;
}

Nodo* empilar(Nodo* nodo, Nodo* tope)
{
	nodo->sig=tope;
	tope=nodo;
	nodo=NULL;
	
	return tope;
}

Nodo* desempilar(Nodo* tope)
{
	Nodo* aux;
	aux=tope;
	tope=aux->sig;
	aux->sig=NULL;
	                         
	free(aux);   
	
	aux=NULL;                      
	
	return tope;
	
}
 
void MostrarPila(Nodo* tope)
{ 
    Nodo* aux;
    aux=tope;
    
	while(aux!=NULL)
	{
		printf("\nValor tope: %i ",aux->dato);
		aux=desempilar(aux);
	}
	 
}
 
