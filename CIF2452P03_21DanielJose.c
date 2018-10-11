#include <stdio.h>
void obtenerSublista(int vec[],int sub1,int sub2);
void obtenerExtremos(int vec[],int nu,int tam);
void main(){
	//Alumnos: Daniel Fernández / José Riquelme
int tamanio;
	do{
		printf("Ingrese el tamanio del vector: ");
		scanf("%i",&tamanio);
    }while(tamanio<=0);
	int l[tamanio];
	int i;
	int sublista1;
	int sublista2;
	int n;
	for(i=0;i<tamanio;i++){
		printf("\nIngrese el valor del vector [%i]: ",i);
		scanf("%i",&l[i]);
	}
	do{
		printf("\nIngrese la posicion inicial a evaluar: ");
		scanf("%i",&sublista1);
	}while((sublista1<0)&&(sublista1>tamanio));
	do{
		printf("\nIngrese las posicion final a evaluar: ");
		scanf("%i",&sublista2);
	}while((sublista2<sublista1)&&(sublista2>tamanio));
	do{
		printf("\nIngrese los elementos iniciales y finales a evaluar: ");
		scanf("%i",&n);
	}while((n<0)&&(n>tamanio));
	obtenerSublista(l,sublista1,sublista2);
	obtenerExtremos(l,n,tamanio);
}
void obtenerSublista(int vec[],int sub1, int sub2){
	int i;
	printf("\n");
	for(i=sub1-1;i<sub2;i++){
		printf(" %i ",vec[i]);
	}
}
void obtenerExtremos(int vec[],int nu,int tam){
	int i;
	int j;
	printf("\n");
	for(i=0;i<nu;i++){
		printf(" %i ",vec[i]);
	}
	for(j=tam-nu;j<tam;j++){
	    printf(" %i ",vec[j]);		
	}
}
