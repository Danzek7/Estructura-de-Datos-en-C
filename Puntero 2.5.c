#include <stdio.h>
#include <stdlib.h>
void main(){
	typedef struct Dispositivo{
		int nroSerie;
		char marca[30];
		char sisOperativo[30];
		int tamPantalla;
	}Producto;
	
	Producto disp1={111,"Samsung","Android",7};
	Producto* disp2=NULL; 
	disp2=&disp1;
	
	printf("Marca en dispositivo 1: %s",disp1.marca);
	printf("\nMarca en dispositivo 2: %s",disp2->marca); //operador flecha
	
	printf("\n\nLa direccion de memoria de marca en disp 1= %i",disp1.marca);
	printf("\nLa direccion de memoria marca almacenada en disp2= %i",disp2->marca);
	
	disp2=disp2+1;
	
	printf("\nLa nueva direccion de memoria de marca almacenada en disp 2 es: %i",disp2->marca);
	
}
