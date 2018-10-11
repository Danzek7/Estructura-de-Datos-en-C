#include <stdio.h>
void mostrar(char stas[]);
void main(){
	char estado[10];
	printf("¿Como estas?: \n");
    scanf("%s",&estado);
	mostrar(estado);
}
void mostrar(char stas[]){
	if(!strcmp(stas,"bien")){
		printf("\nExcelente");
	}
	if(!strcmp(stas,"mal")){
		printf("\nMuy mal");
	}
}
