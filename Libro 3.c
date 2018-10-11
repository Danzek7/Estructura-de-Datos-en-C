#include <stdio.h>
#include <stdlib.h>

typedef struct Cola{
	int dato;
	struct Cola* sig;
}Nodo;

Nodo* crearNodo();
Nodo* encolar();
void mostrarCola(Nodo* );

void main(){
	Nodo* front;
	
	front=encolar();
	
	mostrarCola(front);
}

Nodo* encolar(){
	Nodo* nodo;
	Nodo* front;
	Nodo* rear;
	int i;
	int tam;
	
	front=NULL;
	
	do{
		printf("\nIngrese el tamanio de la cola: ");
		scanf("%i",&tam);
	}while(tam<1);
	
	for(i=1;i<=tam;i++){
		nodo=crearNodo();
		printf("\n Nodo %i: ",i);
		scanf("%i",&nodo->dato);
		if(front==NULL){
			front=nodo;
			rear=front;
		}else{
			rear->sig=nodo;
			rear=nodo;
		}
	}
	rear=NULL;
	nodo=NULL;
	
	return front;
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	return nodo;
}

void mostrarCola(Nodo* frente){
	Nodo* aux;
	aux=frente;
	printf("\n");
	
	while(aux!=NULL){
		printf(" %i-->",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL");
}
