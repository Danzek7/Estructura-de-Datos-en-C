#include <stdio.h>
#include <stdlib.h>
int alum;
int i;
typedef struct Estudiante{
	char nombre[30];
	int edad;
	int promedio;
}Alumno;
void ingresar(Alumno* );
void mostrar(Alumno* ,int );
void main(){
	Alumno a;
	ingresar(&a);
}
void ingresar(Alumno* a){
	do{
	    printf("¿Cuantos alumnos estan cursando?: ");
	    scanf("%i",&alum);
	}while(alum<0);
	for(i=1;i<=alum;i++){
		printf("\n\nNombre alumno %i: ",i);
		scanf("%s",&a->nombre);
		printf("\nEdad: ");
		scanf("%i",&a->edad);
		printf("\nPromedio: ");
		scanf("%i",&a->promedio);
	}
	mostrar(a,alum);
}
void mostrar(Alumno* e,int cant){
	for(i=1;i<=cant;i++){
		printf("\n\n%i ALumno: %s",i,e->nombre);
		printf("\nedad: %i",e->edad);
		printf("\npromedio: %i",e->promedio);
	}
}
