#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	struct Nodo* ant;
	int info;
	struct Nodo* sig;
}Nodo;

Nodo* crearLista();
Nodo* crearNodo();

void main(){
	Nodo* ini;
	Nodo* fin;
	
	ini=crearLista();
}

Nodo* crearLista(){
	Nodo* aux;
	Nodo* aux2;
	Nodo* head;
	Nodo* nuevo;
	int res;
	int a;
	
	head=NULL;
	a=0;
	
	do{
		nuevo=crearNodo();
		if(head==NULL){
			head=nuevo;
			aux=head;
            printf("El valor del primer nodo sera: ");
			scanf("%i",&aux->info);		
		}else{
			printf("\nEl valor del nuevo nodo creado sera: ");
			scanf("%i",&nuevo->info);
			do{
				if(aux->info<=nuevo->info){
					if(aux->sig!=NULL){
						aux2=aux->sig;
						if(aux2->info>nuevo->info){
							aux->sig=nuevo;
							nuevo->sig=aux2;
							a=1;
						}
						aux=aux->sig;	
					}else{
						aux->sig=nuevo;
					}
				}else{
					if(aux==head){
						nuevo->sig=head;
						head=nuevo;
						a=1;
					}
				}
			}while(aux->sig==NULL && a==0);
		}
		do{
			printf("\nQuiere continuar agregando nodos a la lista? (1.si; 0.no): ");
			scanf("%i",&res);
		}while((res<0) && (res>=2));
	}while(res==1);
	
	return head;
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo->ant=NULL;
	nodo->sig=NULL;
	return nodo;
}
