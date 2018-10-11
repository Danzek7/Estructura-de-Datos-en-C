#include <stdio.h>
#include <stdlib.h>

typedef struct NodoDoble
{
	struct NodoDoble* ant; //anterior
	int info;
	struct NodoDoble* suc; //sucesor
}NodoDoble;

NodoDoble* crearNodoDoble();
NodoDoble* crearListaDoble();
void mostrarListaDoble(NodoDoble*);
void mostrarListaAlReves(NodoDoble*);
NodoDoble* eliminarNodoDoble(NodoDoble*,NodoDoble*);

void main ()
{
	int cantNodos;
	NodoDoble* inicio;
	NodoDoble* fin;
		
	inicio=crearListaDoble();
	fin=inicio;
		
	while(fin->suc!=NULL)
	{
		fin=fin->suc;	
	}
	mostrarListaDoble(inicio);
	
	printf("\n");	
	mostrarListaAlReves(fin);
	
	inicio=eliminarNodoDoble(inicio,fin);
	
	//Luego de eliminar un nodo la lista puede quedar vac?a
	//por lo que al tratar de mostrarla ocasiona un error.
	//Opci?n: modificar la funci?n mostrarListaDoble()
	 
	if(inicio != NULL)  
		mostrarListaDoble(inicio);
	else
		printf("La lista se encuentra vacia");
}


NodoDoble* crearNodoDoble()
{
	NodoDoble* nuevo;
	nuevo=(NodoDoble*)malloc(sizeof(NodoDoble));
	nuevo->ant=NULL;
	nuevo->suc=NULL;
	
	return nuevo;	
}

NodoDoble* crearListaDoble(){
	
	NodoDoble* nodo;
	NodoDoble* ini;
	NodoDoble* aux;
	int cantNodos;
	int i;
	
	do
	{
		printf("Ingrese la cantidad de nodos que quiere para su lista: ");
		scanf("%i",&cantNodos);	
	}while(cantNodos<=0);
	
	ini=NULL;
	
	for(i=1; i<=cantNodos; i++)
	{
		nodo=crearNodoDoble();
		printf("\nIngrese un valor para el nodo %i :",i);
		scanf("%i",&nodo->info);
		
		if(ini==NULL)
		{
			ini=nodo;
			aux=ini;
		}
		else
		{
			aux->suc=nodo;
			nodo->ant=aux;
			aux=nodo;
		}
	}
	
	nodo=NULL;
	aux=NULL;
	
	return ini;
}


void mostrarListaDoble(NodoDoble* ini) //En esta funci?n se puede verificar que la lista no est? vac?a
{
	NodoDoble*aux;
	
	aux=ini;
		
	do
	{
		printf(" %i --> ",aux->info);
		aux=aux->suc;
	}while(aux!=NULL);
		
	printf("NULL");
}


void mostrarListaAlReves(NodoDoble* fin) //Idem caso anterior
{
	NodoDoble* aux;
	
	aux=fin;	
	do
	{	
		printf(" %i --> ",aux->info);
		aux=aux->ant;
	}while(aux!=NULL);
	
	printf("NULL");
}


NodoDoble* eliminarNodoDoble(NodoDoble* ini, NodoDoble* fin) //Falta considerar la opci?n de que se reciba una
{															 //lista vac?a.
	NodoDoble*aux;
	NodoDoble*aux2;
	int valor;
	int encontrado;
	
	aux=ini;
	
	printf("\nIngrese el  valor del nodo a eliminar: ");
	scanf("%i",&valor);
	
	encontrado=0;
	
	do
	{
		if(aux->info == valor)
		{
			encontrado=1;				
		}
		else
		{
			aux=aux->suc;		
		}
	}while(encontrado==0 && aux!=NULL);
	
		
	if(encontrado==0)
	{
		printf("No existe un nodo con el valor ingresado\n");
	}
	else
	{
		if(aux == ini)
		{
			if(aux == fin) //Caso de lista con un nodo. inicio y fin apuntan al mismo nodo.
			{
				ini=NULL;
				fin=NULL;
				free(aux);
				aux=NULL;	
			}
			else
			{
				ini=aux->suc;
				ini->ant=NULL;
				aux->suc=NULL;
				free(aux);
				aux=NULL;	
			}
					
		}
		else //else agregado
			if(aux == fin)
			{
				fin=aux->ant;
				fin->suc=NULL;
				aux->ant=NULL;
				free(aux);
				aux=NULL;
			}
			else  //corresponde a if(aux!= ini & aux!= fin)
			{
				aux2=aux->ant;
				aux2->suc=aux->suc;
				aux2=aux->suc;
				aux2->ant=aux->ant;
				aux->suc=NULL;
				aux->ant=NULL;
				free(aux);
				aux=NULL;
			}
	}
	return ini;
}
