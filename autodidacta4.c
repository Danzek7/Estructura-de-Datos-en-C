#include <stdio.h>
int i;
typedef struct Inocente{
	int campo1;
	float campo2;
	struct Inocente* Siguiente;
}Inocente;
typedef struct Siguiente{
	struct Siguiente* Siguiente2;
}Siguiente;
typedef struct Siguiente2{
	int a;
}Siguiente2;
void main(){
	Inocente in;
	Siguiente sig;
	Siguiente2 sig2;
}
