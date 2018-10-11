#include <stdio.h>
#include <stdlib.h>

typedef struct NodoCola{
	int dato;
	struct NodoCola* sig;
}NodoCola;

NodoCola* encolar();
NodoCola* crearNodo();

void main(){
	NodoCola* nodo;
	
	nodo=encolar();
}

NodoCola* encolar(){
	NodoCola* nodo;
	NodoCola* ini;
	NodoCola* fin;
	int cant;
	int i;
	
	do{
		printf(" Ingrese la cantidad de nodos de la cola: ");
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

NodoCola* crearNodo(){
	NodoCola* nodo;
	nodo=(NodoCola*)malloc(sizeof(NodoCola));
	printf("\nEl calor del nuevo nodo es: ");
	scanf("%i",&nodo->dato);
	nodo->sig=NULL;
	return nodo;
}
