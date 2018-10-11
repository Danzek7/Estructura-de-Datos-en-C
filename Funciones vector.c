#include <stdio.h>
#include <math.h>
int normal(int vec[],int tam);
void main(){
	int tamanio;
	do{
		printf("Ingrese el tamanio del vector: ");
		scanf("%i",&tamanio);
	}while(tamanio<0);
	int i;
	int v[tamanio];
	float norma[tamanio];
	for(i=0;i<tamanio;i++){
		printf("\nIngrese el valor del vector[%i]: ",i);
		scanf("%i",&v[i]);
	}
	int indice=mostrar(v,tamanio);
	printf("\nLa norma del vector es: ",indice);
}
int normal(int vec[], int tam){
	float suma;
	int i;
	suma=0;
	float norma[tam];
	for(i=0;i<tam;i++){
		norma[i]=sqrt(pow(vec[i],2));
	}
	for(i=0;i<tam;i++){
		suma=norma[i]+suma;
	}
	return suma;
}
