#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	struct Nodo* ant;
	int info;
	struct Nodo* sig;
}Nodo;

Nodo* crearLista();
Nodo* crearNodo();
void mostrarLista(Nodo*);
void mostrarListaInvertida(Nodo*);
Nodo* eliminarNodo(Nodo*,Nodo*);

void main(){
	Nodo* ini;
	Nodo* fin;
	
	ini=crearLista();
	fin=ini;
	
	while(fin->sig!=NULL){
		fin=fin->sig;
	}
	
	printf("\nLista desde el primer campo:");
	
	mostrarLista(ini);
	
	printf("\nLista desde el ultimo campo:");
	
	mostrarListaInvertida(fin);
	
	ini=eliminarNodo(ini,fin);
	
	printf("\n");
	if(ini!=NULL){
		mostrarLista(ini);
	}else{
		printf("\nLa lista esta totalmente vacia");
	}
}

Nodo* crearNodo(){
	Nodo* nodo;
	
	nodo=(Nodo*)malloc(sizeof(Nodo));
	nodo->ant=NULL;
	nodo->sig=NULL;
	
	return nodo;
}

Nodo* crearLista(){
	Nodo* head;
	Nodo* aux;
	Nodo* aux2;
	Nodo* nu;
	int res;
	int a;
	
	head=NULL;
	
	do{
		nu=crearNodo();
		
		if(head==NULL){
			head=nu;
			aux=head;
			printf("El valor del primer nodo es: ");
			scanf("%i",&aux->info);
		}else{
			printf("\nEl numero contenido en el nuevo nodo es: ");
			scanf("%i",&nu->info);
			do{
				if(aux->info > nu->info){
					if(aux->sig!=NULL){
						aux2=aux->sig;
						if(aux2->info > nu->info){
							aux->sig=nu;
						    nu->sig=aux2;
						    a=1;
						}
						aux=aux->sig;
					}else{
						aux->sig=nu;
						nu->ant=aux;
					}
				}else{
					if(aux==head){
						nu->sig=head;
						head=nu;
						a=1;
					}
				}
			}while(aux->sig!=NULL && a==0);
		}

		do{
			printf("\n---------Quiere añadir otro nodo a la lista (1:si, 0:no)?: ");
			scanf("%i",&res);	
		}while((res<0)&&(res>=2));	
	}while(res==1);
	
	aux=NULL;
	aux2=NULL;
	nu=NULL;
	
	return head;
}

void mostrarLista(Nodo* ini){
	Nodo* aux;
	
	aux=ini;
	
	printf("\n");
	
	while(aux!=NULL){
		printf(" %i -->",aux->info);
		aux=aux->sig;
	}
	
	printf(" NULL");
}

void mostrarListaInvertida(Nodo* fin){
	Nodo* aux;
	
	aux=fin;
	
	printf("\n");
	
	while(aux!=NULL){
		printf(" %i -->",aux->info);
		aux=aux->ant;
	}
	
	printf(" NULL");
}

Nodo* eliminarNodo(Nodo* ini, Nodo* fin){
	Nodo* aux;
	Nodo* aux2;
	int val;
	int enc;
	
	enc=0;
	aux=ini;
	
	printf("\nIngrese el numero del nodo que quiere eliminar: ");
	scanf("%i",&val);
	
	do{
		if(aux->info==val){
			enc=1;
		}else{
			aux=aux->sig;
		}
	}while(aux!=NULL && enc==0);
	
	if(enc==0){
		printf("\nEl valor NO existe!");
	}else{
		if(aux==ini){
			if(aux==fin){
				ini=NULL;
				fin=NULL;
				free(aux);
				aux=NULL;
			}else{
				ini=aux->sig;
				ini->ant=NULL;
				aux->sig=NULL;
				free(aux);
				aux=NULL;
			}
		}else{
			if(aux==fin){
				fin=aux->ant;
				fin->sig=NULL;
				aux->ant=NULL;
				free(aux);
				aux=NULL;
			}else{
				aux2=aux->ant;
				aux2->sig=aux->sig;
				aux2=aux->sig;
				aux2->ant=aux->ant;
				aux->sig=NULL;
				aux->ant=NULL;
				free(aux);
				aux=NULL;
			}
		}
	}
	return ini;
}
