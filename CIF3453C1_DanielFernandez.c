#include<stdio.h>
#include<math.h>
#include<string.h>
typedef struct Registro{
	int nroAten;
	float estatura;
	float peso;
	float imc;
	char clasif[20];
}Atencion;
void ingresarAtencion(Atencion*);
void calcularImc(Atencion*);
void clasificarAtencion(Atencion*);
void main(){
	Atencion aten;
	ingresarAtencion(&aten);
	calcularImc(&aten);
	clasificarAtencion(&aten);
}
void ingresarAtencion(Atencion* a){
	do{
		printf("Numero de atencion del paciente: ");
		scanf("%i",&a->nroAten);
	}while(a->nroAten<1);
	do{
		printf("\nEstatura del paciente: ");
		scanf("%f",&a->estatura);
	}while(a->estatura<1);
	do{
		printf("\nPeso del paciente: ");
		scanf("%f",&a->peso);
	}while(a->peso<1);
}
void calcularImc(Atencion* a){
	a->imc=pow((a->peso/a->estatura),2);
}
void clasificarAtencion(Atencion* a){
	if((a->imc>=18.5)&&(a->imc<25)){
		strcpy(a->clasif,"Normal");
	}
	if((a->imc>=25)&&(a->imc<30)){
		strcpy(a->clasif,"Sobrepeso");
	}
	if((a->imc>=30)&&(a->imc<35)){
		strcpy(a->clasif,"Obesidad Grado I");
	}
	if((a->imc>=35)&&(a->imc<39.9)){
		strcpy(a->clasif,"Obesidad Grado II");
	}
	if(a->imc>=39.9){
		strcpy(a->clasif,"Obesidad Grado III");
	}
	if(a->imc<18.5){
		strcpy(a->clasif,"Desnutrido");
	}
	printf("\n\nDe acuero a su IMC el paciente esta dentro de la clasificacion: %s",a->clasif);
	if(!strcmp(a->clasif,"Normal")){
		printf("\nNivel de riesgo: Promedio");
	}
	if(!strcmp(a->clasif,"Sobrepeso")){
		printf("\nNivel de riesgo: Aumentado");
	}
	if(!strcmp(a->clasif,"Obesidad Grado I")){
		printf("\nNivel de riesgo: Moderado");
	}
	if(!strcmp(a->clasif,"Obesidad Grado II")){
		printf("\nNivel de riesgo: Severo");
	}
	if(!strcmp(a->clasif,"Obesidad Grado III")){
		printf("\nNivel de riesgo: Muy Severo");
	}
	if(!strcmp(a->clasif,"Desnutrido")){
		printf("\nNivel de riesgo: Muy Severo");
	}
}
