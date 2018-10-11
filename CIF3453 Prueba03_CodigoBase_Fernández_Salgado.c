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

int sucesorInOrden(NodoArbol*,int);
int abbDegenerado(NodoArbol*);
int diferenciaExtremos(NodoArbol*);


void main ()
{
	NodoArbol* raiz;
	int deg;
	int dif;
	int clave;
	int suc;
	
	printf("Creacion del Arbol Binario de Busqueda (ABB) \n");
	
	raiz=crearABB();
	deg=0;
	
	printf("\n Ingrese la clave a evaluar: ");
	scanf("%i",&clave);
	
	suc=sucesorInOrden(raiz,clave);
	
	if(suc==0)
	{
		printf("\n El valor ingresado no existe");
	}else
	{
		printf("\n El sucesor in orden de la clave ingresada es: %i",suc);
	}
	
	deg=abbDegenerado(raiz);
	
	if(deg==0)
	{
		printf("\n No existe el arbol");
	}else
	{
		if(deg==1)
		{
			printf("\n No es un arbol degenerado");
		}
		if(deg==2)
		{
			printf("\n Es un arbol degenerado a la IZQUIERDA");
		}
		if(deg==3)
		{
			printf("\n Es un arbol degenerado a la DERECHA");
		}
		if(deg==4)
		{
			printf("\n Es un arbol degenerado MIXTO");
		}
	}
	
	dif=diferenciaExtremos(raiz);
	
	if(raiz==NULL)
	{
		printf("\n El arbol esta vacio");
	}else
	{
		printf("\n La diferencia de los valores es: %i",dif);
	}
	
	
}

//Responda desde aquí

int sucesorInOrden(NodoArbol* T ,int k)
{
	NodoArbol* aux;
	NodoArbol* aux2;
	int enc;
	int dato;
	
	
	if(T==NULL)
	{
		dato=0;
	}else
	{
		aux2=T;
		aux=aux2;
		enc=0;
		dato=0;
		
		while(aux!=NULL && enc!=1)
		{
			if(k == aux2->dato)
			{
				enc=1;
				
				if(aux2->der!=NULL)
				{
					dato=aux2->der->dato;
				}else
				{
					dato=0;
				}
			}else
			{
				if(k < aux2->dato)
				{
					aux2=aux;
					aux=aux->izq;
				}else
				{
					if(k > aux2->dato)
					{
						aux2=aux;
						aux=aux->der;
					}else
					{
						aux=NULL;
					}
				}
			}
		}
	}
	return dato;
}

int abbDegenerado(NodoArbol* T)
{
	NodoArbol* aux;
	int izq;
	int der;
	int no;
	int mix;
	
	no=0;
	izq=0;
	der=0;
	
	if(T==NULL)
	{
		mix=0;
	}else
	{
		aux=T;
		while(aux!=NULL && no==0)
		{
			if(aux->der!=NULL && aux->izq!=NULL)
			{
				no=1;
			}else
			{
				if(aux->der==NULL && aux->izq==NULL)
				{
					aux=NULL;
				}else
				{
					if(aux->der==NULL || aux->izq==NULL)
					{
						if(aux->der==NULL)
						{
							aux=aux->izq;
							izq=1;
						}else
						{
							aux=aux->der;
							der=1;
						}
					}
				}
			}	
		}
		
		if(no)
		{
			mix=1;
		}else
		{
			if(der==1 && izq==1)
			{
				mix=4;
			}else
			{
				if(izq==0 || der==0)
				{
					if(der==0)
					{
						mix=2;
					}else
					{
						mix=3;
					}
				}
			}
		}
	}
	return mix;
}

int diferenciaExtremos(NodoArbol* T)
{
	NodoArbol* aux;
	NodoArbol* aux2;
	int menor;
	int mayor;
	int dif;
	
	
	if(T==NULL)
	{
		return 0;
	}else
	{
		aux=T;
		aux2=aux;
		
		while(aux!=NULL)
		{
			if(aux->izq!=NULL)
			{
				aux=aux->izq;
			}else
			{
				menor=aux->dato;
				aux=NULL;
			}
		}
		while(aux2!=NULL)
		{
			if(aux2->der!=NULL)
			{
				aux2=aux2->der;
			}else
			{
				mayor=aux2->dato;
				aux2=NULL;
			}
		}
		dif=mayor-menor;
		
		return dif;
	}

}
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
