//Esta incompleto el ejercicio, tengo una duda sobre un apartado de este ejercicio
#include <stdio.h>
#include <stdlib.h>//esto es nuevo
#define largo 10
int resp=0;
int valor;
int i;
int comp;
int contador;
typedef struct Deposito{
    int numero;
    int dia;
    int monto;
    char tipo;
}Deposito;

void ingresarDeposito(Deposito*[]);
int validarNumero(Deposito*[],int);
void consultarDeposito(Deposito* []);
void mostrarPorcentajesTipo(Deposito* []);
Deposito* crearNodo(Deposito* []);
void MostrarTodo(Deposito* []);
void main(){
    //Deposito dep;
    Deposito* abril[largo]={NULL};// es importante,siempre hay algo
    for(i=0;i<largo;i++){// es lo mismo que arriba
        abril[i]=NULL;
    }
    /*ingresarDeposito(abril,&dep);
    consultarDeposito(abril);
    mostrarPorcentajesTipo(abril);*/
    do{
        do{
            printf("\n1_Ingresar Deposito\n2_Consultar Deposito\n3_Mostrar Porcentaje\n4_Consultar Todo\n5_Salir\n");
            scanf("%i",&i);
        }while(i<0 || i>5);
        switch (i){
            case 1 :
                ingresarDeposito(abril);
                break;
            case 2 :
                consultarDeposito(abril);
                break;
            case 3 :
                mostrarPorcentajesTipo(abril);
                break;
            default :
                MostrarTodo(abril);
                break;
        }
    }while(i!=5);
}

Deposito* crearNodo(Deposito* arreglo[]){
    Deposito* nuevo;
    int valor;
    nuevo=malloc(sizeof(Deposito));
    do{
        printf("Ingresar nro de deposito : ");
        scanf("%i",&valor);
        resp = validarNumero(arreglo,valor);
    }while(resp == 1);
    printf("Paso");
    nuevo->numero = valor;
    do{
        printf("Ingresar el monto : ");
        scanf("%i",&nuevo->monto);
    }while(nuevo->monto < 0);

    do{
        printf("Ingresar el dia : ");
        scanf("%i",&nuevo->dia);
    }while(nuevo->dia < 0 && nuevo->dia > 32);

    fflush(stdin);//limpiar buffer
    do{
        printf("Ingresar el tipo : ");
        scanf("%c",&nuevo->tipo);
    }while(nuevo->tipo != 'D' && nuevo->tipo != 'E');
    return nuevo;

}

void ingresarDeposito(Deposito* arreglo[]){
/*
    do{
        printf("Ingresar nro de deposito : ");
        scanf("%i",&valor);
        resp = validarNumero(arreglo,valor);
    }while(resp == 1);
    printf("Paso");
    caja->numero = valor;
    do{
        printf("Ingresar el monto : ");
        scanf("%i",&caja->monto);
    }while(caja->monto < 0);

    do{
        printf("Ingresar el dia : ");
        scanf("%i",&caja->dia);
    }while(caja->dia < 0 && caja->dia > 32);

    fflush(stdin);//limpiar buffer
    do{
        printf("Ingresar el tipo : ");
        scanf("%c",&caja->tipo);
    }while(caja->tipo != 'D' && caja->tipo != 'E');
*/
//creamos un puntero de tipo deposito, que nos tome el valor retornado por la funcion
    Deposito* aux;
    aux=crearNodo(arreglo);
    for(i=0;i<largo;i++){
        if(arreglo[i]== NULL){
            arreglo[i] = aux;
            break;//tambien se podia asignar a i como 10,ocupar el break no es muy correcto
        }
    }
}

int validarNumero(Deposito* arreglo[],int comp){
    for(i=0;i<=largo;i++){
        if(arreglo[i]!= NULL){//es incorrecto : arreglo[i]->numero == comp sin antes ver si es null
            if(arreglo[i]->numero == comp){
                return 1;//si el dato existe retornara 1
            }
        }
    }
    return 0;//no encontro el dato
}

void consultarDeposito(Deposito* arreglo[]){
    comp=0;
    printf("�Que deposito quieres consultar?");
    scanf("%i",&valor);

    for(i=0;i<largo;i++){
        if(arreglo[i]!= NULL ){//importante, o se rompe
            if(arreglo[i]->numero == valor){
                printf("\nEl dia : %i se realizo un deposito de $ %i de tipo : %i",arreglo[i]->dia,arreglo[i]->monto,arreglo[i]->tipo);
                comp=1;
            }
        }
    }
    if(comp==0){
        printf("!!NO SE HA ENCONTRADO EL DEPOSITO!!\n\n");
    }
}

void mostrarPorcentajesTipo(Deposito* arreglo[]){
    contador=0;
    for(i=0;i<largo;i++){
        if(arreglo[i]!= NULL ){//importante, o se rompe
            if(arreglo[i]->tipo == 'D'){
                contador++;
            }
        }
    }
    contador=contador*10;//no es lo correcto, pero son 10 por lo tanto no hay problemas
    printf("\nEl %i  porciento corresponde a documentos ",contador);
}

void MostrarTodo(Deposito* arreglo[]){
    for(i=0;i<largo;i++){
        if(arreglo[i]!= NULL ){//importante, o se rompe
            printf("\n\nEl dia : %i se realizo un deposito de $ %i de tipo : %c \n\n",arreglo[i]->dia,arreglo[i]->monto,arreglo[i]->tipo);
        }
    }
}
