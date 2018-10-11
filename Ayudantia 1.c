/*En base al c�digo base: 
1.-ingresarDeposito(): Debe solicitar los datos de un dep�sito, con sus respectivas validaciones y asignando a la celda
que se encuentre disponible en un arreglo.
LA llamada a esta funci�n puede ser parte de un ciclo que controle la cantidad de dep�sitos a ingresar (especificada por el usuario)

2.-ValidarNumero(): Antes de asignar un dep�sito al arreglo se deber� verificar que el n�mero de dep�sito no haya sido ingresado.
En caso de que exista, deber� ser solicitado nuevamente.

3.-consultarDeposito():*/
#include<stdio.h>
#define LARGO 10
typedef struct Deposito{
	int num; //N�mero positivo. No se debe repetir
	int dia; //D�a del mes
	int monto; //Debe ser mayor a $1000
	char tipo; //D: documento, E: efectivo
}Deposito;
void ingresarDeposito(Deposito*[],Deposito*);
int validarNumero(Deposito*[],int);
void consultarDeposito(Deposito*[]);
void mostrarPorcentajesTipo(Deposito*[]);
void main(){
    Deposito dep;
    Deposito* abril[LARGO]={NULL}; //Arreglo de punteros a estructuras
    ingresarDeposito(abril,&dep);
}
void ingresarDeposito(Deposito* d[],Deposito* dp){
	int num;
	do{
	    printf("Ingrese el deposito: ");
	    scanf("%i",&dp->num);
	}while(dp->num<0);
	do{
	    printf("\nDia del mes: ");
	    scanf("%i",&dp->dia);
   }while((dp->dia<0)||(dp->dia>31));
   do{
	    printf("\nMonto del deposito (mayor a $1000): ");
	    scanf("%i",&dp->monto);
	}while(dp->monto<1000);
	do{
		printf("\nTipo de deposito (d:documento, e:efectivo): ");
		scanf("%i",&dp->tipo);
	}while((dp->tipo!='d')||(dp->tipo!='e'));
}
