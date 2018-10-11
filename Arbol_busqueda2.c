#include <stdio.h>
#include <stdlib.h>

typedef struct NodoBusqueda
{
	struct NodoBusqueda* izq;
	int dato;
	struct NodoBusqueda* der;
}NodoAB;

NodoAB* ingresarNodos(NodoAB* );
int buscarNodo(NodoAB* , int );
NodoAB* eliminarNodos(NodoAB* , int );
NodoAB* crearNodo();

void main()
{
	NodoAB* raiz;
	int op;
	int check;
	int clave; 
	
	raiz=ingresarNodos(raiz);
	
	printf("\n\n --- \n Eliminar Nodos: ");
	
	do
	{
		printf("\n Ingrese el numero de la clave a eliminar: ");
		scanf("%i",&clave);
		
		check=buscarNodo(raiz,clave);
		
		if(check)
		{
			raiz=eliminarNodos(raiz,clave);
		}else
		{
			printf("\n LA clave ingresada no existe");
		}
		
		do
		{
			printf("\n  Desea seguir eliminando nodos? (1.si , 0.no): ");
			scanf("%i",&op);
		}while(op<0 || op>1);
		
	}while(!op);
}

int buscarNodo(NodoAB* raiz, int k)
{
	int enc;
	NodoAB* aux;
	
	enc=0;
	
	if(raiz==NULL)
	{
		enc=0;
	}else
	{
		aux=raiz;
		while(aux!=NULL && !enc)
		{
			if(k == aux->dato)
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

NodoAB* ingresarNodos(NodoAB* raiz)
{
	NodoAB* nodo;
	NodoAB* aux;
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
			printf("\n ---Desea seguir implementando nodos al arbol? (1.si, 0.no): ");
			scanf("%i",&op);
		}while(op<0 || op>1);
	}while(op!=0);
	
	return raiz;
}

NodoAB* eliminarNodos(NodoAB* raiz, int k)
{
	NodoAB* aux;
	NodoAB* aux2;
	
	aux=raiz;
	
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
						if(aux->der==NULL)
						{
							if(aux2->izq==aux)
							{
								aux2->izq=aux->izq;
								aux->izq=NULL;
							}else{
								aux2->der=aux->izq;
								aux->izq=NULL;
							}
						}else
						{
							if(aux2->der==aux)
							{
								aux2->der=aux->der;
								aux->der=NULL;
							}else
							{
								aux2->izq=aux->der;
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
	return raiz;
}

NodoAB* crearNodo()
{
	NodoAB* nodo;
	nodo=(NodoAB*)malloc(sizeof(NodoAB));
	nodo->der=NULL;
	nodo->izq=NULL;
	return nodo;
}
