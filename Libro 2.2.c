#include <stdio.h>
#include <stdlib.h>

typedef struct Pila
{
	int dato;
	struct Pila* sig;
}Nodo;

Nodo* crearNodo();
Nodo* empilar(Nodo* , Nodo* );
Nodo* desempilar(Nodo* );
Nodo* seguirEmpilando(Nodo* );
void mostrar(Nodo* );

void main()
{
	Nodo* tope;
	Nodo* p;
	Nodo* nodo;
	
	int i;
	int tam;
	int op;
	int esp;
	
	tope=NULL;
	esp=0;
	
	do
	{
		printf("\nIngrese el tamanio de la pila: ");
		scanf("%i",&tam);
	}while(tam<1);
	
	for(i=1;i<=tam;i++)
	{
		nodo=crearNodo();
		printf(" \nElemento %i: ",i);
		scanf("%i",&nodo->dato);
		p=nodo;
		tope=empilar(p,tope);
	}
	
	do
	{
		do
		{
			printf("\nSeleccione lo que hay que hacer:\n1.Empilar\n2.Desempilar\n3.Ordenar\n4.Mostrar\n5.Salir\nR: ");
			scanf("%i",&op);
		}while(op<1 || op>5);
		printf("\n");
		
		switch(op)
		{
			case 1:
				tope=seguirEmpilando(tope);
				printf("\nPila ordenada");
				break;
			case 2:
				tope=desempilar(tope);
				break;
			case 3:
				break;
			case 4:
				if(tope==NULL)
				{
					printf("\nLa pila se encuentra vacia\n");
				}else
				{
					mostrar(tope);
				}
				
				break;
			case 5:
				break;
		}
	}while(op!=5);
}

Nodo* empilar(Nodo* p, Nodo* tope)
{
	p->sig=tope;
	tope=p;
	p=NULL;
}

Nodo* crearNodo()
{
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	return nodo;
}

Nodo* desempilar(Nodo* tope)
{
	Nodo* aux;
	
	aux=tope;
	
	if(aux==NULL)
	{
		printf("\nNo se puede seguir desempilando\n");
	}else
	{
		tope=aux->sig;
		aux->sig=NULL;
		free(aux);
		aux=NULL;
		printf("Elemento desempilado\n");
	}
	return tope;
}

Nodo* seguirEmpilando(Nodo* tope)
{
	Nodo* aux;
	
	if()
}

void mostrar(Nodo* tope)
{
	Nodo* aux;
	
	aux=tope;
	printf("\n");
	
	while(aux!=NULL)
	{
		printf(" %i\n _\n",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL\n");
}
