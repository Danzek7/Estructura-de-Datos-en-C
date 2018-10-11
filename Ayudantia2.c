#include <stdio.h>
#include <stdlib.h>//Debido a que se est� usando "malloc"(se necesita para la compilaci�n)
typedef struct Nodo{
	int info;
	struct Nodo* Sig;
}Nodo;
void main(){
	int cantNodos;
	int valor;
	int cont=0;
	Nodo* head; //cabecera de la lista de tipo Nodo*
	Nodo* nuevo;//para ir pidiendo la memoria para cada nodo que se vaya pidiendo
	Nodo* aux;//para no alterar a head
	do{
		printf("Ingrese la cantidad de nodos de la lista: ");
		scanf("%i",&cantNodos);
	}while(cantNodos<1);
	head=NULL;//la lista est� vac�a
	//Creaci�n del nodo que est� al inicio
	nuevo=(Nodo*)malloc(sizeof(Nodo));//pedir la memoria de acuerdo a la estructura Nodo (El (Nodo*) evita el warning)
	//"malloc" es una funcion de utilizacion de punteros
	nuevo->info=7;
	nuevo->Sig=head;
	head=nuevo;
	//Creaci�n de un nuevo nodo que se inserte al final
	nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->Sig=NULL;
	nuevo->info=8;
	aux=head;
	while(aux->info!=NULL){
		aux=aux->Sig;
		aux->Sig=nuevo;
	}
	//Insertar nodo seg�n el usuario
	aux=head;
	printf("\nEn que lugar quiere ingresar el nodo?: ");
	scanf("%i",&valor);
	while(aux!=NULL){
		cont++;
		aux=aux->Sig;
	}
	if(valor<=cont){
		printf("\nNo se puede");
	}else{
		cont=0;
		aux=head;
		while(aux!=NULL){
			cont++;
			if(cont==valor){
				nuevo=(Nodo*)malloc(sizeof(Nodo));
				nuevo->info=4;
				nuevo->Sig=aux->Sig;
				aux->Sig=nuevo;
			}
			aux=aux->Sig;
		}
	}
	aux=head;
	while(aux!=NULL){
		
		aux=aux->Sig;
	}
}
