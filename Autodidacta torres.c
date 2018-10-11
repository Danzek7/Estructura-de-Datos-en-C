#include <stdio.h>
#include <stdlib.h>
#define tamanio 840
int i;
int hab;
typedef struct Torres{
	int cantidad;
	struct Pisos* ptr;
}Torres;
typedef struct Pisos{
	int cantidad;
	struct Departamentos* ptr;
}Pisos;
typedef struct Departamentos{
	int cantidad;
}Departamentos;
void ingresarDatos(Torres*,Pisos*,Departamentos*);
void habitantesComplejo(Torres*);
void main(){
	Torres dato1;
	Pisos dato2;
	Departamentos dato3;
	do{
		printf("¿Cuantas personas pueden vivir en un departamento?: ");
		scanf("%i",&hab);
	}while((hab<=1)&&(hab>=6));
	ingresarDatos(&dato1,&dato2,&dato3);
	habitantesComplejo(&dato1);
}
void ingresarDatos(Torres* dato1, Pisos* dato2, Departamentos* dato3){
	do{
		printf("\nCantidad de Torres del complejo: ");
		scanf("%i",&dato1->cantidad);
	}while(dato1->cantidad<0);
	do{
		printf("\nCantidad de Pisos del complejo: ");
		scanf("%i",&dato2->cantidad);
	}while((dato2->cantidad<0)&&(dato2->cantidad>100));
	do{
		printf("\nCantidad de Departamentos del complejo: ");
		scanf("%i",&dato3->cantidad);
	}while((dato3->cantidad<0)&&(dato3->cantidad>100));
	
	dato1->ptr=&dato2;
	dato2->ptr=&dato3;
}
void habitantesComplejo(Torres* dato1){
	int total;
	total=(hab)*(dato1->cantidad)*(dato1->ptr->cantidad)*(dato1->ptr->ptr->cantidad);
	printf("\nLa cantidad de habitantes del complejo: %i",&total);
}
