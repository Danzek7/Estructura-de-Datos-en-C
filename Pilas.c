#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* crearNodo();
Nodo* empilar(Nodo*,Nodo*); //(nodo*,nodo*)= pila, que será el tope 
Nodo* desempilar(Nodo*);
int pilaVacia(Nodo*);
void mostrarPila(Nodo*,Nodo*);

void main(){
	Nodo* tope;
	Nodo* pila1;
	Nodo* pila2;
	Nodo* nodo;
	Nodo* head;
	Nodo* aux;
	Nodo* aux2;
	int cant;
	int i;
	
	head=NULL;
	
	do{
		printf("Ingrese la cantidad de elementos de la pila: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	for(i=1;i<=cant;i++){
		nodo=crearNodo(); 
		printf("\nEl nodo %i sera igual a: ",i);
		scanf("%i",&nodo->info);
		tope=nodo;
		if(head==NULL){
			head=nodo;
			aux=head;
			pila1=empilar(tope,aux);
			pila2=pila1;
			pila2->sig=pila1; 
		}else{  
			aux->sig=nodo; 
			aux=nodo;
			aux2=aux;
			pila2=empilar(tope,aux); 
		}		
	}
	nodo=NULL;
	aux=NULL;
	
	mostrarPila(nodo,pila);
}

Nodo* empilar(Nodo* nodo, Nodo* tope){
    Nodo* head;
    Nodo* aux;
    Nodo* aux2;
    Nodo* aux3;
    Nodo* nuevo;
    
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	return nodo;
}

void mostrarPila(Nodo* nodo ,Nodo* pila){
	Nodo* aux;
	
	aux=nodo;
	
	printf("\n");
	while(aux!=NULL){
		printf(" %i -->",&aux->dato);
		aux=aux->sig;
	}
}
