#include <stdio.h>
void main(){
	int a[5]={1,2,3};
	int* p;
	p=a; //Como es arreglo no lleva &
	printf("La direccion de a es: %i",a);
	printf("\nLa direccion de p es: %i",p);
	
	*p=10; //El * muestra el contenido de la primera celda
	
	printf("\n\nEL primer valor del arreglo es: %i",*a);
	printf("\nEl primer valor del arreglo es: %i",a[0]);
	
	p=&a[1]; //porque sólo entrega la dirección del primer elemento
	
	printf("\n\nEl segundo valor del arreglo es: %i",*p);
	printf("\nEL segundo valor del arreglo es: %i",a[1]);
}
