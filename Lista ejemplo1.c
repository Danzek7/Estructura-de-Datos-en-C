#include <stdio.h>
#include <stdlib.h>//Debido a que se está usando "malloc"(se necesita para la compilación)
typedef struct Nodo{
	int info;
	struct Nodo* Sig;
}Nodo;
void main(){
	int cantNodos;
	int i;
	Nodo* head; //cabecera de la lista de tipo Nodo*
	Nodo* nuevo;//para ir pidiendo la memoria para cada nodo que se vaya pidiendo
	Nodo* aux;//para no alterar a head
	do{
		printf("Ingrese la cantidad de nodos de la lista: ");
		scanf("%i",&cantNodos);
	}while(cantNodos<1);
	head=NULL;//la lista está vacía
	for(i=1;i<=cantNodos;i++){
		nuevo=(Nodo*)malloc(sizeof(Nodo));//pedir la memoria de acuerdo a la estructura Nodo (El (Nodo*) evita el warning)
		//"malloc" es una funcion de utilizacion de punteros
		printf("\nIngrese una edad: ");
		scanf("%i",&nuevo->info);
		nuevo->Sig=NULL;
		if(head==NULL){
			head=nuevo;
			aux=head;
		}else{
			aux->Sig=nuevo;//porque head no debe ser alterado
			aux=nuevo;
		}
	}
	nuevo=NULL;
	aux=NULL;
}

