#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int valor;
	struct Nodo* sig;
}Nodo;

Nodo* crearNodo();
Nodo* empilar(Nodo*,Nodo*);

void main(){
	Nodo* nuevo;
	Nodo* tope;
	int i;
	int cant;
	
	do{
		printf("Ingrese el tamanio de la pila: ");
		scanf("%i",&cant);
	}while(cant<=0);
	
	for(i=1;i<=cant;i++){
		nuevo=crearNodo();
		tope=empilar(nuevo,tope);
	}
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	printf("\nEl valor del nuevo nodo es: ",);
	scanf("%i",&nodo->valor);
	nodo->sig=NULL;
	return nodo;
}

Nodo* empilar(Nodo* nuevo, Nodo* tope){
	nuevo->sig=tope;
	tope=nuevo;
	nuevo=NULL;
	
	return tope;
}
