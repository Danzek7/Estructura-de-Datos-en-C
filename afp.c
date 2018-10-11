#include <stdio.h>
void main()
{
	typedef struct Afp{
		int	 codAfp;
		char nomAfp[10]; 
	}Afp;
	typedef struct Cotizante{
		int  codigo;
		int	 codAfp;
		char tipoCotiz[2];	
		int	 fondo;			
		int  region;	
	}Cotizante;
	Afp	afp[5]={{1033,"CAPITAL"},{1003,"CUPRUM"},{1005,"HABITAT"},{1032,"PLANVITAL"},{1008,"PROVIDA"},{1031,"MODELO"}};
	Cotizante cotiz[5000]={{10,1031,"D",10000000,5},{20,1003,"I",30000000,8},{30,1003,"D",25000000,5},{40,1003,"I",13000000,5},{50,1005,"D",17000000,3},{60,1033,"D",8000000,5}};
	
	int encontrada;
	int encontrada2;
	int encontrada3;
	int encontrada4;
	int encontrada5;
	int encontrada6;
	int cont;
	int codigo;
	int i;
	int totalD;
	int totalI;

	encontrada=0;
	encontrada2=0;
	encontrada3=0;
	encontrada4=0;
	encontrada5=0;
	encontrada6=0;
	cont=0;
	do{
	    if(!strcmp(afp[cont].nomAfp,"CAPITAL")){
			encontrada=1;
			codigo=afp[cont].codAfp;	
		}else
			cont++;
	}while(encontrada==0&&cont!=5); 
	do{
	    if(!strcmp(afp[cont].nomAfp,"CUPRUM")){
			encontrada2=1;
			codigo=afp[cont].codAfp;	
		}else
			cont++;
	}while(encontrada2==0&&cont!=5);
	do{
	    if(!strcmp(afp[cont].nomAfp,"HABITAT")){
			encontrada3=1;
			codigo=afp[cont].codAfp;	
		}else
			cont++;
	}while(encontrada3==0&&cont!=5);
	do{
	    if(!strcmp(afp[cont].nomAfp,"PLANVITAL")){
			encontrada4=1;
			codigo=afp[cont].codAfp;	
		}else
			cont++;
	}while(encontrada4==0&&cont!=5);
	do{
	    if(!strcmp(afp[cont].nomAfp,"PROVIDA")){
			encontrada5=1;
			codigo=afp[cont].codAfp;	
		}else
			cont++;
	}while(encontrada5==0&&cont!=5);
	do{
	    if(!strcmp(afp[cont].nomAfp,"MODELO")){
			encontrada6=1;
			codigo=afp[cont].codAfp;	
		}else
			cont++;
	}while(encontrada6==0&&cont!=5);
	
	if(encontrada==1){
	    printf("\nAfp CAPITAL. Codigo: %i",codigo);
    }
    if(encontrada2==1){
	    printf("\nAfp CUPRUM. Codigo: %i",codigo);
    }
    if(encontrada3==1){
	    printf("\nAfp HABITAT. Codigo: %i",codigo);
    }
    if(encontrada4==1){
	    printf("\nAfp PLANVITAL. Codigo: %i",codigo);
    }
    if(encontrada5==1){
	    printf("\nAfp PROVIDA. Codigo: %i",codigo);
    }
    if(encontrada6==1){
	    printf("\nAfp MODELO. Codigo: %i",codigo);
    }
	cont=0;
	for(i=0; i<5; i++){	    
		if(cotiz[i].codAfp==codigo&&cotiz[i].region==5){
			cont++;
		    }
		}
	printf("\nLa AFP CUPRUM posee %i afiliado(s) en la V region",cont);
	for(i=0; i<8; i++){	    //Existen datos de 3 afiliados en el arreglo de cotizantes
		if(cotiz[i].codAfp==codigo&&cotiz[i].region==8){
			cont++;
		    }
		}
	printf("\nLa AFP CUPRUM posee %i afiliado(s) en la VIII region",cont);
	for(i=0; i<3; i++){	    //Existen datos de 3 afiliados en el arreglo de cotizantes
		if(cotiz[i].codAfp==codigo&&cotiz[i].region==3){
			cont++;
		    }
		}
	printf("\nLa AFP CUPRUM posee %i afiliado(s) en la III region",cont);

	//Parte 2: Para cada tipo de cotizante (D o I), informe el monto total cotizado.
	totalD=0;
	totalI=0;
	for(i=0; i<5; i++)	//Existen datos de 3 afiliados en el arreglo de cotizantes
	{
	if(!strcmp(cotiz[i].tipoCotiz,"D")){
		totalD=totalD + cotiz[i].fondo;
	}else
		totalI=totalI + cotiz[i].fondo;
	}		
	printf("\nTotal cotizado por afiliados Dependientes es: $%i",totalD);	
	printf("\nTotal cotizado por afiliados Independientes es: $%i",totalI);
}
