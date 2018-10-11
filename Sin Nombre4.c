#include <stdio.h>
#include <stdlib.h>
#define tam 3

typedef struct Nodo{
	struct Nodo* ant;
	int info;
	struct Nodo* suc;
}Nodo;

Nodo* crearLista();
Nodo* crearNodo();
void mostrarLista(Nodo*);

void main(){
	Nodo* ini;
	ini=crearLista();
	mostrarLista(ini);
}

Nodo* crearLista(){
	Nodo* nuevo;
	Nodo* head;
	Nodo* aux;
	int i;
	
	head=NULL;
	
	for(i=0;i<tam;i++){
		nuevo=crearNodo();
		printf("\nEl valor del nuevo nodo sera: ");
		scanf("%i",&nuevo->info);
		if(head==NULL){
			head=nuevo;
			aux=head;
		}else{
			aux->suc=nuevo;
			nuevo->ant=aux;
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
	nodo->ant=NULL;
	nodo->suc=NULL;
	return nodo;
}
void mostrarLista(Nodo* ini){
	Nodo* aux;
	aux=ini;
	printf("\n");
	while(aux!=NULL){
		printf(" %i -->",aux->info);
		aux=aux->suc;
	}
	printf(" NULL");
}
