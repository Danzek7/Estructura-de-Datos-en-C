#include <stdio.h>
void main(){
	int cant;
	int i;
	do{
		printf("¿Cuantos competidores habran?:");
		scanf("%i",&cant);
	}while(cant<0);
	typedef struct Corredor{
	    char nom[20];
		int edad;
		char sexo[20];
		char club[20];	
	}c[cant];
	for(i=0;i<=cant;i++){
		printf("\nCorredor %i:",i);
		printf("\nEdad: %i",c[i].edad);
	}
}
