#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo{
	int dato;
	struct Nodo* sig;	
}NodoLista;

void crearVectorLista(NodoLista* [], int ); 
NodoLista* crearNodo();
void ListaC_unionSinDuplicado(NodoLista* []);
void ListaC_unionConDuplicado(NodoLista* []);
void mostrarInterseccion(NodoLista* []);
void eliminarLista(NodoLista* []);
void limpiarVector(NodoLista* []);
void mostrarVectorLista(NodoLista* [], int );
void mostrarListaC(NodoLista* v[]);

void main(){
	int n;
	n=3;
	NodoLista* v[n]; 	//se esta declarando un vector tamaño 3 cuyos punteros apuntan a nodolita y se incian en null
	int op;
	
	v[n]=NULL;
	
	crearVectorLista(v, n);
	ListaC_unionSinDuplicado(v);
	ListaC_unionConDuplicado(v);
	mostrarInterseccion(v);
	
	do{
		do{
			printf("\n...¿Que lista C desea ver?\n1: C=(AUB) Con Duplicado\n2: C=(AUB) Sin Duplicado\n3: C=(AnB),\n4: C=(A-B)\n5: C=(AUB)-(AnB)\n6: salir):\nR: ");
			scanf("%i",&op);
		}while((op<=0)&&(op>6));
		
		switch(op){
			case 1:
				ListaC_unionDuplicado(v);
				mostrarVectorLista(v, n);
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				break;
		}
	}while(op!=6);
}

void crearVectorLista(NodoLista* vl[], int n){
	int i;
	int cantNodos;
	int j;
	NodoLista* nuevo;
	NodoLista* h;
	NodoLista* aux;

	for(i=0; i<n-1; i++){ //establecer el limite <3 pero empieza de 0 => es i<2 == i<3-1
		
		do{
			if(i==0){
				printf("Ingrese la cantidad de nodos de la lista A: " );
			}else if(i==1){
				printf("Ingrese la cantidad de nodos de la lista B: " );
			}
			scanf("%i", &cantNodos);   //cantidad cualquiera
		}while(cantNodos<=1);
		
		printf("\n");
		h=NULL; //se reinicia por cada lista
		
		for(j=1;j<=cantNodos;j++){ //creamos toda la lista en este for
		
			nuevo=crearNodo();
			printf("ingrese un valor para el nodo %i: " , j);
			scanf("%i", &nuevo->dato);
				
			if(h==NULL){
				h=nuevo;
				aux=h;
				
			}else{
				aux->sig=nuevo;
				aux=aux->sig;
			}
		}
		vl[i]=h;
		printf("\n");	
	}
	
}

NodoLista* crearNodo(){
	NodoLista* nuevo;
	
	nuevo=(NodoLista*)malloc(sizeof(NodoLista));
	nuevo->sig=NULL;
	
	return nuevo;
}

void ListaC_unionSinDuplicado(NodoLista* vl[]){
	NodoLista* nuevo;
	NodoLista* aux;
	NodoLista* aux2;
	NodoLista* aux3;
	NodoLista* h;
	int i;
	int cont;
	
	cont=0;
	h=NULL;
	
	for(i=0; i<2; i++){
		aux= vl[i];
		if(i==0){
			while(aux->sig!=NULL){	
				aux=aux->sig;
				nuevo=crearNodo();
				nuevo->dato=aux->dato;
				
				if(h==0){
					h=nuevo;
					aux2=h;
				}else{
					aux2=aux2->sig;
				}
			}		
		}
		if(i==1){
			while(aux->sig!=NULL){
				aux=aux->sig;
				aux3=h;
				while(aux3->dato!=NULL){
					if(aux->dato==aux3->dato){
						aux3=aux3->sig;
					}
					if(aux->dato==aux3->dato){
						cont=1;
					}
				}
				if(cont==0){
					nuevo=crearNodo();
					nuevo->dato=aux->dato;
					aux2->sig=nuevo;
					aux2=aux2->sig;
				}
			}
		}
	}
	
	aux=vl[2];
	aux->sig=h;

}

void ListaC_unionConDuplicado(NodoLista* vl[]){
	NodoLista* nuevo;
	NodoLista* aux;
	NodoLista* aux2;
	NodoLista* aux3;
	NodoLista* h;
	int i;
	int cont;
	
	cont=0;
	
	for(i=0; i<2; i++){
		aux= vl[i];
		if(i==0){
			while(aux->sig!=NULL){	
				aux=aux->sig;
				nuevo=crearNodo();
				nuevo->dato=aux->dato;
				
				if(h==0){
					h=nuevo;
					aux2=h;
				}else{
					aux2=aux2->sig;
				}
			}		
		}
		if(i==1){
			while(aux->sig!=NULL){
				aux=aux->sig;
				nuevo=crearNodo();
				nuevo->dato=aux->dato;
				aux2->sig=nuevo;
				aux2=aux2->sig;
			}
		}
	}
	aux=vl[2];
	aux->sig=h;
}

void mostrarInterseccion(NodoLista* vl[], int n){
	NodoLista* nuevo;
	NodoLista* aux;
	NodoLista* aux2;
	NodoLista* aux3;
	NodoLista* h;
	int i;
	int j;
	
	aux=vl[0];
	aux2=vl[1];
	
	while(aux->sig!=NULL){
		aux=aux->sig;
		aux2=aux2->sig;
		while(aux2->sig!=NULL){
			if(aux->dato==aux2->dato){
				nuevo=crearNodo();
				nuevo->dato=aux->dato;
				if(head==NULL){
					h=nuevo;
					aux3=h;
				}else{
					aux3=nuevo;
					aux3=aux3->sig;
				}
			}else if(aux->dato!=aux2->dato){
				aux2=aux2->sig;
			}
		}
	}
	aux=vl[2];
	aux->sig=h;
}
// 3. recorrer y mostrar cada una de las listas 
void mostrarVectorLista(NodoLista* v[], int n){
	NodoLista* aux;
	int i;
	
	for(i=0; i<n-1 ;i++){
		printf("\nLista de vector %i: \n", i);
		aux=v[i];
		while(aux!=NULL){
			printf(" %i --> ", aux->dato);
			aux=aux->sig;
		}
		printf("NULL\n");
	}	
}

/* 4. eliminar UNA de las listas del vector 
void eliminarLista(NodoLista* v[], int n){
	int nrovec;
	
	printf("Usted cuenta con %n listas, cual desea eliminar? ", n);
	scanf("%i", &nrovec);
	
	for(i=0; i<n; i++){
		if(i==nrovec){
			aux=v[i];
			aux2=aux->sig;
			aux=NULL;
			free(aux2);
		}
	
	}
	
	
}
*/




/* 5. limpiar el vector 

void limpiarVector(NodoLista* v[], int n){
	NodoLista* aux;
	NodoLista* aux2;
	int i;
	
	for(i=0; i<n; i++){
		aux=v[i];
		aux2=aux->sig;
		aux=NULL;
		free(aux2);
	}
}
*/
