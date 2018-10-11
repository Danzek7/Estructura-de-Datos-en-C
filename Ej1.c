#include <stdio.h>
void main(){
	int num;
	int res;
	int suma;
	do{
		printf("Ingrese un numero entero positivo: \n");
		scanf("%i",&num);
	}while(num<0);
	suma=0;
	do{
		res=num%10;
		num=num/10;
		suma=suma+res;
	}while(num>0);
	printf("\nEl resultado de la suma es: %i",suma);
}
