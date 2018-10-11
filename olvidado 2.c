#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo* sig;
}Nodo;

Nodo* crearNodo();
Nodo* encolar();

void main(){
	Nodo* nodo
	
	nodo=encolar();
}

void encolar(Nodo* ini, Nodo* fin){
	Nodo* ini;
	Nodo* fin;
	Nodo* nuevo;
	int i;
	
	ini=NULL;
	
	for(i=1;i<4;i++){
		nuevo=crearNodo();
		if(ini==NULL){
			ini=nuevo;
			fin=ini;
		}else{
			fin->sig=nuevo;
			fin=nuevo;
		}
	}
	return ini;
}

Nodo* crearNodo(){
	Nodo* nodo;
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->sig=NULL;
	return nodo;
}
