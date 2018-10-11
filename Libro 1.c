#include <stdio.h>
#include <stdlib.h>

typedef struct NodoLista{
	int dato;
	struct NodoLista* sig;
}NodoLista;

NodoLista* crearNodo();
NodoLista* enlistar();
void eliminarElemento(NodoLista* );
void insertarElemento(NodoLista* );
void mostrar(NodoLista* );

void main(){
	NodoLista* ini;
	int op;
	
	ini=enlistar();
	
	do{
		do{
			printf("\nQué hacer ahora?:\n1.mostrar\n2.Eliminar un elemento\n3.Insertar al INICIO\n4.Insertar al Final\n5.Ordenar Lista\n6.Salir \nR: ");
			scanf("%i",&op);
			printf("\n\n");
		}while(op<1 || op>=6);
		
		switch(op){
			case 1:
				mostrar(ini);
				break;
			case 2:
				eliminarElemento(ini);
				break;
			case 3:
				insertarElemento(ini);
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

void insertarElemento(NodoLista* nodo){
	int dato;
	int pos;
	NodoLista* aux;
	
	printf("\ningrese el valor del dato que desea insertar: ");
	scanf("%i",&dato);
	
	if(nodo==NULL){
		nodo->dato=dato;
	}else{
		
	}
}

NodoLista* enlistar(){
	NodoLista* nuevo;
	NodoLista* head;
	NodoLista* aux;
	int i;
	int cant;
	
	head=NULL;
	i=0;
	
	do{
		printf("\nIngrese la cantidad de nodos que tendrá a lista: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	do{
		nuevo=crearNodo();
		printf("\n Nodo nro° %i: ",i+1);
		scanf("%i",&nuevo->dato);
		if(head==NULL){
			head=nuevo;
			aux=head;
		}else{
			aux->sig=nuevo;
			aux=nuevo;
		}
		i++;
	}while(i<cant);
	
	nuevo=NULL;
	aux=NULL;
	
	return head;
}

NodoLista* crearNodo(){
	NodoLista* nodo;
	
	nodo=(NodoLista*)malloc(sizeof(NodoLista));
	nodo->sig=NULL;
	
	return nodo;
}

void eliminarElemento(NodoLista* nodo){
	NodoLista* aux;
	NodoLista* aux2;
	NodoLista* aux3;
	NodoLista* fin;
	int enc;
	int val;
	
	printf("\nElemento a eliminar: ");
	scanf("%i",&val);
	
	enc=0;
	aux=nodo;
	aux2=nodo;
	aux3=aux;
	fin=nodo;	
	
	while(aux!=NULL && enc!=1){
		if(aux->dato==val){
			enc=1;	
		}else{
			aux=aux->sig;
		}	
	}
	
	while(fin->sig!=NULL){
		fin=fin->sig;
	}
	
	if(enc==0){
		printf("\nEl elemento que se desea eliminar no existe");
	}else{
		if(aux==aux2){
			if(aux==fin){
				aux->sig=NULL;
				free(aux);
				aux=NULL;
			}else{
				aux2=aux->sig;
				aux->sig=NULL;
				free(aux);
				aux=NULL;
			}
		}
		if(aux==fin){
			while(aux2->sig!=fin){
				aux2=aux2->sig;
			}
			aux=aux2;
			aux2->sig=NULL;
			free(fin);
			fin=NULL;
		}else{
			while(aux2->sig!=aux && aux3->sig!=aux){
				aux2=aux2->sig;
				aux3=aux3->sig;
			}
			aux2->sig=aux->sig;
			aux2=aux2->sig;
			aux3->sig=aux2;
			aux->sig=NULL;
			free(aux);
			aux=NULL;
		}	
	}
	printf("\n\n");
}

void mostrar(NodoLista* nodo){
	NodoLista* aux;
	
	aux=nodo;
	
	printf("\n");
	
	do{
		printf(" %i-->",aux->dato);
		aux=aux->sig;
	}while(aux!=NULL);
	
	printf(" NULL\n\n");
}
