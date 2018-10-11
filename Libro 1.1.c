#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	int dato;
	struct Lista* sig;
}Nodo;

Nodo* crearLista();
Nodo* crearNodo();

void main(){
	Nodo* head;
	int op;
	
	head=crearLista();
	
	do{
		do{
			printf("\n Que hacer?:\n1.Agregar\n2.Eliminar\n3.Quit\nR: ");
			scanf("%i",&op);
		}while(op<1 || op>3);
	}while(op!=3);
}

Nodo* crearLista(){
	Nodo* nuevo;
	Nodo* head;
	Nodo* aux;
	
	head=NULL;
	
	do{
		nuevo=crearNodo();
		printf("\n Nuevo nodo de la lista: ");
		scanf("%i",&nuevo->dato);
		if(head==NULL){
			head=nuevo;
			aux=head;
		}else{
			aux->sig=nuevo;
			aux=nuevo;
		}
	}
	aux=NULL;
	nuevo=NULL;
	
	return head;
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	return nodo;
}
