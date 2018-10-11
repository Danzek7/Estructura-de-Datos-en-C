#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	struct Nodo* ant;
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* crearLista();
Nodo* crearNodo();
void mostrarResultados(Nodo*,Nodo*);

void main(){
	Nodo* ini;
	Nodo* fin;
	int res;
	
	ini=crearLista();
	fin=ini;
	
	while(fin->sig!=NULL){
		fin=fin->sig;
	}
	
	printf("\n------------------------");
	do{
		printf("\nQue quiere hacer con la lista? (1.mostrarla ; 2.quitar un nodo ; 3.agregar un nodo): ");
		scanf("%i",&res);
	}while(res<1 && res>=4);
	
	switch(res){
		case 1:
			mostrarResultados(ini,fin);
			break;
		case 2:
			printf("\npronto");
			break;
		case 3:
			printf("\npronto");
			break;
    }
}

Nodo* crearLista(){
	Nodo* nuevo;
	Nodo* aux;
	Nodo* head;
	int res;
	
	head=NULL;
	
	do{
		nuevo=crearNodo();
		printf("\nEl valor contenido en el nuevo nodo es: ");
		scanf("%i",&nuevo->dato);
		if(head==NULL){
			head=nuevo;
			aux=head;
		}else{
			aux->sig=nuevo;
			nuevo->ant=aux;
			aux=nuevo;
		}
		do{
			printf("\n----------Quiere seguir añadiendo nodos a la lista? (1:si - 0:no): ");
			scanf("%i",&res);
		}while(res<0 && res>=2);
	}while(res==1);
	
	aux=NULL;
	nuevo=NULL;
	return head;
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	nodo->ant=NULL;
	return nodo;
}

void mostrarResultados(Nodo* ini, Nodo* fin){
	Nodo* aux;
	
	aux=ini;
	printf("\nLista:");
	printf("\n");
	
	while(aux!=NULL){
		printf(" %i -->",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL");
	
	aux=fin;
	printf("\nLista al reves: ");
    printf("\n");
	
	while(aux!=NULL){
		printf(" %i -->",aux->dato);
		aux=aux->ant;
	}
	printf(" NULL");
}
