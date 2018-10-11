#include <stdio.h>

void ingresarLista(int[],int);
int unionSinDuplicados(int[],int,int[],int,int[]);
int unionConDuplicados(int[],int,int[],int,int[]);
int interseccionListas(int[],int,int[],int,int[]);
int restaListas(int[],int,int[],int,int[]);
int unionSinInterseccion(int[],int,int[],int,int[]);
void ordenarListaC(int[],int);
void mostrarLista(int[],int);

void main()
{
	int a[20];
	int b[20];
	int c[40];
	int longA;
	int longB;
	int longC;
	
	do
	{
		printf("Ingrese la cantidad de elementos de la Lista A (Maximo 20): ");
		scanf("%i",&longA);
	}while(longA < 1 || longA > 20);
		
	printf("\nIngrese los elementos de la Lista A: ");
	ingresarLista(a,longA);
	
	do
	{
		printf("\nIngrese la cantidad de elementos de la Lista B (Maximo 20): ");
		scanf("%i",&longB);
	}while(longB < 1 || longB > 20);
	
	printf("\nIngrese los elementos de la Lista B: ");
	ingresarLista(b,longB);
	
	printf("\n-- A U B (Sin duplicados) ==> ");
	longC=unionSinDuplicados(a, longA, b, longB, c);
	ordenarLista(c,longC);
	mostrarLista(c,longC);
	
	printf("\n-- A U B (Con duplicados) ==> ");
	longC=unionConDuplicados(a, longA, b, longB, c);
	ordenarLista(c,longC);
	mostrarLista(c,longC);
	
	printf("\n-- A interseccion B ==> ");
	longC=interseccionListas(a, longA, b, longB, c); 
	if(longC == 0)
		printf("Interseccion de las Listas A y B es vacia");
	else	
	{
		ordenarLista(c,longC);
		mostrarLista(c,longC);
	}
		
	printf("\n-- A - B ==> ");
	longC=restaListas(a, longA, b, longB, c); 
	if(longC == 0)
		printf("No existen valores exclusivos en A");
	else	
	{
		ordenarLista(c,longC);
		mostrarLista(c,longC);
	}
		
	printf("\n-- (A U B) - (A interseccion B) ==> ");
	longC=unionSinInterseccion(a, longA, b, longB, c); 
	ordenarLista(c,longC);
	mostrarLista(c,longC);		
}

void ingresarLista(int v[], int largo)
{
	int i;
	int orden;

	do
	{
		orden=1;
		i=0;
		do
		{
			printf("\nLista[%i]: ",i+1);
			scanf("%i",&v[i]);
			
			if(i>0 && v[i]<v[i-1])
			{
				printf("\nDebe ingresar los elementos de la lista en orden...Ingrese nuevamente");
				orden=0;
			}
			else
				i++;
		}while(orden == 1 && i<largo);		
	}while(orden != 1);
}

int unionSinDuplicados(int listaA[], int largoA, int listaB[], int largoB, int listaC[])
{
	int i;
	int j;
	int largoC;
	int repetido;
	
	for(i=0; i<largoA; i++)
		listaC[i]=listaA[i];
		
	largoC=largoA-1;
	j=0;
	
	do
	{
		i=0;
		repetido=0;
		do
		{
			if(listaB[j] == listaA[i])
				repetido=1;
			else
				i++;
		}while(repetido==0 && i<largoA);
		
		if(repetido == 0)
		{
			largoC++;
			listaC[largoC]=listaB[j];
		}
		
		j++;		
	}while(j <= largoB);
	
	return largoC;
}

int unionConDuplicados(int listaA[], int largoA, int listaB[], int largoB, int listaC[])
{
	int i;
	int largoC;
		
	for(i=0; i<largoA; i++)
		listaC[i]=listaA[i];
		
	largoC=largoA;
	
	for(i=0; i<largoB; i++)
	{
		listaC[largoC]=listaB[i];
		largoC++;
	}
			
	return largoC;
}

int interseccionListas(int listaA[], int largoA, int listaB[], int largoB, int listaC[])
{
	int i;
	int j;
	int largoC;
	
	i=0;
	largoC=0;
	do
	{
		j=0;
		do
		{
			if(listaA[i] == listaB[j])
			{
				listaC[largoC]=listaA[i];
				largoC++;
			}
			j++;
		}while(j<largoB);
		i++;
		
	}while(i<=largoA);
	
	return largoC;
}

int restaListas(int listaA[], int largoA, int listaB[], int largoB, int listaC[])
{
	int i;
	int j;
	int largoC;
	int repetido;
	
	i=0;
	largoC=0;
	do
	{
		repetido=0;
		j=0;
		do
		{
			if(listaA[i] == listaB[j])
				repetido=1;
			else
				j++;
		}while(repetido==0 && j<largoB);
		
		if(repetido == 0)
		{
			listaC[largoC]=listaA[i];
			largoC++;			
		}
		
		i++;
		
	}while(i<largoA);
	
	return largoC;
}

int unionSinInterseccion(int listaA[], int largoA, int listaB[], int largoB, int listaC[])
{
	int i;
	int j;
	int largoInter;
	int listaInter[40];
	int largoC;
	int repetido;
	
	largoInter=interseccionListas(listaA, largoA, listaB, largoB, listaInter); 
	
	if(largoInter == 0)	//Como la intersecci?n es vac?a hace un traspaso directo de los datos
	{
		for(i=0; i<largoA; i++)
			listaC[i]=listaA[i];
			
		largoC=largoA;
		
		for(i=0; i<largoB; i++)
		{
			listaC[largoC]=listaB[i];
			largoC++;
		}	
	}
	else
	{
		i=0;
		largoC=0;
		do
		{
			repetido=0;
			j=0;
			do
			{
				if(listaA[i] == listaInter[j])
					repetido=1;
				else
					j++;
			}while(repetido==0 && j<largoInter);
		
			if(repetido == 0)
			{
				listaC[largoC]=listaA[i];
				largoC++;			
			}
			i++;		
		}while(i<largoA);
		
		i=0;
	
		do
		{
			repetido=0;
			j=0;
			do
			{
				if(listaB[i] == listaInter[j])
					repetido=1;
				else
					j++;
			}while(repetido==0 && j<largoInter);
		
			if(repetido == 0)
			{
				listaC[largoC]=listaB[i];
				largoC++;			
			}
			i++;		
		}while(i<largoB);
	}
	return largoC;
}

void ordenarLista(int lista[], int largo) //M?todo de la Burbuja
{
	int i;
	int j;
	int aux;
	
	j=largo-1;
	while(j != 0)
	{
		i=0;
		while(i < j)
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

void mostrarLista(int lista[], int largo)
{
	int i;
	
	printf("| ");
	for(i=0; i<largo; i++)
		printf("%i | ",lista[i]);
}
