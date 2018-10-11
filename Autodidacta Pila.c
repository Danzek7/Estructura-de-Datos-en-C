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
	int cant;
	int i;
	
	do{
		printf("La cantidad de nodos de la pila es: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	tope=NULL;
	
	for(i=1;i<=cant;i++){
		p=crearNodo();
		printf("\nEl valor del nuevo nodo es: ");
		scanf("%i",&p->dato);
		tope=empilar(p,tope);
	}
	
	mostrar(tope);
}

Nodo* empilar(Nodo* p, Nodo* tope){
	p->sig=tope;
	tope=p;
	p=NULL;
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
