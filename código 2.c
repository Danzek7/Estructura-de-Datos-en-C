#include<stdio.h>
struct Package{
	int q;
};
void cambiarValor(struct Package*,int);
void main(){
	struct Package p;
	p.q=10;
	cambiarValor(&p,20);
	printf("p.q es: %i",p.q);
}
void cambiarValor(struct Package* dato, int valor){
	dato->q=valor;
}
