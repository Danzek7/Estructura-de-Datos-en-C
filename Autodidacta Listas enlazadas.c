#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	struct Nodo* ant;
	int num;
	struct Nodo* sig;
}Nodo;

Nodo* crearLista();
Nodo* crearNodo();
void mostrarLista(Nodo*);
void main(){
	Nodo* head;
	
	head=crearLista();

	mostrarLista(head);
}
Nodo* crearLista(){
	Nodo* nodo;
	Nodo* ini;
	Nodo* aux;
	int i;
	int tam;
	
	do{
		printf("Cuantos nodos va a tener la lista?: ");
		scanf("%i",&tam);
	}while(tam<=0);	
	ini=NULL;
	
	for(i=1;i<=tam;i++){
		nodo=crearNodo();
		printf("\nEl nodo %i sera igual a: ",i);
		scanf("%i",&nodo->num);
		if(ini==NULL){
			ini=nodo;
			aux=ini;
		}else{
			aux->sig=nodo;
			nodo->ant=aux;
			aux=nodo;
		}
	}
	nodo=NULL;
	aux=NULL;
	return ini;
}
Nodo* crearNodo(){
	Nodo* nuevo;
	nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->sig=NULL;
	return nuevo;
}
void mostrarLista(Nodo* ini){
	Nodo* aux;
	aux=ini;
	
	printf("\n");//leer los sucesores (del inicio al final)
	while(aux!=NULL){
		printf(" %i -->",aux->num);
		aux=aux->sig;
	}
	printf(" NULL");
}
