#include <stdio.h>
#include <stdlib.h>
typedef struct Dispositivo{
	int nroSerie;
	char marca[30];
	char sisOperativo[15];
	int tamPantalla;
}Producto;

void ingresarDatos(Producto* );
void mostrarDatos(Producto*);
void modificarSO(Producto*);

void main(){
	Producto p;
	ingresarDatos(&p);
	mostrarDatos(&p);
}
void ingresarDatos(Producto* p1){
	printf("Ingrese numero de serie: ");
	scanf("%i",&p1->nroSerie); //flechita porque el puntero tiene el control
	printf("\nIngrese la marca: ");
	scanf("%s",p1->marca); //ámpersan no va en carácteres
	printf("\nIngrese el sistema operativo: ");
	scanf("%s",p1->sisOperativo);
	printf("\nIngrese el tamanio de pantalla: ");
	scanf("%i",&p1->tamPantalla);
	mostrarDatos(p1);
}
void mostrarDatos(Producto* pro){
	printf("\n\nNumero de Serie: %i",pro->nroSerie);
	printf("\nMarca: %s",pro->marca);
	printf("\nSistema operativo: %s",pro->sisOperativo);
	printf("\nTamanio de pantalla: %i",pro->tamPantalla);
	modificarSO(pro->sisOperativo);
}
void modificarSO(Producto* sist){
	int i;
	char sistema[15];
	do{
		printf("\n\n¿Quiere modificar el SO del equipo?");
		scanf("%i",&i);
	}while((i<0)||(i>1));
	if(i!=1){
		printf("Gracias por su visita!");
	}else{
		printf("\nSistema operativo: ");
		scanf("%s",sistema);
	}
	!strcmp(sist->sisOperativo,sistema);
}
