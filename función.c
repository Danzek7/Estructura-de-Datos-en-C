#include <stdio.h>
void incrementar(int );
void main(){
	int i=5;
	printf("El valor de i es: %i",i);
	incrementar(i);
	printf("\nEl nuevo valor de i es: %i",i);
}
void incrementar(int num){
	printf("\nEl valor de num es: %i",num);
	num++;
	printf("\nEL nuevo valor de num es: %i",num);
}
