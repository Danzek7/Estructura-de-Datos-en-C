#include <stdio.h>

void main(){
	int tam;
	int op;
	int n;
	int inicio;
	int fin;
	
	do{
		printf("\nLa cola es de tamanio: ");
		scanf("%i",&tam);
	}while(tam<1);
	
	int c[tam];
	inicio=0;
	fin=0;
	n=0;
	
	do{
		do{
			printf("\n _Que quiere hacer?: \n1.Anadir\n2.Imprimir\n3.mostrar\n4.Salir\nR: ");
			scanf("%i",&op);
		}while(op<1 || op>=5);
		switch(op){
			case 1:
				if(n!=tam){
					fin=(inicio+n)%tam;
					printf("\n V[%i]: ",fin);
					scanf("%i",&c[fin]);
					n++;
				}else{
					printf("\nLa cola esta completamente llena");
				}
				break;
			case 2:
				if(n!=0){
					inicio=(inicio+1)%tam;
					n--;
					printf("\nElemento eliminado");
				}else{
					fin=-1;
					printf("\nLa cola esta completamente vacia");
				}
				break;
			case 3:
				if(fin!=-1){
					printf("\n|%i|",c[inicio]);
				}else{
					printf("\nLa cola esta vacia");
				}
				break;
			case 4:
				break;
		}
	}while(op!=4);
}
