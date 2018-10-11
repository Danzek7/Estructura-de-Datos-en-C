#include <stdio.h>
#include <stdlib.h>

typedef struct CuentaBanco
{
	int  numero;
	int  saldo;
	char estado;
	struct CuentaBanco* sig;	//Este era el campo solicitado	
}Cuenta;


Cuenta* crearCuenta();
void asignarCuenta(Cuenta* [], Cuenta*);
int verificarCuenta(Cuenta* [], int);
int conectarACuenta(Cuenta* [], int);
int desconectarCuenta(Cuenta* [], int);
int bloquearCuenta(Cuenta* [], int);

void main()
{
	//Declaracion de variables
	Cuenta* sistema[5]={NULL};	
	Cuenta* cuenta;
	
	int numeroCta;
	int existeCta;
	int conexionCta;
	int desconexionCta;
	int bloqueoCta;
	int opcion;
	
	do
	{
		do
		{
			printf("\nBienvenido al Sistema\n");
			printf("\n (1) Asignar cuenta");	//Incluye crear cuenta
			printf("\n (2) Conectarse a la cuenta");
			printf("\n (3) Desconectarse de la cuenta");
			printf("\n (4) Bloquear una cuenta");
			printf("\n (5) Salir\n");
			printf("\n     Ingrese opcion: ");
			scanf("%i",&opcion);
		}while(opcion < 1 || opcion > 5);
	
		switch (opcion)
		{
			case 1: cuenta=crearCuenta();
					asignarCuenta(sistema,cuenta);
					break;
				
			case 2: do
					{
						printf("\nIngrese el numero de cuenta a conectar: ");
						scanf("%i",&numeroCta);
					}while(numeroCta <= 0);
					
					existeCta=verificarCuenta(sistema,numeroCta);
					
					if(existeCta)
					{
						conexionCta=conectarACuenta(sistema,numeroCta);
						
						if(conexionCta == 1)
							printf("\nLa conexion a la cuenta fue exitosa");
						if(conexionCta == 2)
							printf("\nLa cuenta se encuentra en uso, ya existe una conexi?n");
						if(conexionCta == 3)
							printf("\nLa cuenta esta bloqueda, no permite conexion");
					}
					else
						printf("\nLa cuenta a conectar No existe");
				
					break;
				
			case 3: do
					{
						printf("\nIngrese el numero de cuenta a desconectar: ");
						scanf("%i",&numeroCta);
					}while(numeroCta <= 0);
					
					desconexionCta=desconectarCuenta(sistema, numeroCta);
						
					if(desconexionCta)
						printf("\nDesconexion exitosa... ");
					else
						printf("\nLa cuenta no existe o no estaba en uso, desconexion no cursada");
					
					break;
		
			case 4: do
					{
						printf("\nIngrese el numero de cuenta a bloquear: ");
						scanf("%i",&numeroCta);
					}while(numeroCta <= 0);
					
					existeCta=verificarCuenta(sistema,numeroCta);
					
					if(existeCta)
					{
						bloqueoCta=bloquearCuenta(sistema, numeroCta);
						
						if(bloqueoCta == 0)
							printf("\nLa cuenta ya se encontraba bloqueada");
						if(bloqueoCta == 1)
							printf("\nLa cuenta se encuentra en uso, no puede ser bloqueada");
						if(bloqueoCta == 2)
							printf("\nBloqueo de cuenta exitoso");	
					}					
					else
						printf("\nLa cuenta a bloquear No existe");
					
					break;
				
			case 5: printf("\nGracias por preferirnos");
					break;
				
			default: printf("\n Algo anda mal...");
		}
	}while(opcion != 5);	
}

Cuenta* crearCuenta()
{
	Cuenta* cuenta;
	
	cuenta=(Cuenta*)malloc(sizeof(Cuenta));
			
	do
	{
		printf("\nIngrese el numero de cuenta: ");
		scanf("%i",&cuenta->numero);
	}while(cuenta->numero <=0);
	
	cuenta->saldo=0;
	cuenta->estado='D';
	cuenta->sig=NULL;
	
	return cuenta;
}

void asignarCuenta(Cuenta* sistema[5], Cuenta* cuenta)
{
	int posicion;
	Cuenta* aux1;
	Cuenta* aux2;
	
	posicion=cuenta->numero%5;
		
	if(sistema[posicion] == NULL)	
		sistema[posicion]=cuenta;
	else
	{
		aux1=sistema[posicion];
		aux2=NULL;
		while(aux1 != NULL)		
			if(aux1->numero <= cuenta->numero)
			{
				aux2=aux1;
				aux1=aux1->sig;
			}
			else
				aux1=NULL;
	
		if(aux2 == NULL)
		{
			cuenta->sig=sistema[posicion];
			sistema[posicion]=cuenta;
		}
		else
		{
			cuenta->sig=aux2->sig;				
			aux2->sig=cuenta;
		}				
	} 
}

int verificarCuenta(Cuenta* sistema[5], int nroCta)
{
	int posicion;
	Cuenta* aux;
	int existeCta;
	
	posicion=nroCta%5;
	existeCta=0;
	aux=sistema[posicion];
	
	while(aux != 0 && existeCta == 0)
	{
		if(aux->numero == nroCta)
			existeCta=1;
		else		
			aux=aux->sig;
	}
	
	return existeCta;
}

int conectarACuenta(Cuenta* sistema[5], int nroCta)
{
	int posicion;
	Cuenta* aux;
	
	posicion=nroCta%5;
	aux=sistema[posicion];
	
	while(aux->numero != nroCta)
		aux=aux->sig;
	
	if(aux->estado == 'D') 
	{
		aux->estado='U';
		return 1;
	}
	if(aux->estado == 'U') return 2;
	if(aux->estado == 'B') return 3;
}

int desconectarCuenta(Cuenta* sistema[], int nroCta)
{
	int posicion;
	Cuenta* aux;
	char estadoCta;
	
	posicion=nroCta%5;
	estadoCta='E';	//Valor referencial (de control), E de estado
	aux=sistema[posicion];
	
	while(aux != NULL && estadoCta == 'E')
	{
		if(aux->numero == nroCta)
			estadoCta=aux->estado;
		else		
			aux=aux->sig;
	}
	
	if(estadoCta == 'U') 
	{
		aux->estado='D';
		return 1;
	}
	else
		return 0;
}

int bloquearCuenta(Cuenta* sistema[5], int nroCta)
{
	int posicion;
	Cuenta* aux;
	
	posicion=nroCta%5;
	aux=sistema[posicion];
	
	while(aux->numero != nroCta)
		aux=aux->sig;
	
	if(aux->estado == 'B') return 0;
	if(aux->estado == 'U') return 1;
	if(aux->estado == 'D') 
	{
		aux->estado='B';
		return 2;
	}
}
