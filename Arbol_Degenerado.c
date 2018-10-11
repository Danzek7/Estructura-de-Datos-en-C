#include <stdio.h>
#include <stdlib.h>

typedef struct Arbol
{
	struct Arbol* izq;
	int dato;
	struct Arbol* der;
}NodoArbol;

int buscarValor(NodoArbol* , int );

void main()
{
	NodoArbol* raiz;
	NodoArbol* aux;
	NodoArbol* nodo;
	int exito;
	int op;
	int hijo;
	int valor;
	
	raiz=NULL;
	
	do
	{
		nodo=(NodoArbol*)malloc(sizeof(NodoArbol));
		
		printf("\n Ingrese valor para el nuevo nodo: ");
		scanf("%i",&nodo->dato);
		
		nodo->izq=NULL;
		nodo->der=NULL;
		
		if(raiz==NULL)
		{
			raiz=nodo;
			aux=raiz;
		}else
		{
			do
			{
				printf("\n Ingrese (1).Hijo izquierdo o (2).Hijo derecho: ");
				scanf("%i",&hijo);
			}while(hijo<1 || hijo>2);
			
			if(hijo==1)
			{
				aux->izq=nodo;
				aux=aux->izq;
			}else
			{
				aux->der=nodo;
				aux=aux->der;	
			}
		}
		
		do
		{
			printf("\n-- Desea seguir ingresando nodos al arbol? (1:si, 0:no): ");
			scanf("%i",&op);
		}while(op<0 || op>1);
		
			/*
			crear nodo;
			solicitar valor
			reconocer si debe ser la raíz (Si T==NULL, osea, el árbol es nulo)
			seguir con las inserciones (perguntar si es hijo izq o der)
			*/
	}while(op!=0);
	
	printf("\n\n Ingrese valor a buscar: ");
	scanf("%i",&valor);
	
	exito=buscarValor(raiz,valor);
	
	if(exito) //exito == 1
	{
		printf("\n ¡¡¡Valor Encontrado!!!");
	}else
	{
		printf("\n Valor NO Encontrado");
	}
}

int buscarValor(NodoArbol* T, int valor)
{
	NodoArbol* aux;
	int enc;
	
	aux=T;
	enc=0;
	
	do
	{
		if(aux->dato==valor)
		{
			enc=1;
		}else
		{
			if(aux->izq!=NULL)
			{
				aux=aux->izq;
			}else
			{
				if(aux->der!=NULL)
				{
					aux=aux->der;
				}else
				{
					aux=NULL;
				}
			}
		}
	}while(aux!=NULL && enc==0);
	
	return enc;
}
