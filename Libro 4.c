#include <stdio.h>
#include <stdlib.h>

void ingresarLista(int[],int);
int unionSinDuplicados(int[],int,int[],int,int[]);
void ordenarLista(int[], int);

void main()
{
	int a[20];
	int b[20];
	int c[20];
	int longA;
	int longB;
	int longC;
	
	do
	{
		printf(" Ingrese el tamanio de la lista A: ");
		scanf("%i",&longA);
	}while(longA<1);
	
	printf("\n Lista A: ");
	ingresarLista(a,longA);
	
	do
	{
		printf("\n Ingrese el tamanio de la lista B: ");
		scanf("%i",&longB);
	}while(longB<1);
	
	printf("\n Lista B: ");
	ingresarLista(b,longB);
	
	printf("\n C= AUB (sin duplicados): ");
	longC=unionSinDuplicados(a,longA,b,longB,c);
	ordenarLista(c,longC);
}

void ingresarLista(int vec[], int tam)
{
	int i;
	int orden;
	
	do
	{
		orden=1;
		i=0;
		do
		{
			printf("\nVector[%i]: ",i+1);
			scanf("%i",&vec[i]);
			
			if(i>0 && vec[i]<vec[i-1])
			{
				printf("\nVuelva a ingresar la lista nuevamente.");
				orden=0;
			}else
			{
				i++;
			}
		}while(orden==1 && i<tam);
	}while(orden!=1);
	
}

int unionSinDuplicados(int a[],int longA,int b[],int longB,int c[])
{
	int i;
	int j;
	int longC;
	int repetido;
	
	for(i=0;i<longA;i++)
	{
		c[i]=a[i];
	}
	
	longC=longA-1;
	j=0;
	
	do
	{
		i=0;
		repetido=0;
		do
		{
			if(b[j]==a[i])
			{
				repetido=1;
			}else
			{
				i++;
			}
		}while(repetido==0 && i<longA);
		
		if(repetido==0)
		{
			longC++;
			c[longC]=b[j];
		}
		j++;
	}while(j<=longB);
	
	return longC;
}

void ordenarLista(int lista[], int largo)
{
	int i;
	int j;
	int aux;
	
	j=largo-1;
	while(j!=0)
	{
		i=0;
		while(i<j)
		{
			if(lista[i]>lista[i+1])
			{
				aux=lista[i];
				lista[i]=lista[i+1];
				lista[i+1]=aux;
			}
			i++;
		}
		j--;
	}
}
