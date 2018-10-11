#include <stdio.h>

void main(){
	struct Producto{
		int codigo;
		char desc[100];
		int precio;
		int stock
	};
	struct Producto p;
    p.codigo=777;
    strcpy(p.desc,"Super 8");
    p.precio=300;
    p.stock=1000;
    printf("Codigo del producto: %i",p.codigo);
    printf("\nDescripcion del producto: %s",p.desc);
    printf("\nPrecio del producto: $%i",p.precio);
    printf("\nstock del producto: %i",p.stock);
}
