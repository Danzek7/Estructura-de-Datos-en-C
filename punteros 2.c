#include <stdio.h>
#include <stdlib.h>
void main(){
	typedef struct Dispositivo{
		int nroSerie;
		char marca[30];
		char sisOperativo[15];
		int tamPantalla;
	}Producto;
	
	Producto disp1={111,"Samsung","Android",7};
	Producto* disp2=NULL; 
	disp2=&disp1;
	
	printf("Marca en dispositivo 1: %s",disp1.marca);
	printf("\nMarca en dispositivo 2: %s",disp2->marca); //operador flecha
}
