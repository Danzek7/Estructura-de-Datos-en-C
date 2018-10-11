#include <stdio.h>
#include <stdlib.h>

typedef struct NodoLista{
	int dato;
	struct NodoLista* sig;
}NodoLista;

NodoLista* crearNodo();
NodoLista* crearLista();
NodoLista* ListaC_unionDuplicado(NodoLista*,NodoLista*);
NodoLista* ListaC_unionSinDuplicado(NodoLista*,NodoLista*);
NodoLista* ListaC_interseccion(NodoLista*,NodoLista*);
NodoLista* ListaC_elementosAsinB(NodoLista*);
NodoLista* ListaC_unionInterseccion(NodoLista*,NodoLista*);
void mostrarLista(NodoLista*);

void main(){
	NodoLista* A;
	NodoLista* B;
	NodoLista* C;
	int op;
	
	printf("Lista A:\n");
	A=crearLista();
	printf("\nLista B:\n");
	B=crearLista();
	
	do{
		printf("\n...¿Que lista C desea ver?\n1: C=(AUB) Con Duplicado\n2: C=(AUB) Sin Duplicado\n3: C=(AnB),\n4: C=(A-B)\n5: C=(AUB)-(AnB)\n6: salir):\nR: ");
		scanf("%i",&op);
	}while((op<=0)&&(op>6));
	
	switch(op){
		case 1:
			C=ListaC_unionDuplicado(A,B);
			mostrarLista(C);
			break;
		case 2:
			
			break;
		case 3:
			C=ListaC_interseccion(A,B);
			mostrarLista(C);
			break;
		case 4:
			C=ListaC_elementosAsinB(A);
			mostrarLista(C);
			break;
		case 5:
			C=ListaC_unionInterseccion(NodoLista*,NodoLista*);
			mostrarLista(C);
			break;
		case 6:
			break;
	}
}

NodoLista* crearLista(){
	NodoLista* head;
	NodoLista* aux;
	NodoLista* aux2;
	NodoLista* nuevo;
	int i;
	int tam;
	
	head=NULL;
	
	do{
		printf("Ingrese el tamanio de la lista: ");
		scanf("%i",&tam);
	}while(tam<=0);
	
	for(i=1;i<=tam;i++){
		nuevo=crearNodo();
		printf("\n---El nodo %i es igual a: ",i);
		scanf("%i",&nuevo->dato);
		if(head==NULL){
			head=nuevo;
			aux=head;
			aux2=aux;
		}else{
			aux->sig=nuevo;
			aux=nuevo;
		}
	}
	
	aux=NULL;
	aux2=NULL;
	nuevo=NULL;
	return head;
}

NodoLista* ListaC_unionDuplicado(NodoLista* a, NodoLista*b){
	NodoLista* C;
	NodoLista* aux;
	NodoLista* aux2;
	NodoLista* head;
	
	aux2=b;
	C=a;
	
	head=NULL;
	
	do{
		if(head==NULL){
			head=C;
			aux=head;
		}else{
			aux=aux->sig;
			C=aux;
		}
	}while(aux->sig!=NULL);
	
	do{
		if(C==aux){
			C->sig=aux2;
			C=aux2;
		}else{
			aux2=aux2->sig;
			C->sig=aux2;
			C=aux2;
		}
	}while(aux2!=NULL);
	
	C=NULL;
	aux=NULL;
	aux2=NULL;
	
	return head;
}

NodoLista* ListaC_interseccion(NodoLista* a, NodoLista* b){
	NodoLista* aux;
	NodoLista* aux2;
	NodoLista* aux3;
	NodoLista* head;
	
	head=NULL;
	aux=a;
	aux2=NULL;
	aux3=b;
	
	do{
		if(head==NULL && aux->sig==NULL){
			head=aux;
			aux2=head;
		}else{
			aux=aux->sig;
		}
	}while(aux2==NULL);
	
	if(aux2->sig==NULL){
		aux2->sig=aux3;
		aux2=aux3;
	}
	aux2->sig=NULL;
	
	aux=NULL;
	aux2=NULL;
	aux3=NULL;
	
	return head;
}

NodoLista* ListaC_elementosAsinB(NodoLista* a){
	NodoLista* head;
	NodoLista* aux;
	NodoLista* aux2;
	NodoLista* A;
	NodoLista* C;
	
	C=a;
	A=C;
	head=NULL;
	
	do{
		A=A->sig;
	}while(A->sig!=NULL);
	
	do{
		if(head==NULL){
			head=C;
			aux=head;
		}else{
			aux=aux->sig;
			C=aux;
		}
	}while(aux->sig!=A);
	
	aux=NULL;
	aux2=NULL;
	A=NULL;
	C=NULL;
	
	return head;
}

NodoLista* ListaC_unionInterseccion(NodoLista*,NodoLista*){
	
}

NodoLista* crearNodo(){
	NodoLista* nodo;
	
	nodo=(NodoLista*)malloc(sizeof(NodoLista));
	nodo->sig=NULL;
	
	return nodo;
}

void mostrarLista(NodoLista* c){
	NodoLista* aux;
	
	aux=c;
	
	printf("\n");
	while(aux!=NULL){
		printf(" %i-->",aux->dato);
		aux=aux->sig;
	}
	printf(" NULL");
}
