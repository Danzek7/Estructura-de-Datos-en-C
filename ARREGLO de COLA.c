/*
Desde una cola enlzada, extraer los nodos para enlazarlos a un arreglo de listas de tamaño 5, aplicando la función k % 5. Por ejemplo: si el valor del nodo es 13,
entonces 13 % 5 = 3, por lo tanto, ese nodo debe enlazarse en la lista de la cuarta posición del arreglo, índice 3.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Cola
{
	int dato;
	struct Cola* sig;
}Nodo;

Nodo* inicio=NULL;
Nodo* fin=NULL;

void encolar();
void desencolar(Nodo* []);
Nodo* crearNodo();
void mostrar();
void mostrarArreglo(Nodo* []);

void main()
{
	Nodo* arreglo[5]={NULL};
	int op;
	
	do
	{
		do
		{
			printf("\nQue quieres hacer?:\n");
			printf("\n1.Encolar");
			printf("\n2.Desencolar");
			printf("\n3.Mostrar");
			printf("\n4.Salir");
			printf("\nR: ");
			scanf("%i",&op);
			
		}while(op<1 || op>4);
		
		switch(op)
		{
			case 1: printf("\n---encolando---\n");
				encolar();
				mostrar();
				break;
			case 2: printf("\n---desencolando---\n");
				desencolar(arreglo);
				mostrarArreglo(arreglo);
				break;
			case 3: printf("\n---mostrando---\n");
				mostrarArreglo(arreglo);
				break;
			case 4:
				break;
		}
	}while(op!=4);
}

void encolar()
{
	Nodo* nodo;
	
	nodo=crearNodo();
	
	if(inicio==NULL)
	{
		inicio=nodo;
		fin=inicio;
	}else
	{
		fin->sig=nodo;
		fin=nodo;
	}
}

void desencolar(Nodo* array[])
{
	int indice;
	Nodo* aux;
	Nodo* aux2;
	
	if(inicio==NULL)
	{
		printf("\n---¡¡¡No hay elementos para eliminar!!!---\n");
	}else
	{
		aux=inicio;
		inicio=inicio->sig;
		aux->sig=NULL;
		
		indice=aux->dato%5;
		
		if(array[indice]==NULL)
		{
			array[indice]=aux;
		}else
		{
			aux2=array[indice];
			
			while(aux2->sig!=NULL)
			{
				aux2=aux2->sig;
			}
			
			aux2->sig=aux;
			printf("\nArreglo[indice]: %d\n",array[indice]);
		}
	}
}

Nodo* crearNodo()
{
	Nodo* nodo;
	
	nodo=(Nodo*)malloc(sizeof(Nodo));
	
	printf("\nValor del nuevo nodo: ");
	scanf("%i",&nodo->dato);
	
	nodo->sig=NULL;
	
	return nodo;
}

void mostrarArreglo(Nodo* array[])
{
	int i;
	Nodo* auxArreglo;
	
	for(i=0;i<5;i++)
	{
		if(array[i]!=NULL)
		{
			auxArreglo=array[i];
			printf("\nArreglo[%d] ->",i);
			
			while(auxArreglo!=NULL)
			{
				printf(" |%d| ",auxArreglo->dato);
				auxArreglo=auxArreglo->sig;
			}
		}else
		{
			printf("\nArreglo[%d] = NULL",i);
		}
	}
	printf("\n");
}

/*NO se PUEDE!!!!!!!!*/
void mostrar()
{
	Nodo* aux;
	
	aux=inicio;
	
	printf("\n");
	
	while(aux!=NULL)
	{
		printf(" %i-->",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL\n");
}
