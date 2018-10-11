#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* crearNodo();
Nodo* empilar();

void main(){
	Nodo* nodo;
	nodo=empilar();
}

Nodo* empilar(){
	Nodo* nodo;
	Nodo* inicio;
	Nodo* tope;
	Nodo* aux;
	int val;
	int i;
	
	inicio=NULL;
	tope=NULL;
	
	do{
		printf("De que tamanio quiere su pila?: ");
		scanf("%i",&val);
	}while(val<=0);
	
	for(i=1;i<=val;i++){
		if(inicio==NULL){
			nodo=crearNodo();
			inicio=nodo;
			aux=inicio;
			aux->sig=tope;
		}else{
			nodo=crearNodo();
			tope=nodo;
			aux=tope;
		}
	}
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	int val;
	
	printf("\nEl valor del nuevo nodo es: ");
	scanf("%i",&val);
	
	nodo->dato=val;
	nodo->sig=NULL;
	
	return nodo;
}
