#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	struct Nodo* ant;
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* crearListaEnlazadaDoblementeCircular();
Nodo* crearNodo();
void mostrarLista(Nodo*,Nodo*);
Nodo* eliminarNodo(Nodo*,Nodo*);

void main(){
	Nodo* ini;
	Nodo* fin;
	
	ini=crearListaEnlazadaDoblementeCircular();
	fin=ini;
	
	while(fin->sig!=NULL){
		fin=fin->sig;
	}
	mostrarLista(ini,fin);
	ini=eliminarNodo(ini,fin);
}

Nodo* crearListaEnlazadaDoblementeCircular(){
	Nodo* nuevo;
	Nodo* head;
	Nodo* aux;
	int i;
	int cant;
	
	head=NULL;
	
	do{
		printf("Cuantos nodos quiere anadir a la lista?: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	for(i=1;i<=cant;i++){
		nuevo=crearNodo();
		printf("\nEL valor del nodo nro %i sera: ",i);
		scanf("%i",&nuevo->dato);
		if(head==NULL){
			head=nuevo;
			aux=head;
		}else{
			aux->sig=nuevo;
			nuevo->ant=aux;
			aux=nuevo;
		}
	}
	nuevo=NULL;
	aux=NULL;
	return head;
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->ant=NULL;
	nodo->sig=NULL;
	return nodo;
}

void mostrarLista(Nodo* ini, Nodo* fin){
	Nodo* aux;
	aux=ini;
	printf("\n");
	while(aux!=NULL){
		printf("<-- %i -->",aux->dato);
		aux=aux->sig;
	}
}

Nodo* eliminarNodo(Nodo* ini ,Nodo* fin){
	Nodo* aux;
	Nodo* aux2;
	int valor;
	int encontrado;
	
	aux=ini;
	encontrado=0;
	
	printf("\nQue valor desea eliminar?: ");
	scanf("%i",&valor);
	
	do{
		if(aux->dato==valor){
			encontrado=1;
		}else{
			aux=aux->sig;
		}
	}while(encontrado==0);
	
	if(encontrado==0){
		printf("\nNo existe el nodo que esta buscando: ");
	}else{
		if(aux==ini){
			if(aux==fin){
				ini=NULL;
				fin=NULL;
				free(aux);
				aux=NULL;
			}else{
				ini=aux->sig;
				ini->ant=NULL;
				aux->sig=NULL;
				free(aux);
				aux=NULL;
			}
		}else{
			if(aux==fin){
				fin=aux->ant;
				fin->sig=NULL;
				aux->ant=NULL;
				free(aux);
				aux=NULL;
			}else{
				aux2=aux->ant;
				aux2->sig=aux->sig;
				aux2=aux->sig;
				aux2->ant=aux->ant;
				aux->ant=NULL;
				aux->sig=NULL;
				free(aux);
				aux=NULL;
			}
		}
	}
	return ini;
}
