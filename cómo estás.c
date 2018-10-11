#include <stdio.h>
void main(){
	char estado[10];
	printf("¿Como estas?: \n");
	scanf("%s",&estado);
	if(!strcmp(estado,"bien")){
		printf("\nExcelente");
	}
	if(!strcmp(estado,"mal")){
		printf("\nMuy mal");
	}
}
