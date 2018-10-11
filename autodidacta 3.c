#include <stdio.h>
#define prom 3
int i;
int res;
typedef struct Alumno{
	char nombre[30];
	int nota[prom];
}Alumno;
int buscaAlumno(Alumno* p);
void main(){
	Alumno est;
	int indice=buscarAlumno(&est);
	printf("%i",indice);
}
int buscaAlumno(Alumno* p){
	res=0;
	printf("Nombre del alumno a evaluar: ");
	scanf("%s",p->nombre);
	for(i=0;i<prom;i++){
		printf("\nIngrese la nota de la evaluación %i: ",i+1);
		scanf("%i",p->nota[i]);
		res=p->nota[i]+res;
	}
	res=(res/prom);
	return res;
}
