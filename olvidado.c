#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* empilar(Nodo* , Nodo* );
Nodo* crearNodo();
void mostrar(Nodo* );

void main(){
	Nodo* tope;
	Nodo* p;
	Nodo* nuevo;
	int i;
	
	tope=NULL;
	
	for(i=1;i<4;i++){
		nuevo=crearNodo();
		printf("\nEl nodo %i es igual a: ",i);
		scanf("%i",&nuevo->dato);
		p=nuevo;
		tope=empilar(p,tope);
	}
	mostrar(tope);
}

Nodo* empilar(Nodo* p, Nodo* tope){
	p->sig=tope;
	tope=p;
	return tope;
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	return nodo;
}

void mostrar(Nodo* tope){
	Nodo* aux;
	aux=tope;
	printf("\n");
	while(aux!=NULL){
		printf(" %i\n _\n",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL");
}
