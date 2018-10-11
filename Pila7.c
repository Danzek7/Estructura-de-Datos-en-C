#include <stdio.h>
#include <stdlib.h>

typedef struct NodoPila{
	int dato;
	struct NodoPila* sig;
}NodoPila;

NodoPila* crearNodo();
NodoPila* empilar(NodoPila* , NodoPila* );
void mostrarPila(NodoPila* );

void main(){
	NodoPila* tope;
	NodoPila* p;
	int cant;
	int i;
	
	do{
		printf("Ingrese la cantidad de nodos de la pila: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	tope=NULL;
	
	for(i=1;i<=cant;i++){
		p=crearNodo();
		printf("\n--El valor del nodo %i es: ",i);
		scanf("%i",&p->dato);
		tope=empilar(tope,p);
	}
	
	mostrarPila(tope);
}

void mostrarPila(NodoPila* tope){
	NodoPila* aux;
	aux=tope;
	printf("\n");
	while(aux!=NULL){
		printf(" %i\n _\n",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL");
}

NodoPila* empilar(NodoPila* tope, NodoPila* p){
	p->sig=tope;
	tope=p;
	p=NULL;
	return tope;
}

NodoPila* crearNodo(){
	NodoPila* nodo;
	nodo=(NodoPila*)malloc(sizeof(NodoPila));
	nodo->sig=NULL;
	return nodo;
}
