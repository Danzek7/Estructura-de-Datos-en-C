/*En base al código base: 
1.-ingresarDeposito(): Debe solicitar los datos de un depósito, con sus respectivas validaciones y asignando a la celda
que se encuentre disponible en un arreglo.
LA llamada a esta función puede ser parte de un ciclo que controle la cantidad de depósitos a ingresar (especificada por el usuario)

2.-ValidarNumero(): Antes de asignar un depósito al arreglo se deberá verificar que el número de depósito no haya sido ingresado.
En caso de que exista, deberá ser solicitado nuevamente.

3.-consultarDeposito(): Deberá permitir que el ususario consulte por un deposito en base al número del mismo.

4.-mostrarPorcentaje():Deberá mostrar el porcentaje de deposito por tipo*/
#include <stdio.h>
#include <stdlib.h>
#define LARGO 10
int i;
int resp=0;
int comp;
int valor;
typedef struct Deposito{
	int numero;
	int dia;
	int monto;
	char tipo;
}Deposito;
void ingresarDeposito(Deposito*[],Deposito*);
//int validarNumero(Deposito*[],int);
void consultarDeposito(Deposito*[]);
//void mostarPorcentajesTipo(Deposito*[]);

void main(){
	Deposito dep;
	Deposito* abril[LARGO]={NULL};
	for(i=0;i<LARGO;i++){
		abril[i]=NULL;
	}
	ingresarDeposito(abril,&dep);
	consultarDeposito(abril);
}

void ingresarDeposito(Deposito* abr[],Deposito* dep){
	do{
		printf("\nIngrese numero del deposito: ");
		scanf("%i",&valor);
	
	}while(valor<0);
	dep->numero=valor;
	do{
		printf("\n¿Qué dia del mes es?: ");
		scanf("%i",&dep->dia);
	}while((dep->dia<0)||(dep->dia>32));
	do{
		printf("\nMonto del deposito: ");
		scanf("%i",&dep->monto);
	}while(dep->monto<1000);
	fflush(stdin);
	do{
		printf("\nIngresar Tipo del deposito (d:documento, e:efectivo): ");
		scanf("%c",&dep->tipo);
	}while((dep->tipo!='d')&&(dep->tipo!='e')&&(dep->tipo!='E')&&(dep->tipo!='D'));
	for(i=0;i<LARGO;i++){
		if(abr[i]==NULL){
			abr[i]=dep;
		}
	}
}
void consultarDepositos(Deposito* abr[]){
	comp=0;
	printf("\nQué deposito quiere consultar? ");
	scanf("%i",&valor);
	for(i=0;i<LARGO;i++){
		if(abr[i]!=NULL){
			if(abr[i]->numero==valor){
				printf("\nEl dia %i: Se realizo un deposito de $%i de tipo %i",abr[i]->dia,abr[i]->monto,abr[i]->tipo);
				comp=1;
			}
		}
	}
	if(comp==0){
		printf("\n\nNo se ha encontrado el deposito!!");
	}
}
