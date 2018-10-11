#include <stdio.h>
#include <stdlib.h>

int a[5];

void main(){
	int inicio;
	int fin;
	int n;
	int option;
	
	inicio=0;
	fin=0;
	n=0;
	
	do{
		printf("\n/////\nQue quieres hacer: ");
		do{
			printf("\n1:ingresar; 2:imprimir; 3:mostrar; 4:Quit ->");
			scanf("%i",&option);
			
			switch(option){
				case 1:
					if(n!=5){
						fin=(inicio+n)%5;
						printf("\nIngresa el dato: \n");
						scanf("%i",&a[fin]);
						n++;
					}else{
						printf("\nNo hay espacio suficiente\n");
					}
					break;
				
				case 2:
					if(n!=0){
						inicio=(inicio+1)%5;
						n--;
					}else{
						printf("\nLa cola esta completamente vacia\n");
					}
					break;
			
				case 3:
					if(inicio!=fin){
						printf("\n|%i|",a[inicio]);
					}else{
						printf("\nLa cola esta vacia\n");
					}
					break;
			
				default:
					break;
					
			}
		}while(option<1 || option>4);
	}while(option!=4);
}
