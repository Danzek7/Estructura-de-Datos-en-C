#include <stdio.h>
typedef struct Agenda{
	char num[12];
	char nombre[30];
	struct Agenda* sig;
}Agenda;
void anadirElem(Agenda*);
void main(){
	int a;
	Agenda ag;
	do{
		printf("¿Que accion quiere realizar? (1.añadir elemento, 2.borrar elemento, 3.mostrar lista, 4.salir): ");
		scanf("%i",&a);
	}while((a<1)&&(a>=5));
	switch(a){
		case 1:
			anadirElem(&ag);
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
	}
}
void anadirElem(Agenda* agen){
	printf("\nNumero del usuario: ");
	scanf("%s",&agen->num);
	printf("\nNombre del usuario: ");
	scanf("%s",&agen->nombre);
}
