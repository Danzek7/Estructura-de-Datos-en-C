#include <stdio.h>
#include <stdlib.h>
typedef struct Lista{
	struct Lista* ant;
	int info;
	struct Lista* sig;
}Lista;
Lista* crearNodos();
void main(){
	Lista* lis;
	Lista* nuevo;
	Lista* head;
	int res;
	printf("Ingrese informacion para el nodo actual: ");
	scanf("%i",&inicio->info);
	lis->ant=NULL;
	lis->sig=NULL;
	head=lis;
	do{
		printf("\nQuiere crear mas nodos?: ");
		scanf("%i",&res);
		nuevo=crearNodoDoble();
		if(lis->info<=nuevo->info){
			
		}
		inicio->sig=nuevo;
		nuevo=inicio;
	}while((res<0)&&(res>=1));
	
}
Lista* crearNodoDoble(){
	Lista* aux;
	Lista* head;
	Lista* aux2;
	Lista* nuevo;
	aux=(Lista*)malloc(sizeof(Lista));
	aux->ant=NULL;
	aux->sig=NULL;
	head=NULL;
	if(head==NULL){
		head=nuevo;
	}else{
		do{
		    aux=head;
		    if(aux->info<=nuevo->info){
		    	if(aux->sig!=NULL){
		    	aux2=aux->sig;
		    	    if(aux2->info>nuevo->info){
		    		    aux->sig=nuevo;
		    		    nuevo->sig=aux2;
				    }
				    aux=aux->sig;
			    }else{
				    aux->sig=nuevo;
		    	}
		    }else{
		    	if(aux==head){
		    		nuevo->sig=head;
		    		head=nuevo;
				}
			}
			
	    }while(aux->sig==NULL && a==0);
    }
		    
      
	    printf("\nEl valor del nuevo nodo es: ");
	    scanf("%i",&aux->info);
	}
	return aux;
}
