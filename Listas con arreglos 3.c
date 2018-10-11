#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}NodoLista;

void crearVectorLista(NodoLista*[],int);
NodoLista* crearLista(int);
NodoLista* crearNodo();
void mostrarVectorLista(NodoLista*[],int);
void eliminarVectorLista(NodoLista*[],int);

void main(){
	int cant;
	int res;
	
	do{
		printf("Ingrese el tamanio del vector: ");
		scanf("%i",&cant);
	}while(cant<=0);
	
	NodoLista* vec[cant];
	
	crearVectorLista(vec,cant);
	mostrarVectorLista(vec,cant);
	
	do{
		printf("\nDesea eliminar el vector de una lista (1:si; 0:no)?: ");
		scanf("%i",&res);
	}while((res<0)&&(res>=2));
	
	if(res==0){
		printf("\nMuchas Gracias.");
	}else{
		eliminarVectorLista(vec,tam);
	}
}

void eliminarVectorLista(NodoLista* v[],int n){
	NodoLista* del;
	NodoLista* head;
	int des;
	int i;
	
	head=NULL;
	
	do{
		printf("\nCual es el vector que desea eliminar?: ");
		scanf("%i",&des);
	}while((des<=0)&&(des>n));
	
	for(i=0;i<n;i++){
		if(head==NULL){
			head=v[i];
			if(i+1==des){
			    head=del->sig;
			    free(del);
			    del=NULL;
			}else{
				
			}
		}
	}
}

void crearVectorLista(NodoLista* v[], int n){
	NodoLista* aux;
	NodoLista* aux2;
	int tam;
	int i;
	
	aux=NULL;
	
	for(i=1;i<=n;i++){
		do{
			printf("\nCuantos nodos quiere que tenga la lista del arreglo arreglo [%i]?: ",i);
			scanf("%i",&tam);
		}while(tam<=0);
		v[i]=crearLista(tam);
		if(aux==NULL){
			aux=v[i];
		}
	}
}

NodoLista* crearLista(int tam){
	NodoLista* nuevo;
	NodoLista* aux;
	NodoLista* head;
	int i;
	
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
	int i;
	
	printf("\n");
	printf("Vector de listas: ");
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
