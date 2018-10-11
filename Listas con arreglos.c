#include <stdio.h>
#include <stdlib.h>

int i;

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}NodoLista;

void crearVectorLista(NodoLista*[],int);
NodoLista* crearLista(int);
NodoLista* crearNodo();
void mostrarVectorLista(NodoLista*[],int);

void main(){
	int cant;
	
	do{
		printf("Ingrese el tamanio del vector: ");
		scanf("%i",&cant);
	}while(cant<=0);
	
	NodoLista* vec[cant];
	
	crearVectorLista(vec,cant);
	mostrarVectorLista(vec,cant);
}

void crearVectorLista(NodoLista* v[], int n){
	int tam;
	
	for(i=1;i<=n;i++){
		do{
			printf("\nCuantos nodos quiere que tenga la lista del arreglo arreglo [%i]?: ",i);
			scanf("%i",&tam);
		}while(tam<=0);
		v[i]=crearLista(tam);
	}
}

NodoLista* crearLista(int tam){
	NodoLista* nuevo;
	NodoLista* aux;
	NodoLista* head;
	
	head=NULL;
	
	for(i=1;i<=tam;i++){
		nuevo=crearNodo();
		if(head==NULL){
			head=nuevo;
			aux=head;
		}else{
			aux->sig=nuevo;
			aux=nuevo;
		}
	}
	
	aux=NULL;
	nuevo=NULL;
	
	return head;
}

NodoLista* crearNodo(){
	NodoLista* nodo;
	
	nodo=(NodoLista*)malloc(sizeof(NodoLista));
	
	printf("\n----------------valor del nuevo nodo: ");
	scanf("%i",&nodo->dato);
	
	nodo->sig=NULL;
	
	return nodo;
}

void mostrarVectorLista(NodoLista* v[], int n){
	NodoLista* aux;
	
	printf("\n");
	
	for(i=0;i<n;i++){
		printf("\nV[%i]===> ",i);
		aux=v[i];
		
		while(aux!=NULL){
			printf(" %i--> ",aux->dato);
			aux=aux->sig;
		}
		
		printf(" NULL");
	}
}
