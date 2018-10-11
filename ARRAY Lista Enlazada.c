#include <stdio.h>

void mostrar(int [], int);

void main(){
	int i;
	int cant;
	int op;

	
	do{
		printf("\nIngrese el tamano de la lista: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	int a[cant];
	i=0;
	
	do{
		printf("\n V[%i]: ",i+1);
		scanf("%i",&a[i]);
		i++;
	}while(i<cant);
	
	do
	{
		do
		{
			printf("\nQue desea hacer? (1.Mostrar, 2.Eliminar, 3.Ingresar, 4.Quit): ");
			scanf("%i",&op);
		}while(op<1 || op>4);
		
		switch(op)
		{
			case 1:
				mostrar(a,cant);
				break;
			case 2:
				
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}while(op!=4);
}


void mostrar(int a[], int cant){
	int i;
	i=0;
	
	printf("\n");
	do{
		printf(" %i-->",a[i]);
		i++;
	}while(i<cant);
	printf(" NULL");
}
