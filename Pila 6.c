#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* crearNodo();
Nodo* empilar(Nodo* , Nodo* );
void mostrarPila(Nodo* );

void main(){
	Nodo* p;
	Nodo* tope;
	int i;
	int cant;
	
	tope=NULL;
	
	do{
		printf("Ingrese la cantidad de nodos que desea agregar: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	for(i=1;i<=cant;i++){
		p=crearNodo();
		
		printf("\n--El nodo %i es igual a: ",i);
		scanf("%i",&p->dato);
		
		tope=empilar(p,tope);
	}
	
	mostrarPila(tope);
}

Nodo* empilar(Nodo* p, Nodo* tope){
	p->sig=tope;
	tope=p;
	p=NULL;
	
	return tope;
}

Nodo* crearNodo(){
	Nodo* aux;
	
	aux=(Nodo*)malloc(sizeof(Nodo));
	aux->sig=NULL;
	
	return aux;
}

void mostrarPila(Nodo* tope){
	Nodo* aux;
	
	aux=tope;
	
	printf("\n");
	while(aux!=NULL){
		printf(" %i\n _ \n",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL");
}
