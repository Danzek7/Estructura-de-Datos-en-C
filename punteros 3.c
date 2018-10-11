#include <stdio.h>
void main(){
	int a;
	int* p;
	
	printf("La direccion de a es: %i",&a);
	
	p=&a;
	
	printf("\nLa direccion almacenada en p es: %i",p);
	
	p=p+1; //incrementa el contenido de la variable puntero
	
	printf("\nLa nueva direccion almacenada en p es: %i",p);
}
