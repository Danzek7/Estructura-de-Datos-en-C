#include <stdio.h>
#include <stdlib.h>
#define tam 2
typedef struct Nodo{
	struct Nodo* ant;
	int dato;
	struct Nodo* sig;
}Nodo;
Nodo* crearLista();
Nodo* crearNodo();
void mostrarLista(Nodo*,Nodo*);
void main(){
	Nodo* ini;
	Nodo* fin;
	ini=crearLista();
	fin=ini;
	while(fin->sig!=NULL){
		fin=fin->sig;
	}
	mostrarLista(ini,fin);
}
Nodo* crearLista(){
	Nodo* nuevo;
	Nodo* aux;
	Nodo* head;
	int i;
	head=NULL;
	for(i=1;i<=tam;i++){
		nuevo=crearNodo();
		printf("\nEl nuevo nodo sera: ");
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
void mostrarLista(Nodo* ini ,Nodo* fin){
	Nodo* aux;
	aux=ini;
	printf("\n");
	while(aux!=NULL){
		printf(" %i -->",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL");
}
