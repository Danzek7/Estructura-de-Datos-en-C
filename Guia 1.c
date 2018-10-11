#include<stdio.h>
#include<stdlib.h>

typedef struct Cola
{
	int dato;
	struct Cola* sig;
}Nodo;

Nodo* encolar();
Nodo* crearNodo();

void main()
{
	Nodo* ini;
	ini=encolar();
}

Nodo* encolar()
{
	Nodo* ini;
	Nodo* fin;
	Nodo* nodo;
	int i;
	int cant;
	
	do
	{
		printf("\nIngrese la cantidad de elementos que conforman la cola: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	nodo=NULL;
	ini=NULL;
	fin=NULL;
	
	for(i=0;i<cant;i++)
	{
		nodo=crearNodo();
		printf("\nNodo %i: ",i+1);
		scanf("%i",&nodo->dato);
		
		if(ini==NULL)
		{
			ini=nodo;
			fin=ini;
		}else
		{
			fin->sig=nodo;
			fin=nodo;
		}	
	}

	return ini;
}

Nodo* crearNodo()
{
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	return nodo;
}
