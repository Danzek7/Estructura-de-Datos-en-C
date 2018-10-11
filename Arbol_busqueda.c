#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol
{
	struct NodoArbol* izq;
	int dato;
	struct NodoArbol* der;
}NodoArbol;

NodoArbol* crearNodo();
int buscarNodo(NodoArbol* , int );
NodoArbol* eliminarNodo(NodoArbol* ,  int );

void main()
{
	NodoArbol* raiz;
	NodoArbol* nuevo;
	NodoArbol* aux;
	int opcion;
	int clave;
	int existe;
	
	raiz=NULL;
	
	do
	{
		nuevo=crearNodo();
		printf("\n Ingrese la nueva clave ingresada: ");
		scanf("%i",&nuevo->dato);
		
		if(raiz==NULL)
		{
			raiz=nuevo;
			aux=raiz;
		}else
		{
			aux=raiz;
			
			while(aux!=NULL)
			{
				if(nuevo->dato<aux->dato)
				{
					if(aux->izq==NULL)
					{
						aux->izq=nuevo;
						aux=NULL;
					}else
					{
						aux=aux->izq;
					}
				}else
				{
					if(aux->der==NULL)
					{
						aux->der=nuevo;
						aux=NULL;
					}else
					{
						aux=aux->der;
					}
				}
			}
		}
		
		do
		{
			printf(" \nDese ingresar otra clave? (1. si, 0. no): ");
			scanf("%i",&opcion);
		}while(opcion<0 || opcion>1);
		
	}while(opcion!=0);
	
	do
	{
		printf("\nIngrese la clave del nodo a eliminar: ");
		scanf("%i",&clave);
		
		existe=buscarNodo(raiz,clave);
		
		if(existe)
		{
			raiz=eliminarNodo(raiz,clave);
		}else
		{
			printf("\n LA clave ingresada no existe");
		}
		
		do
		{
			printf("\n Desea eliminar otra clave? (1. si, 0. no): ");
			scanf("%i",&opcion);
		}while(opcion<0 || opcion>1);
		
	}while(opcion!=0);
}

NodoArbol* crearNodo()
{
	NodoArbol* nodo;
	
	nodo=(NodoArbol*)malloc(sizeof(NodoArbol));
	nodo->der=NULL;
	nodo->izq=NULL;
	
	return nodo;
}

int buscarNodo(NodoArbol* arbol, int k)
{
	NodoArbol* aux;
	int enc;
	
	enc=0;
	
	if(arbol==NULL)
	{
		return 0;
	}else
	{
		aux=arbol;
		while(enc==0 && aux!=NULL)
		{
			if(aux->dato==k)
			{
				enc=1;
			}else
			{
				if(k < aux->dato)
				{
					if(aux->izq==NULL)
					{
						aux=NULL;
					}else
					{
						aux=aux->izq;
					}
				}else
				{
					if(aux->der==NULL)
					{
						aux=NULL;
					}else
					{
						aux=aux->der;
					}
				}
			}
		}
		return enc;
	}	
}

NodoArbol* eliminarNodo(NodoArbol* arbol,  int k)
{
	NodoArbol* aux;
	NodoArbol* aux2;
	
	aux=arbol;
	
	while(aux!=NULL)
	{
		if(k < aux->dato)
		{
			aux2=aux;
			aux=aux->izq;
		}else
		{
			if(k > aux->dato)
			{
				aux2=aux;
				aux=aux->der;
			}else
			{
				if(aux->izq==NULL && aux->der==NULL)
				{
					if(aux2->izq==aux)
					{
						aux2->izq=NULL;
					}else
					{
						aux2->der=NULL;
					}
					
					free(aux);
					aux=NULL;
				}else
				{
					if(aux->izq==NULL || aux->der==NULL)
					{
						if(aux->izq!=NULL)
						{
							if(aux2->izq==aux)
							{
								aux2->izq=aux->izq;
								aux->izq=NULL;
							}else
							{
								aux2->der=aux->izq;
								aux->izq=NULL;
							}
						}else
						{
							if(aux2->izq==aux)
							{
								aux2->izq=aux->der;
								aux->der=NULL;
							}else
							{
								aux2->der=aux->der;
								aux->der=NULL;
							}
						}
						free(aux);
						aux=NULL;
					}
				}
			}
		}
	}
	return arbol;
}
