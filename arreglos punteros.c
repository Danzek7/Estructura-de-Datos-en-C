#include <stdio.h>
#define tamanio 7
typedef struct Paciente{
	int nroFicha;
	char fechaNac[10]; //formato dd/mm/aaaa
	char genero; //f:femenino; m:masculino
}Paciente;
void ingresarPaciente(Paciente* );
void asignarPaciente(Paciente*[],Paciente*);
void verAsignaciones(Paciente*[]);
void main(){
	Paciente* box[tamanio]={NULL}; //MUY RECOMENDABLE para punteros
	Paciente pac;
	ingresarPaciente(&pac);
	asignarPaciente(box,&pac);
	verAsignaciones(box);
}
void ingresarPaciente(Paciente* p){
	printf("\nNro de ficha del paciente: ");
	scanf("%i",&p->nroFicha);
	printf("\nFecha de nacimiento del paciente: ");
	scanf("%s",p->fechaNac);
	printf("\nGenero del paciente: %c");
	scanf("%s",&p->genero);
}
void asignarPaciente(Paciente* b[],Paciente* a){
	int box;
	do{
		printf("\n¿A que box quiere ingresar al paciente? ");
		scanf("%i",&box);
	}while((box<1)||(box>tamanio));
	b[box]=a; //guarda la dirección de memoria de la estructura
}
void verAsignaciones(Paciente* b[]){
	int i;
	for(i=1;i<tamanio+1;i++){
	    if(b[i]==NULL){
	    	printf("\nBox %i - Sin Asignacion",i);
		}else{
			printf("\nBox %i - Asignacion a %i",i,b[i]->nroFicha);
		}
	}
}
