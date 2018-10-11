#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* ingresarNodos();
Nodo* crearNodo();
void eliminar(Nodo* );
void mostrarLista(Nodo* );
void ordenar(Nodo* );

void main()
{
	Nodo* lista;
	int op;
	
	lista=ingresarNodos();
	
	do
	{
		do
		{
			printf("\nQue desea hacer con la lista?: (1.Insertar, 2.Eliminar, 3.Mostrar, 4.Ordenar, 5.Quit): ");
			scanf("%i",&op);
		}while(op<1 || op>=6);
		
		switch(op)
		{
			case 1:
				break;
			case 2:
				eliminar(lista);
				break;
			case 3:
				mostrarLista(lista);
				break;
			case 4:
				ordenar(lista);
				break;
			case 5:
				break;
		}
	}while(op!=5);
}

Nodo* ingresarNodos()
{
	Nodo* head;
	Nodo* aux;
	Nodo* nodo;
	int i;
	int cant;
	
	head=NULL;
	i=0;
	
	printf("Ingresar nodos a la lista: ");
	
	do
	{
		printf("\nIngrese la cantidad de nodos que tendrá a lista: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	do
	{
		nodo=crearNodo();
		printf("\n Nodo nro° %i: ",i+1);
		scanf("%i",&nodo->dato);
		if(head==NULL)
		{
			head=nodo;
			aux=head;
		}else
		{
			aux->sig=nodo;
			aux=nodo;
		}
		i++;
	}while(i<cant);
	
	aux=NULL;
	nodo=NULL;
	
	return head;
}

Nodo* crearNodo()
{
	Nodo* nodo;
	
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	
	return nodo;
}

void eliminar(Nodo* lista)
{
	Nodo* aux;
	Nodo* aux2;
	Nodo* cola;
	int enc;
	int op;
	
	enc=0;
	aux=lista;
	aux2=lista;
	cola=lista;
	
	printf("\n--Que elemento desea eliminar de la lista?: ");
	scanf("%i",&op);
	
	while(cola->sig!=NULL)
	{
		cola=cola->sig;
	}
	
	while(enc!=1 && aux!=NULL)
	{
		if(aux->dato==op)
		{
			enc=1;
		}else
		{
			aux=aux->sig;
		}
	}
	
	if(enc==0)
	{
		printf("\nElemento no encontrado\n");
	}else
	{
		if(aux==lista)
		{
			if(aux==cola)
			{
				lista=NULL;
				free(aux);
				aux=NULL;
			}else
			{
				lista=aux->sig;
				aux->sig=NULL;
				free(aux);
				aux=NULL;
			}
		}else
		{
			if(aux==cola)
			{
				while(aux2->sig!=cola)
				{
					aux2=aux2->sig;
				}
				aux2->sig=NULL;
				free(cola);
				cola=NULL;
			}else
			{
				while(aux2->sig!=aux)
				{
					aux2=aux2->sig;
				}
				aux2->sig=aux->sig;
				aux2=aux2->sig;
				aux->sig=NULL;
				free(aux);
				aux=NULL;
			}
		}
	}
	printf("\n");
}

void ordenar(Nodo* nodo)
{
	Nodo* aux;
	Nodo* aux2;
	
	aux=nodo;
	
	do
	{
		if(nodo<nodo->sig)
		{
			aux2=nodo;
			nodo=nodo->sig;
			nodo->sig=aux2;
		}else
		{
			aux=aux->sig;	
		}
	}while(aux!=NULL);
}

void mostrarLista(Nodo* lista)
{
	Nodo* aux;
	printf("\n");
	
	aux=lista;
	
	while(aux!=NULL){
		printf(" %i-->",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL\n");
}
