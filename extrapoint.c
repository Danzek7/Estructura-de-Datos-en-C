#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
	int dato;
	struct Nodo* sig;
	
}NodoLista;

void crearVectorLista(NodoLista* [], int ); 
NodoLista* crearNodo();


void main(){
	int n;
	n=3;
	NodoLista* v[n]; 	//se esta declarando un vector tamaño 3 cuyos punteros apuntan a nodolita y se incian en null
	
	crearVectorLista(v, n);
	mostrarVectorLista(v, n);
}

void crearVectorLista(NodoLista* vl[], int n){
	int i;
	int cantNodos;
	int j;
	NodoLista* nuevo;
	NodoLista* h;
	NodoLista* aux;

	for(i=0; i<n; i++){
		do{
			printf("Ingrese la cantidad de nodos de la lista : " );
			scanf("%i", &cantNodos);   //cantidad cualquiera
		}while(cantNodos<1);
		
		h=NULL; //se reinicia por cada lista
		for(j=1;j<=cantNodos;j++){ //creamos toda la lista en este for
			nuevo=crearNodo();
			printf("ingrese un valor para el nodo %i: " , j);
			scanf("%i", &nuevo->dato);	//if donde se pida ascender numericamente
			if(h==NULL){
				h=nuevo;
				aux=h;
			}else{
				aux->sig=nuevo;
				aux=aux->sig;
			}
		}
		vl[i]=h;	
	}
	
}

NodoLista* crearNodo(){
	NodoLista* nuevo;
	
	nuevo=(NodoLista*)malloc(sizeof(NodoLista));
	nuevo->sig=NULL;
	
	return nuevo;
}

/* 3. recorrer y mostrar cada una de las listas */
void mostrarVectorLista(NodoLista* v[], int n){
	NodoLista* aux;
	int i;
	
	for(i=0; i<n ;i++){
		printf("\nLista de vector %i: \n", i);
		aux=v[i];
		while(aux!=NULL){
			printf(" %i --> ", aux->dato);
			aux=aux->sig;
		}
		printf("NULL");
	}
	
	
}
