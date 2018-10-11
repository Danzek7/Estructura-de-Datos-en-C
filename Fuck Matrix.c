#include <stdio.h>
void main(){
	float M[3][3]={{5,0.4,0.2},{4,0.3,0.1},{3.5,0.5,0.2}};
	int P[3][3];
	float G[3][3];
	int i;
	int j;
	int k;
	int maq;
	float gasto;
	int min;
	float suma;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			do{
				printf("Ingrese P[%i,%i]: ",i,j);
				scanf("%i",&P[i][j]);
			}while(P[i][j]<=0);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			G[i][j]=0;
			for(k=0;k<3;k++){
				G[i][j]=G[i][j]+M[i][k]*P[k][j];
			}
			printf("\nG[%i,%i]: f",i,j,G[i][j]);
		}
	}
	do{
		printf("\nIngrese la maquina a consultar (1 - 2 - 3): ");
		scanf("%i",&maq);
	}while((maq<1)||(maq>3));
	gasto=G[maq-1][0];
	min=0;
	for(j=1;j<3;j++){
		if(G[maq-1][j]<gasto){
			gasto=G[maq-1][j];
			min=j;
		}
	}
	printf("\nEl proveedor mas conveniente es P%i",min);
	
}
