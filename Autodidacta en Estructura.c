#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int i;
typedef struct Promedio{
	float nota1;
	float nota2;
	float nota3;
}Promedio;
typedef struct Alumno{
	char nombre[30];
	char genero;
	char fechaNac[20];
    Promedio ptr;
}Alumno;
void corroborarDatos(Alumno*[],int);
Alumno* ingresarDatos(int);
void leerDatos(Alumno*[],int);
void reemplazarDatos(Alumno*[],int);
void main(){
	Alumno* vec[3]={NULL};
	int alm;
	int op;
	do{
		printf("¿Cuantos alumnos estan cursando actualmente?: ");
		scanf("%i",&alm);
	}while(alm<1);
	corroborarDatos(vec,alm);
	do{
		do{
		    printf("\n\n¿Que operacion desea realizar ahora?: \n1.Consultar datos\n2.Reemplazar algun dato\n3.Salir\n");
		    scanf("%i",&op);
	    }while((op<1)&&(op>=4));
		switch(op){
			case 1:
				leerDatos(vec,alm);
				break;
			case 2:
				reemplazarDatos(vec,alm);
				break;
			case 3:
				break;
		}
	}while(op!=3);
}
void corroborarDatos(Alumno* cant[], int tam){
	for(i=0;i<tam;i++){
		if(cant[i]==NULL){
			printf("\n\nEstudiante %i:",i+1);
			cant[i]=ingresarDatos(tam);
		}
	}
}
Alumno* ingresarDatos(int tam){
	Alumno* nuevo;
	nuevo=(Alumno*)malloc(tam*sizeof(Alumno));
	for(i=0;i<tam;i++){
		printf("\nIngrese su nombre: ");
		scanf("%s",&nuevo->nombre);
		do{
			printf("\nIngrese su genero (M:masculino, F:femenino): ");
			fflush(stdin);
			scanf("%c",&nuevo->genero);
		}while((nuevo->genero!='m')&&(nuevo->genero!='f')&&(nuevo->genero!='M')&&(nuevo->genero!='F'));
		printf("\nDigite su fecha de nacimiento: ");
		scanf("%s",&nuevo->fechaNac);
		do{
		    printf("\nNota nro 1 (Entre 1.0 y 7.0): ");
		    fflush(stdin);
		    scanf("%f",&nuevo->ptr.nota1);	
		}while((nuevo->ptr.nota1<1)||(nuevo->ptr.nota1>=7.1));
		do{
			printf("\nNota nro 2 (Entre 1.0 y 7.0): ");
			fflush(stdin);
		    scanf("%f",&nuevo->ptr.nota2);
		}while((nuevo->ptr.nota2<1)||(nuevo->ptr.nota2>=7.1));
		do{
			printf("\nNota nro 3 (Entre 1.0 y 7.0): ");
			fflush(stdin);
		    scanf("%f",&nuevo->ptr.nota3);
		}while((nuevo->ptr.nota3<1)||(nuevo->ptr.nota3>=7.1));
		return nuevo;
	}
}
void leerDatos(Alumno* can[],int t){
	float prom;
	for(i=0;i<t;i++){
		printf("\n\nEstudiante %i",i+1);
		printf("\nNombre: %s",can[i]->nombre);
		printf("\nGenero: %c",can[i]->genero);
		printf("\nFecha de nacimiento: %s",can[i]->fechaNac);
		prom=((can[i]->ptr.nota1+can[i]->ptr.nota2+can[i]->ptr.nota3)/3);
		printf("\nPromedio final: %f",prom);
		prom=0;
	}
}
void reemplazarDatos(Alumno* c[],int tam){
	int a;
	int o;
	char nom[30];
	char sex;
	char fec[20];
	float not1;
	float not2;
	float not3;
	do{
		printf("\n¿A que estudiante desea reemplazar sus datos? ");
		scanf("%i",&a);
	}while((a<1)&&(a>=tam+1));
	for(i=0;i<tam;i++){
		if(a==i+1){
			do{
				printf("\n¿Que dato desea reemplazar? \n1.Nombre\n2.Genero\n3.Edad\n4.Nota 1\n5. Nota 2\n6. Nota 3\n");
				scanf("%i",&o);
			}while((o<1)&&(o>=7));
			switch(o){
				case 1:
					printf("\nIngrese el nuevo nombre para el estudiante %i: ",a);
					scanf("%s",nom);
					strcpy(c[i]->nombre,nom);
					break;
				case 2:
					do{
						printf("\nIngrese el sexo del estudiante %i (F:femenino, M:masculino): ",a);
						fflush(stdin);
						scanf("%c",&sex);
					}while((sex!='F')&&(sex!='M')&&(sex!='f')&&(sex!='m'));
					c[i]->genero=sex;
					break;
				case 3:
					printf("\nIngrese la nueva fecha de nacimiento del estudiante %i: ",a);
					scanf("%s",fec);
					strcpy(c[i]->fechaNac,fec);
					break;
				case 4:
					do{
						printf("\nIngrese el nuevo resultado de la evaluacion nro 1 del estudiante %i: ",a);
					    fflush(stdin);	
					    scanf("%f",&not1);
					}while((not1<1)&&(not1>=7.1));
					c[i]->ptr.nota1=not1;
					break;
				case 5:
					do{
						printf("\nIngrese el nuevo resultado de la evaluacion nro 2 del estudiante %i: ",a);
					    fflush(stdin);
						scanf("%f",&not2);	
					}while((not2<1)&&(not2>=7.1));
					c[i]->ptr.nota2=not2;
					break;
				case 6:
					do{
						printf("\nIngrese el nuevo resultado de la evaluacion nro 3 del estudiante %i: ",a);
					    fflush(stdin);	
					    scanf("%f",&not3);
					}while((not3<1)&&(not3>=7.1));
					c[i]->ptr.nota3=not3;
					break;
			}
		}
	}
}
