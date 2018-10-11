#include <stdio.h>

void main(){
	int tam;
	int op;
	int ini;
	int fin;
	int n;
	
	ini=0;
	fin=0;
	n=0;
	
	do{
		printf("\nDe que tamanio sera la cola: ");
		scanf("%i",&tam);
	}while(tam<1);
	
	int v[tam];
	
	do{
		do{
			printf("\nQue operacion desea realizar?:\n1.Anadir\n2.Eliminar\n3.Mostrar\n4.Quit\nR: ");
			scanf("%i",&op);
		}while(op<1 || op>4);
		
		switch(op){
			case 1:
				if(n!=tam){
					fin=(ini+n)%tam;
					printf("\n V[%i]: ",n);
					scanf("%i",&v[fin]);
					n++;
				}else{
					printf("\nLa cola esta completamente llena");
				}
				break;
			case 2:
				if(n!=0){
					ini=(ini+1)%tam;
					n--;
					printf("\nElemento eliminado");
				}else{
					printf("\nLa lista esta completamente vacía");
					fin=-1;
				}
				break;
			case 3:
				if(fin!=-1){
					printf("\n Front: |%i|",v[ini]);
				}else{
					printf("\nError");
				}
				break;
			case 4:
				break;
		}
	}while(op!=4);
}
