#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol
{
	struct NodoArbol* izq;
	int dato;
	struct NodoArbol* der;
}NodoArbol;

NodoArbol* crearNodoArbol();
NodoArbol* crearABB();

//??? sucesorInOrden(NodoArbol*,int);
//??? abbDegenerado(NodoArbol*);
//??? diferenciaExtremos(NodoArbol*);


void main ()
{
	NodoArbol* raiz;
	
	printf("Creacion del Arbol Binario de Busqueda (ABB) \n");
	
	raiz=crearABB();
	
}

//Responda desde aquí


NodoArbol* crearNodoArbol()
{
	NodoArbol* nuevo;
	
	nuevo=(NodoArbol*)malloc(sizeof(NodoArbol));
	nuevo->izq=NULL;
	nuevo->der=NULL;
	
	return nuevo;
}

NodoArbol* crearABB()
{
	NodoArbol* raiz;
	NodoArbol* nodo;
	NodoArbol* aux;
	int opcion;
	
	raiz=NULL;
	
	do
	{
		nodo=crearNodoArbol();
		
		printf("\nIngrese la clave a insertar: ");
		scanf("%i",&nodo->dato);
		
		if(raiz == NULL)
			raiz=nodo;
		else
		{
			aux=raiz;
			while(aux != NULL)
			{
				if(nodo->dato < aux->dato)
					if(aux->izq == NULL)
					{
						aux->izq=nodo;
						aux=NULL;
					}	
					else
						aux=aux->izq;
				else
					if(aux->der == NULL)
					{
						aux->der=nodo;
						aux=NULL;
					}
					else
						aux=aux->der;
			}
		}
		
		do
		{
			printf("\nDesea ingresar otra clave? (1:Si - 0:No): ");
			scanf("%i",&opcion);
		}while(opcion != 1 && opcion != 0);
		
	}while(opcion != 0);	
	
	return raiz;
}


