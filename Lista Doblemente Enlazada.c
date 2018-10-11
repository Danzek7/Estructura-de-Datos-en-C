#include <stdio.h>
#include <stdlib.h>

typedef struct NodoDoble{
	struct NodoDoble* ant; //antecesor
	int info;
	struct NodoDoble* suc; //sucesor
}NodoDoble;

NodoDoble* crearNodoDoble(); //para crear el nodo de la lista
NodoDoble* crearListaDoble();
void mostrarListaDoble(NodoDoble*,NodoDoble*);
NodoDoble* eliminarNodoDoble(NodoDoble*,NodoDoble*);

void main(){
	NodoDoble* inicio;//primer campo
	NodoDoble* fin;//último campo

	inicio=crearListaDoble();//Lo de abajo se lee al final
	//////////////////
	fin=inicio;
	
	while(fin->suc!=NULL){
		fin=fin->suc;
	}
	mostrarListaDoble(inicio,fin);
	eliminarNodoDoble(inicio,fin);
}

NodoDoble* crearNodoDoble(){ //crear tren sin pasajeros
	NodoDoble* nuevo;
	nuevo=(NodoDoble*)malloc(sizeof(NodoDoble));
	nuevo->ant=NULL;
	nuevo->suc=NULL;
	return nuevo;
}

NodoDoble* crearListaDoble(){
	NodoDoble* nodo;
	NodoDoble* ini;
	NodoDoble* aux;
	int cantNodos;
	int i;

	do{
		printf("Cuantos nodos va a tener la lista?: ");
		scanf("%i",&cantNodos);
	}while(cantNodos<=0);

	ini=NULL;

	for(i=1;i<=cantNodos;i++){ //*Look at my sight
		nodo=crearNodoDoble(); //el segundo nodo de la lista
		printf("\nEl nodo %i sera igual a: ",i);
		scanf("%i",&nodo->info);
		if(ini==NULL){
			ini=nodo;//declarar el inicio de la lista
			aux=ini; //para mover el puntero
		}else{ //para apuntar a su sucesor y su antecesor 
			aux->suc=nodo; 
			nodo->ant=aux;
			aux=nodo;
		}
	}
	nodo=NULL;
	aux=NULL;
	
	return ini;
}

NodoDoble* eliminarNodoDoble(NodoDoble* ini, NodoDoble* fin){
	
	int valor;
	int encontrado;
	NodoDoble* aux;
	NodoDoble* aux2;
	
	encontrado=0;
	aux=ini;
	
	printf("\n\nIngrese el valor a eliminar: ");
    scanf("%i",&valor);
    
    while((encontrado!=1) && (aux!=NULL)){ //para que no se caiga la lista (ejemplo del 37)
    	if(aux->info==valor){
    		encontrado=1;
		}else{
			aux=aux->suc;
		}
	}
	
	if(encontrado==0){
		printf("\nNo existe un nodo con el valor ingresado.");
	}else{
		if(aux==ini){ //Si está en la cabezera
		    if(ini==fin){ //Si la lista tiene un solo Nodo
		    	ini=NULL;
		    	fin=NULL;
		    	free(aux);
		    	aux=NULL;
			}else{ //ahora si el caso inicial
				ini=aux->suc; //movemos el nodo inicial al lado
			    ini->ant=NULL;
			    aux->suc=NULL;
			    free(aux);
			    aux=NULL;
			}
	    }
		if(aux==fin){ //Si está al final
			fin=aux->ant; //movemos el nodo final al lado
			fin->suc=NULL;
			aux->ant=NULL;
			free(aux);
			aux=NULL;
		}
		
		if((aux!=ini) && (aux!=fin)){ //Si está en el intermedio de la lista (Ni al comienzo, ni al final)
			aux2=aux->ant;
			aux2->suc=aux->suc;
			aux2=aux->suc;
			aux2->ant=aux->ant;
			//ver ejemplos del cuaderno (arriba)
			aux->suc=NULL;
			aux->ant=NULL;
			free(aux);
			aux=NULL;
		}
	}
}

void mostrarListaDoble(NodoDoble* ini, NodoDoble* fin){
	
	NodoDoble* aux;
	aux=ini;
	
	printf("\n");//leer los sucesores (del inicio al final)
	while(aux!=NULL){
		printf(" %i -->",aux->info);
		aux=aux->suc;
	}
	
	printf(" NULL");
	
	aux=fin;
	
	printf("\n");//leer los antecesores (del final al inicio)
	while(aux!=NULL){
		printf(" %i -->",aux->info);
		aux=aux->ant;
	}
	
	printf(" NULL");
}

