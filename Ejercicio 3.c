#include <stdio.h>
#define SIZE 100
typedef struct InfoCelda{
	char nombre[SIZE];
	unsigned int idCelda;
	float calidad;
	struct InfoOperador* operador;
}InfoCelda;
typedef struct InfoOperador{
	char nombre[SIZE];
	unsigned int prioridad;
	unsigned int UltimaComprob;
}InfoOperador;
void main(){
	
}
