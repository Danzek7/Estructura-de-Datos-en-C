#include <stdio.h>
void main(){
	typedef struct Parlamento{
		char nom[20];
		char fechaNac[20];
		char puest[20];
		char reg[20];
		char par[10];
		int dist;
	}Parlamento;
	Parlamento p={"Allamand Zavala, Andres","12 junio 1958","Senador","Metropolitana de Santiago","RN",7};
	printf("Nombre: %s",p.nom);
	printf("\nFecha de nacimiento: %s",p.fechaNac);
	printf("\nPuesto: %s",p.puest);
	printf("\nRegion: %s",p.reg);
	printf("\nPartido: %s",p.par);
	printf("\nDistrito: %i",p.dist);
}
