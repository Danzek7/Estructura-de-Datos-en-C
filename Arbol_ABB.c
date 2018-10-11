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
int buscarNodo(NodoEq* , int );
NodoEq* eliminarNodo(NodoEq* , int );
NodoEq* desempilar(NodoEq* , NodoEq* );

void main()
{
	NodoEq* raiz;
	NodoEq* aux;
	NodoEq* tope;
	int clave;
	int existe;
	int op;
	
	raiz=crearArbol(raiz);
	printf("\n Recorrido In-Orden: \n");
	aux=raiz;
	
	while(tope!=NULL)
	{
		while(aux!=NULL)
		{
			tope=aux;
			aux=aux->izq;
		}
		
		aux=tope;
		tope=desempilar(tope,raiz);
		printf("%i\n",aux->dato);
		aux=aux->der;
	}
	
	printf("\n Eliminar elementos: \n");
	
	do
	{
		printf("\nIngrese la clave que desea eliminar: ");
		scanf("%i",&clave);
		
		existe=buscarNodo(raiz,clave);
		
		if(existe)
		{
			raiz=eliminarNodo(raiz,clave);
		}else
		{
			if(raiz==NULL)
			{
				printf("\n EL arbol esta vacio");
			}else
			{
				printf("\n EL elemento seleccionado no existe");
			}
		}
		
		do
		{
			printf("\n Desea seguir eliminando elementos? (1.si,0.no): ");
			scanf("%i",&op);
		}while(op<0 || op>1);
		
	}while(op!=0);
}

NodoEq* desempilar(NodoEq* tope, NodoEq* raiz)
{	
	NodoEq* p;
	
	p=raiz;
	
	if(p==NULL)
	{
		tope=NULL;
	}else
	{
		while(p!=NULL)
		{
			if(tope->dato < p->dato)
			{
				if(p->izq == tope)
				{
					p->izq=NULL;
					tope=p;
					p=NULL;
				}else
				{
					p=p->izq;
				}
				
			}else
			{
				if(p->der == tope)
				{
					p->der=NULL;
					tope=p;
					p=NULL;
				}else
				{
					p=p->der;
				}
			}
		}
	}
	
	return tope;
}

//////
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
			printf("\n-- Desea seguir ingresando nodos al arbol? (1.si, 0.no): ");
			scanf("%i",&op);
		}while(op<0 || op>1);
		
	}while(op!=0);
	
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

int buscarNodo(NodoEq* arbol, int k)
{
	NodoEq* aux;
	int enc;
	
	aux=arbol;
	
	if(aux==NULL)
	{
		return 0;
	}else
	{
		enc=0;
		while(aux!=NULL && enc==0)
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

NodoEq* eliminarNodo(NodoEq* arbol, int k)
{
	NodoEq* aux;
	NodoEq* aux2;
	
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
				if(aux->der==NULL && aux->izq==NULL)
				{
					if(aux2->izq==aux)
					{
						aux2->izq=NULL;
					}else
					{
						aux2->der==NULL;
					}
					free(aux);
					aux=NULL;
				}else
				{
					if(aux->der==NULL || aux->izq==NULL)
					{
						if(aux->izq==NULL)
						{
							if(aux2->izq==aux)
							{
								aux2->izq=aux->der;
								aux->der==NULL;
							}else
							{
								aux2->der=aux->der;
								aux->der==NULL;
							}
						}else
						{
							if(aux2->izq==aux)
							{
								aux2->izq==aux->izq;
								aux->izq==NULL;
							}else
							{
								aux2->der=aux->izq;
								aux->izq==NULL;
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
