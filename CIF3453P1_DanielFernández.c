#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define tam 4
typedef struct Paciente{
	int nroFicha;
	char genero; //F: femenino, M:masculino
	short mesNac;
	short agnoNac;
	char grupo[2]; //Grupo sanguíneo: A, B, AB, O
	char factor; //+: positivo, -:negativo
}Ficha;
void completarFicha(Ficha* []);
void mostrarEdad(Ficha* []);
void obtenerEstadistica(Ficha* []);

void main(){
	Ficha* array[tam]={NULL};
	completarFicha(array);
	mostrarEdad(array);
	obtenerEstadistica(array);
} 
void completarFicha(Ficha* fic[]){
	Ficha vec1;
	Ficha vec2;
	Ficha vec3;
	Ficha vec4;
	Ficha* v1;
	Ficha* v2;
	Ficha* v3;
	Ficha* v4;
	v1=&vec1;
	v2=&vec2;
	v3=&vec3;
	v4=&vec4;
	
	v1->nroFicha=1;
    v1->genero='F';
    v1->mesNac=6;
    v1->agnoNac=8;
    strcpy(v1->grupo,"A");
    v1->factor='+';
    fic[0]=v1;
    
	v2->nroFicha=2;
    v2->genero='M';
	v2->mesNac=12;
	v2->agnoNac=98;
    strcpy(v2->grupo,"O");
	v2->factor='+';
	fic[1]=v2;
	    
	v3->nroFicha=4;
	v3->genero='M';
	v3->mesNac=3;
	v3->agnoNac=6;
	strcpy(v3->grupo,"O");
	v3->factor='-';
	fic[2]=v3;
	    
	v4->nroFicha=7;
    v4->genero='F';
	v4->mesNac=6;
    v4->agnoNac=97;
    strcpy(v4->grupo,"AB");
    v4->factor='-';
    fic[3]=v4;
}
void mostarEdad(Ficha* f[]){
	Ficha anio;
	Ficha* a;
	a=&anio;
    int i;
    short edad[tam];
    for(i=0;i<tam;i++){
    	a=f[i];
    	edad[i]=(18-(a->agnoNac));
	}
    for(i=0;i<tam;i++){
    	printf("\n\nLa edad del paciente nro %i es: %i",i+1,edad[i]);
	}	
}
void obtenerEstadistica(Ficha* ficha[]){
	int i;
	int men;
	int ab;
	int age;
	int o;
	men=0;
	ab=0;
	age=0;
	o=0;
	for(i=0;i<tam;i++){
	    if(ficha[i]->agnoNac<1&&ficha[i]->factor=='-'){
	        men=men+1;
	    }
	    if((ficha[i]->genero='M')&&(!strcmp(ficha[i]->grupo,"AB"))){
	    	ab=ab+1;
		}
		if(ficha[i]->agnoNac>=43){
			age=age+1;
		}
    }
}
