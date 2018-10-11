#include <stdio.h>
/*Coded by Daniel Fernandez, Universidad Playa Ancha, 2018(c)*/
void main(){
	struct Emisor{
		int numero;
		char compania[20];
		char fecha[20];
		float hora;
		int duracion;
	};
	struct Receptor{
		int numero;
		char compania[20];
		char fecha[20];
		float hora;
		int duracion;
	};
	struct Emisor emi={965299345,"Claro","San Felipe","15 marzo 2018",18.40,3};
	struct Receptor rec={972156806,"Entel","Los Andes","15 marzo 2018",18.40,3};
	printf("Numero telefonico: %i",emi.numero);
	printf("\nCompania: %s",emi.compania);
	printf("\nUbicacion: %s",emi.ubicacion);
	printf("\nFecha: %s",emi.fecha);
	printf("\nDuracion: %i minutos",emi.duracion);
	printf("\n\nNumero telefonico: %i",rec.numero);
	printf("\nCompania: %s",rec.compania);
	printf("\nUbicacion: %s",rec.ubicacion);
	printf("\nFecha: %s",rec.fecha);
	printf("\nDuracion: %i minutos",rec.duracion);
}
