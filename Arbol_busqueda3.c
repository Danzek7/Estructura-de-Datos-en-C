#include <stdio.h>
#include <stdlib.h>

typedef struct NodoSearch
{
	struct NodoSearch* izq;
	int dato;
	struct NodoSearch* der;
}Nodo;

Nodo* crearArbol(Nodo* );
Nodo* crearNodo();
int buscar(Nodo* , int);
Nodo* eliminar(Nodo* , int );

void main()
{
	Nodo* raiz;
	int op;
	int enc;
	int clave;
	
	raiz=NULL;
	
	raiz=crearArbol(raiz);
	
	do
	{
		printf("\n Ingrese la clave que desea eliminar: ");
		scanf("%i",&clave);
		
		enc=buscar(raiz,clave);
		
		if(enc)
		{
			raiz=eliminar(raiz,clave);
		}else
		{
			printf("\n La clave ingresada no existe");
		}
		
		do
		{
			printf("\n DEsea seguir eliminando nodos?: ");
			scanf("%i",&op);
		}while(op<0 || op>1);
		
	}while(op!=0);
}

Nodo* eliminar(Nodo* arbol, int k)
{
	Nodo* aux;
	Nodo* aux2;
	Nodo* auxNu;
	
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
						if(aux->izq==NULL)
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
						}else
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
						}
						free(aux);
						aux=NULL;
					}else
					{
						if(aux2->der==aux)
						{
							if(aux->der!=NULL)
							{
								auxNu=aux->der;
								
								if(auxNu->izq==NULL && auxNu->der==NULL)
								{
									aux2->der=auxNu;
									aux->der=NULL;
									auxNu->izq=aux->izq;
									aux->izq=NULL;
								}else
								{
									if(auxNu->izq==NULL || auxNu->der==NULL)
									{
										if(auxNu->izq==NULL)
										{
											aux2->der=auxNu;
											aux->der=NULL;
											auxNu->izq=aux->izq;
											aux->izq=NULL;
										}else
										{
											aux2->der=auxNu;
											aux->der=NULL;
											auxNu->der=auxNu->izq;
											auxNu->izq=aux->izq;
											aux->izq=NULL;
										}
									}
								}
								free(aux);
								aux=NULL;
							}else
							{
								auxNu=aux->izq;
								aux2->der=auxNu;
								aux->izq=NULL;
								free(aux);
								aux=NULL;
							}	
						}else
						{
							if(aux->der!=NULL)
							{
								auxNu=aux->der;
								
								if(auxNu->izq==NULL && auxNu->der==NULL)
								{
									aux2->izq=auxNu;
									aux->der=NULL;
									auxNu->izq=aux->izq;
									aux->izq=NULL;
								}else
								{
									if(auxNu->izq==NULL || auxNu->der==NULL)
									{
										if(auxNu->izq==NULL)
										{
											aux2->izq=auxNu;
											aux->der=NULL;
											auxNu->izq=aux->izq;
											aux->izq=NULL;
										}else
										{
											aux2->izq=auxNu;
											aux->der=NULL;
											auxNu->der=auxNu->izq;
											auxNu->izq=aux->izq;
											aux->izq=NULL;
										}
									}
								}
								free(aux);
								aux=NULL;
							}else
							{
								auxNu=aux->izq;
								aux2->izq=auxNu;
								aux->izq=NULL;
								free(aux);
								aux=NULL;
							}
						}
					}
				}
			}
		}
	}
	return arbol;
}

int buscar(Nodo* T, int k)
{
	Nodo* aux;
	int enc;
	
	enc=0;
	
	if(T==NULL)
	{
		return 0;
	}else
	{
		aux=T;
		while(aux!=NULL)
		{
			if(k==aux->dato)
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

Nodo* crearArbol(Nodo* raiz)
{
	Nodo* nodo;
	Nodo* aux;
	int op;
	
	do
	{
		nodo=crearNodo();
		
		printf("\n Ingrese el nuevo nodo: ");
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
			printf("\n Desea seguir ingresando nodos al arbol: ");
			scanf("%i",&op);
		}while(op<0 || op>1);	
	}while(op!=0);
	
	return raiz;
}

Nodo* crearNodo()
{
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->izq=NULL;
	nodo->der=NULL;
	return nodo;
}
