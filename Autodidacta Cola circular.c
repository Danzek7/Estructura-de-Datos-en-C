#include <stdio.h>
#include <stdlib.h>

void main(){
	int tam;
	int ini;
	int fin;
	int n;
	int caso;
	
	do{
		printf("El tamanio de la cola es: ");
		scanf("%i",&tam);
	}while(tam<1);
	
	int v[tam];
	
	ini=0;
	fin=0;
	n=0;
	
	do{
		do{
			printf("\n-----------------------\nQue desea hacer?:\n1.Encolar\n2.Desencolar\n3.Mostrar\n4.Quitar\nR: ");
			scanf("%i",&caso);
		}while(caso<1 || caso>4);
		
		switch(caso){
			case 1:
				if(n!=tam){
					fin=(ini+n)%tam;
					printf("\nIngrese el dato %i: ",fin+1);
					scanf("%i",&v[fin]);
					n++;
				}else{
					printf("\nNo hay espacio suficiente");
				}
				break;
			case 2:
				if(n!=0){
					ini=(ini+1)%tam;
					n--;
				}else{
					printf("\nLa lista esta completamente vacia");
				}		
				break;
			case 3:
				if(ini!=fin){
					printf("\nEl primer valor de la cola es: |%i|",v[ini]);
				}else{
					printf("\nLa cola esta totalmente vacia");
				}
				break;
			case 4:
				break;
		}
	}while(caso!=4);
}
