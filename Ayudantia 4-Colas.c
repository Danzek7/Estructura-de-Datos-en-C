#include <stdio.h>
#include <stdlib.h>

typedef struct NodoCola{
	int dato;
	struct NodoCola* sig;
}NodoCola;

NodoCola* crearNodo();
NodoCola* encolar();
NodoCola* desencolar(NodoCola*);

void main(){
	NodoCola* nodo;
	nodo=encolar();
	desencolar(nodo);
}

NodoCola* encolar(){
	NodoCola* nodo;
	NodoCola* inicio;
	NodoCola* fin;
	int i;
	
	nodo=NULL;
	inicio=NULL;
	fin=NULL;
	
	for(i=1;i<=5;i++){
		if(inicio==NULL){
			nodo=crearNodo();
			inicio=nodo;
			fin=nodo;
		}else{
			nodo=crearNodo();
			fin->sig=nodo;
			fin=nodo;
		}
	}
	
	printf("\nEl valor inicial es: %i",inicio->dato);
	return inicio;
}

void desencolar(NodoCola* inicio){
	NodoCola* aux;
	int res;
	
	do{
		if(inicio==NULL){
			printf("\nNo hay elementos.");
		}else{
			aux=inicio;
			inicio=inicio->sig;
			aux->sig=NULL;
			free(aux);
			aux=NULL;
		}
		
		do{
			printf("\nDesea seguir desencolando? (1: si, 0: no): ");
		    scanf("%i",&res);		
		}while((res<0)&&(res>=2));
		
	}while(res!=0);
}

NodoCola* crearNodo(){
	NodoCola* nodo;
	int valor;
	nodo=(NodoCola*)malloc(sizeof(NodoCola));
	printf("\n");
	printf("Ingrese el valor del nuevo nodo: ");
	scanf("%i",&valor);
	nodo->dato=valor;
	nodo->sig=NULL;
	return nodo;
}
