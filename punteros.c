#include <stdio.h>
#include <stdlib.h>
//standar library por punteros
void main(){
	int a=10;
	int* p, q;
	
	p=&a; //asignaci�n de la direcci�n de
	q=&p;
	
	//Las diferencias var�an de un equipo a otro
	printf("El valor de a es: %i",a);
	printf("\nLa direccion de a es: %i",p);
	
	printf("\nEL valor de p es: %i",p);
	printf("\nLa direccion de p es: %i",q);
	
	printf("\nEl valor de q es: %i",q);
	printf("\nLa direccion de q es: %i",&q); //s�lo para variables de tipo puntero
	
	/////////////////////////////////////////////////////////
	printf("\n\nEl valor de a es: %i",a);
	printf("\nLa direccion de a es: %p",p);
	
	printf("\nEL valor de p es: %p",p);
	printf("\nLa direccion de p es: %p",q);
	
	printf("\nEl valor de q es: %p",q);
	printf("\nLa direccion de q es: %p",&q);
	
	printf("\n\nEl valor de almacenamiento en la direccion asignada a p es: %i",*p);
}
