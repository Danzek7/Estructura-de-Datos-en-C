#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	struct Nodo* ant;
	int info;
	struct Nodo* suc;
}Nodo;

Nodo* crearLista();
Nodo* crearNodo();
void mostrarLista(Nodo*);

void main(){
	Nodo* ini;
	Nodo* fin;
	ini=crearLista();
	fin=ini;
	mostrarLista(ini);
}

Nodo* crearLista(){
	Nodo* nuevo;
	Nodo* aux;
	Nodo* aux2;
	Nodo* head;
	int a;
	int i;
	
	head=NULL;
	a=0;
	
	do{
		nuevo=crearNodo();
		printf("\nEl valor del nuevo nodo sera: ");
		scanf("%i",&nuevo->info);
		if(head==NULL){
			head=nuevo;
		}else{
			do{
				aux=head;
				if(aux->info <= nuevo->info){
					if(aux->suc==NULL){
						aux2=aux->suc;
						if(aux2->info > nuevo->info){
							aux->suc=nuevo;
							nuevo->suc=aux2;
							a=1;
						}
						aux=aux->suc;
					}else{
						aux->suc=nuevo;
					}
				}else{
					if(aux==head){
						nuevo->suc=head;
						head=nuevo;
						a=1;
					}
				}
			}
		}
		do{
			printf("\nQuiere anadir otro nodo a la lista? (1.si, 0.no)");
		    scanf("%i",&i);
		}while(i<0 && i>=2);
	}while(aux->suc==NULL && a==0 && i==1);
	
	nuevo=NULL;
	aux=NULL;
	aux2=NULL;
	
	return head;
}

Nodo* crearNodo(){
	Nodo* nod;
	nod=(Nodo*)malloc(sizeof(Nodo));
	nod->suc=NULL;
	nod->ant=NULL;
	return nod;
}
void mostrarLista(Nodo* ini){
	Nodo* aux;
	aux=ini;
	printf("\n");
	while(aux!=NULL){
		printf(" %i --> ",aux->info);
		aux=aux->suc;
	}
	printf("NULL");
}
