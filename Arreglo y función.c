#include <stdio.h>
#define longitud 5 //Define un código para todas las funciones del programa

void ingresarPH(int[]);
void mostrarPH(int[]);

void main(){
	int ph[longitud];
	ingresarPH(ph);
	mostrarPH(ph);
}
void ingresarPH(int v[]){
	int i;
	for(i=0;i<longitud;i++){
		printf("\nIngrese PH[%i]: ",i+1);
		scanf("%i",&v[i]);
	}
}
void mostrarPH(int a[]){
	int i;
	printf("\n");
	for(i=0;i<longitud;i++){
		printf("\nPH[%i]: %i",i+1,a[i]);
	}
}

