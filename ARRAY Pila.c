#include <stdio.h>

void mostrar(int [], int);

void main(){
	int i;
	int cant;
	
	do{
		printf("\nIngrese la cantidad de elementos que tendrá la pila: ");
		scanf("%i",&cant);
	}while(cant<1);
	
	int v[cant];
	i=0;
	
	do{
		printf("\n V[%i]: ",i+1);
		scanf("%i",&v[i]);
		i++;
	}while(i<cant);
	
	mostrar(v,cant);
}

void mostrar(int v[], int cant){
	int i;
	
	i=cant-1;
	printf("\n");
	do{
		printf(" %i\n _\n",v[i]);
		i--;
	}while(i>=0);
	printf(" NULL");
}
