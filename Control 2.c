#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pedido
{
	int codigo;
	char tipo[6]; //alimento: perro, gato, ave, pez
	int kilos;
	struct Pedido* sig;
}Pedido;

typedef struct Produccion
{
	int cantProcesados;
	int produccionKg;
	Pedido* principal;
	Pedido* espera;
}Linea;

Pedido* ingresarColaPedidos(); 
Pedido* crearNodo();
int contarNodo(Pedido* );
void clasificar(Linea *v, Pedido* );
void mostrarPedido(Pedido* );
void mostrarLista(int n,Linea *v);

void main(){
	Pedido* P;
	int op;
	int n;
	
	n=4;
	
	Linea L[n];
	
	do{
		do
		{
			printf("Que operacion desea realizar?: \n1.Ingresar pedidos\n2.Mostrar cola Pedidos\n3.Distribuir cola de Pedidos\n4.Mostrar Distribución\n5.Salir\nR:");
			scanf("%i",&op);
		}while(op<0 || op>5);
		
		switch(op)
		{
			case 1:
				P=ingresarColaPedidos();
				break;
			case 2:
				printf("\nPedidos:\n");
				mostrarPedido(P);
				break;
			case 3:
				clasificar(L, P);
				break;
			case 4:
				printf("\nLista:\n");
				mostrarLista(n,L);
				break;
			case 5:
				printf("\nGracias por su visita");
				break;
		}
	}while(op!=5);
}

Pedido* ingresarColaPedidos()
{
	Pedido* nuevo;
	Pedido* head;
	Pedido* aux;
	int i;
	int op;
	
	head=NULL;
	
	for(i=0;i<4;i++)
	{
		printf("\nPedido %i: \n",i);
		
		nuevo=crearNodo();
		
		printf("--Ingrese el codigo del producto: ");
		scanf("%i",&nuevo->codigo);
		
		do
		{
			printf("\n--Que tipo de comida es el producto? \n1.Perro\n2.Gato\n3.Ave\n4.Pez\nR: ");
			fflush(stdin);
			scanf("%i",&op);
		}while((op<1)||(op>=5));
		
		if(op==1)
		{
			strcpy(nuevo->tipo,"Perro");
		}
		if(op==2)
		{
			strcpy(nuevo->tipo,"Gato");			
		}
		if(op==3)
		{
			strcpy(nuevo->tipo,"Ave");			
		}
		if(op==4)
		{
			strcpy(nuevo->tipo,"Pez");			
		}
		
		do{
			printf("\n--Cuantos kilos tiene el producto?: ");
			scanf("%i",&nuevo->kilos);			
		}while(nuevo->kilos<1);
		
		if(head==NULL)
		{
			head=nuevo;
			aux=head;
		}else
		{
			aux->sig=nuevo;
			aux=nuevo;
		}
		printf("\n\n");
	}
	
	aux=NULL;
	nuevo=NULL;
	
	return head;
}

void clasificar(Linea *v, Pedido* head)
{
    Pedido* aux;
    Pedido* headPri;
    Pedido* headSec;
    Pedido* auxPri;
    Pedido* auxSec;
    Pedido* nuevo;
    int i;
    int cont;
    int cantProc;
    int cantKil;
    char animal[10];
    
    for(i=0;i<4;i++)
	{	
        aux=head;
        headPri=NULL;
        headSec=NULL;
        cantProc=0;
        cantKil=0;
        
        if(i==0)
		{
        	strcpy(animal,"Perro");
		}
		if(i==1)
		{
			strcpy(animal,"Gato");
		}
		if(i==2)
		{
			strcpy(animal,"Ave");
		}
		if(i==3)
		{
			strcpy(animal,"Pez");
		}
        
        while(aux!=NULL)
		{
			cantProc++;
			cantKil= aux->kilos+cantKil;
			
            if(!strcmp(aux->tipo,animal))
			{
                nuevo=crearNodo();
                nuevo->codigo=aux->codigo;
                nuevo->kilos=aux->kilos;
                cont=contarNodo(headPri);
               if(cont)
			   {
                    if(headPri==NULL)
					{
                        headPri=nuevo;
                        auxPri=headPri;
                    }else
					{
                        auxPri->sig=nuevo;
                        auxPri=nuevo;
                    }
               }else
			   {
            		if(headSec==NULL){
            			headSec->sig=nuevo;
            			auxSec=nuevo;
					}else{
						auxSec->sig=nuevo;
						auxSec=nuevo;
					}	
               }
            }
            aux=aux->sig;
        }
		(v+i)->principal=headPri;
		(v+i)->espera=headSec;
		(v+i)->cantProcesados=cantProc;
		(v+i)->produccionKg=cantKil;	
    }
}

int contarNodo(Pedido* head)
{
    Pedido* aux;
    
    aux=head;
    int cont;
    
    cont=0;
    
    while(aux!=NULL)
	{
        cont++;
        aux=aux->sig;
    }
    if(cont==10)
	{
        return 0;
    }
    
    return 1;

}

Pedido* crearNodo()
{
	Pedido* nodo;
	
	nodo=(Pedido*)malloc(sizeof(Pedido));
	nodo->sig=NULL;
	
	return nodo;
}

void mostrarPedido(Pedido* head)
{
	Pedido* aux;
	aux=head;
	
	while(aux!=NULL)
	{
		printf(" %i, %s, %i  -->",aux->codigo,aux->tipo,aux->kilos);
		aux=aux->sig;
	}
	
	printf(" NULL\n\n");
}

void mostrarLista(int n,Linea *v)
{
	int i;
	
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Pos: %i:\n",i+1);
		printf(" cantProcesado: %i, cantidadKG: %d, principal: %d-->",(v+i)->cantProcesados,(v+i)->produccionKg);
		printf("NULL\n\n");	
	}
}
