#include <stdio.h>
struct Estr3{
	int a;
};
struct Estr2{
	int b;
	struct Estr3* ptr;
};
struct Estr1{
	int c;
	struct Estr2* ptr;
};
void main(){
	struct Estr1 dato1;
	struct Estr1* datoptr;
	struct Estr2 dato2;
	struct Estr3 dato3;
	
	dato1.c=30;
	dato2.b=20;
	dato3.a=10;
	
	datoptr=&dato1;
	dato1.ptr=&dato2;
	dato2.ptr=&dato3;
}
