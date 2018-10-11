#include <stdio.h>
#include <stdlib.h>

typedef struct NodoEq
{
	struct NodoEq* izq;
	int dato;
	struct NodoEq* der;
}NodoEq;

NodoEq* crearArbol(NodoEq* );
NodoEq* crearNodo();

void main()
{
	NodoEq* arbol;
	int existe;
	int clave;
	int op;
	
	arbol=crearArbol(arbol);
	
	while(aux!=NULL)
	{
		
	}	
}

NodoEq* crearArbol(NodoEq* raiz)
{
	NodoEq* aux;
	NodoEq* nodo;
	int op;
	
	raiz=NULL;
	
	do
	{
		nodo=crearNodo();
		
		printf("\n El valor del nuevo nodo es: ");
		scanf("%i",&nodo->dato);
		
		if(raiz==NULL)
		{
			raiz=nodo;
			aux=raiz;
		}else
		{
			aux=raiz;
			
			while(aux!=NULL)
			{
				if(nodo->dato < aux->dato)
				{
					if(aux->izq==NULL)
					{
						aux->izq=nodo;
						aux=NULL;
					}else
					{
						aux=aux->izq;
					}
				}else
				{
					if(aux->der==NULL)
					{
						aux->der=nodo;
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
			printf("\n ---Desea seguir agregando nodos?: 1.si, 0.no : ");
			scanf("%i",&op);
		}while(op<0 || op>1);
	}while(op);
	
	return raiz;
}

NodoEq* crearNodo()
{
	NodoEq* nodo;
	nodo=(NodoEq*)malloc(sizeof(NodoEq));
	nodo->der=NULL;
	nodo->izq=NULL;
	return nodo;
}
