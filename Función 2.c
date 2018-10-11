#include <stdio.h> //paso por referencia
void incrementar(int*);
void main(){
	int i=5;
	printf("El valor de i es: %i",i);
	incrementar(&i);
	printf("\nEl nuevo valor de i es: %i",i);
}
void incrementar(int* num){
	printf("\nEL valor de num es: %i",*num);
	*num=*num+1;
	printf("\nEL nuevo valor de num es: %i",*num);
}
