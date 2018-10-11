#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* encolar();
Nodo* crearNodo();
void desencolar(Nodo* );
void mostrar(Nodo* );

void main(){
	Nodo* nodo;
	int op;
	
	nodo=encolar();
	do{
		do{
			printf("\nQue desea hacer? (1.mostrar, 2.desencolar 3.salir) ");
			scanf("%i",&op);
		}while(op<1 || op>=4);
		
		switch(op){
			case 1:
				mostrar(nodo);
				break;
			case 2:
				desencolar(nodo);
				break;
			case 3:
				break;
		}
	}while(op!=3);
}

Nodo* encolar(){
	Nodo* nodo;
	Nodo* ini;
	Nodo* fin;
	int cant;
	int i;
	
	do{
		printf("Ingrese el tamanio de la cola: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	ini=NULL;
	
	for(i=1;i<=cant;i++){
		nodo=crearNodo();
		if(ini==NULL){
			ini=nodo;
			fin=nodo;
		}else{
			fin->sig=nodo;
			fin=nodo;
		}
	}
	return ini;
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	printf("\nEl valor del nuevo nodo es: ");
	scanf("%i",&nodo->dato);
	nodo->sig=NULL;
	return nodo;
}

void desencolar(Nodo* ini){
	Nodo* aux;
	int res;
	
	if(ini->sig!=NULL){
		do{
			aux=ini;
			ini=ini->sig;
			aux->sig=NULL;
			free(aux);
			aux=NULL;
			
			do{
				printf("\nDesea seguir desencolando? 1.si, 2.no ");
				scanf("%i",&res);
			}while(res<1 || res>2);
		}while(res!=2);
	}else{
		printf("\nNo se puede seguir desencolando");
	}
}

void mostrar(Nodo* nodo){
	printf("\nEl primer valor de la cola es: %i",nodo->dato);
	printf("\n");
}
