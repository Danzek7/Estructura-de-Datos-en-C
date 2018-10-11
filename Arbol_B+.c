#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol
{
	int dato1;
	int dato2;
	int dato3;
	struct NodoArbol* d1;
	struct NodoArbol* d2;
	struct NodoArbol* d3;
	struct NodoArbol* siguiente;
}NodoArbol;

NodoArbol* crearArbol(NodoArbol* );
NodoArbol* crearNodo();

void main()
{
	NodoArbol* raiz;
	
	raiz=crearArbol(raiz);
	
}

NodoArbol* crearArbol(NodoArbol* raiz)
{
	NodoArbol* aux;
	NodoArbol* nodo;
	NodoArbol* d1;
	NodoArbol* d2;
	NodoArbol* d3;
	NodoArbol* sig;
	int punt;
	int dato;
	int cont;
	int op;
	
	raiz=NULL;
	cont=0;
	
	do
	{
		nodo=crearNodo();
		
		printf("\n Ingrese el valor del nuevo dato ingresado: ");
		scanf("%i",&dato);
				
	
		if(raiz==NULL)
		{
			do
			{
				if(cont==0)
				{
					nodo->dato1=dato;
					cont++;
				}
				if(cont==1)
				{
					if(dato < nodo->dato1)
					{
						nodo->dato2=nodo->dato1;
						nodo->dato1=dato;
					}else
					{
						nodo->dato2=dato;
					}
					
					cont++;
				}
				if(cont==2)
				{
					if(dato < nodo->dato2)
					{
						if(dato < nodo->dato1)
						{
							nodo->dato3=nodo->dato2;
							nodo->dato2=nodo->dato1;
							nodo->dato1=dato;
						}
					}
					nodo->dato3=dato;
					cont++;
				}
			}while(cont<3);
		
			raiz=nodo;
			aux=raiz;
		}else
		{
			aux=raiz;
			
			if(aux->d1==NULL && aux->d2==NULL && aux->d3==NULL)
			{
				if(dato >= aux->dato3)
				{
					
				}
			}
		}
	}while(op);
}

NodoArbol* crearNodo()
{
	NodoArbol* nodo;
	
	nodo=(NodoArbol*)malloc(sizeof(NodoArbol));
	nodo->d1=NULL;
	nodo->d2=NULL;
	nodo->d3=NULL;
	nodo->siguiente=NULL;
	
	return nodo;
}
