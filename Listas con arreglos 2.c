#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}NodoLista;

void crearVectorLista(NodoLista*[],int);
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
	int i;
	int j;
	NodoLista* head;
	NodoLista* aux;
	NodoLista* nuevo;
	
	for(i=1;i<=n;i++){
		do{
			printf("\nCuantos nodos quiere que tenga la lista del arreglo arreglo [%i]?: ",i);
			scanf("%i",&tam);
		}while(tam<=0);
		
		head=NULL;
		
		for(j=1;j<=tam;j++){
			nuevo=crearNodo();
			if(head==NULL){
				head=nuevo;
				aux=head;
			}else{
				aux->sig=nuevo;
				aux=aux->sig;
			}
		}
		v[i]=head;
	}
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
	int i;
	
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
