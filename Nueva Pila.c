#include <stdio.h>
#include <stdlib.h>

typedef struct NodoPila
{
	int valor;
	struct NodoPila* sig;
}NodoPila;

NodoPila* crearNodo();
NodoPila* empilar(NodoPila* , NodoPila* );
void mostrarPila(NodoPila* );
void desempilar(NodoPila* );

void main()
{
	NodoPila* tope;
	NodoPila* p;
	int cant;
	int res;
	int i;
	
	tope=NULL;
	
	do
	{
		printf("Ingrese la cantidad de nodos que tendrá la pila: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	for(i=1;i<=cant;i++)
	{
		p=crearNodo();
		printf("\El valor del nodo %i es: ",i);
		scanf("%i",&p->valor);
		tope=empilar(p, tope);
	}
	
	do
	{
		do
		{
			printf("\nDesea eliminar un nodo? (1.Si, 0.No): ");
			scanf("%i",&res);
		}while(res<0 || res>=2);
		
		if(res==1)
		{
			desempilar(tope);
		}	
	}while(res!=0);
	
	if(tope!=NULL)
	{
		mostrarPila(tope);
	}else
	{
		printf("\nNo hay más elementos en la pila");	
	}
}

NodoPila* empilar(NodoPila* p, NodoPila* tope)
{
	p->sig=tope;
	tope=p;
	p=NULL;
	return tope;
}

void mostrarPila(NodoPila* tope)
{
	NodoPila* aux;
	aux=tope;
	printf("\n");
	do
	{
		printf(" %i\n _\n",aux->valor);
		aux=aux->sig;
	}while(aux!=NULL);
	printf(" NULL");
}

NodoPila* crearNodo()
{
	NodoPila* nodo;
	
	nodo=(NodoPila*)malloc(sizeof(NodoPila*));
	nodo->sig=NULL;
	
	return nodo;
}

void desempilar(NodoPila* tope)
{
	NodoPila* aux;
	
	aux=tope;
	tope=tope->sig;
	aux->sig=NULL;
	free(aux);
	aux=NULL;
}
