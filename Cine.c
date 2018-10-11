#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Asistente
{
	int numSala;
	int numero;
	int pago;
	int recibo;
	float horaTran;
	float horaIng;
	struct Fila* sig;
}NodoRegistro;

typedef struct Salas
{
	int numSala;
	int capacidad;
	char pelicula[20];
	char genero[20];
	int clasificacion;
	int duracion;
	NodoRegistro* Asistente;
}NodoSala;

void definirSalas(NodoSala* []);
void listaAsistentes(NodoSala* [], NodoRegistro* , int );
NodoRegistro* venderEntrada(NodoRegistro* , NodoSala* [], int , char funcion[10], int , int );
void ingresarSala(NodoSala* []);
NodoRegistro* crearNodo();
NodoSala* crearNodoSala();

void main()
{
	NodoSala* arraySalas[5]={NULL};
	NodoRegistro* ini;
	int n;
	int hora;
	int op;
	
	n=0;
	hora=600;
	
	do
	{
		do
		{
			printf("\n-->>>Que desea hacer? : ");
			printf("\n1.Definir Sala");
			printf("\n2.Vender entrada");
			printf("\n3.Ingresar a sala");
			printf("\n4.Terminar Funcion");
			printf("\n5.Salir");
			printf("\nR: ");
			scanf("%i",&op);
		}while(op<1 || op>5);
		
		switch(op)
		{
			case 1:
				definirSalas(arraySalas);
				n=1;
				break;
			case 2:
				if(n!=1)
				{
					printf("\nprimero ingrese los datos de las respectivas salas");
				}else
				{
					listaAsistentes(arraySalas,ini,hora);
				}
				break;
			case 3:
				ingresarSala(arraySalas);
				break;
			case 4:
				break;
			case 5:
				break;	
		}
	}while(op!=5 || hora>2400);
	
}

NodoRegistro* crearNodo()
{
	NodoRegistro* nodo;
	nodo=(NodoRegistro*)malloc(sizeof(NodoRegistro));
	nodo->sig=NULL;
	return nodo;
}

NodoSala* crearNodoSala()
{
	NodoSala* nodo;
	nodo=(NodoSala*)malloc(sizeof(NodoSala));
	return nodo;
}

void listaAsistentes(NodoSala* arraySalas[], NodoRegistro* inicio, int hora)
{
	NodoSala* sala;
	NodoSala* resc;
	NodoRegistro* fin;
	int i;
	int enc;
	int op;
	int cant;
	int pelicula;
	int pago;
	char funcion[20];
	
	i=0;
	enc=0;
	inicio=NULL;
	
	do
	{
		printf("\n\n --> Ingrese pelicula seleccionada por el cliente");
		printf("\n 1.Mision Imposible 6 - valor:$100");
		printf("\n 2.Hotel Transilvania 3 - valor:$100");
		printf("\n 3.Jurasic World 2 - valor:$100");
		printf("\n 4.12 horas - valor:$100");
		printf("\n 5.Christopher Robin - valor:$100");
		printf("\n R: ");
		scanf("%i",&pelicula);
	}while(pelicula<1 || pelicula>5);
		
	do
	{
		printf("\n Cuantas entradas desea comprar (max. 3)?: ");
		scanf("%i",&cant);
	}while(cant<1 || cant>3);
	
	if(pelicula==1)
	{
		strcpy(funcion,"Mision Imposible 6");
		pago=100;
	}
	if(pelicula==2)
	{
		strcpy(funcion,"Hotel Transilvania 3");
		pago=100;
	}
	if(pelicula==3)
	{
		strcpy(funcion,"Jurasic World 2");
		pago=100;
	}
	if(pelicula==4)
	{
		strcpy(funcion,"12 horas");
		pago=100;
	}
	if(pelicula==5)
	{
		strcpy(funcion,"Christopher Robin");
		pago=100;
	}
	
	do
	{
		sala=arraySalas[i];
		resc=sala;
		
		if(!strcmp(sala->pelicula,funcion))
		{
			enc=1;
		}else
		{
			i++;
		}
	}while(enc==0);
	
	if(sala->capacidad>0)
	{
		inicio=venderEntrada(inicio,arraySalas,pago,funcion,cant,hora);
		
		if(sala->Asistente==NULL)
		{
			sala->Asistente=inicio;
			resc->Asistente=sala->Asistente;
		}else
		{
			while(resc->Asistente->sig!=NULL)
			{
				resc->Asistente=resc->Asistente->sig;
			}
			
			resc->Asistente->sig=inicio;
			resc->Asistente=resc->Asistente->sig;
		}
		sala->capacidad--;
	}else
	{
		printf("\nLa sala ya esta llena");
	}
	printf("\n");
}

void definirSalas(NodoSala* Salas[])
{
	int i;
	int j;
	int pelicula;
	int enc1;
	int enc2;
	int enc3;
	int enc4;
	int enc5;
	
	enc1=0;
	enc2=0;
	enc3=0;
	enc4=0;
	enc5=0;

	for(i=0;i<5;i++)
	{
		Salas[i]=crearNodoSala();
		do
		{
			printf("\n\nSala %i: ",i+1);
			Salas[i]->numSala=i;
			do
			{
				printf("\n--> La pelicula estrenada en la sala %i es: ");
				printf("\n 1.Mision Imposible 6");
				printf("\n 2.Hotel Transilvania 3");
				printf("\n 3.Jurasic World 2");
				printf("\n 4.12 horas");
				printf("\n 5.Christopher Robin");
				printf("\n -->(Recuerde no seleccionar mas de una pelicula para una sala)<-- ");
				printf("\n R: ");
				scanf("%i",&pelicula);
			}while(pelicula<1 || pelicula>5);
			
			if(pelicula==1)
			{
				if(enc1!=0)
				{
					printf("\nVuelva a seleccionar la pelicula en OTRA SALA");
				}else
				{
					fflush(stdin);
					strcpy(Salas[i]->pelicula,"Mision Imposible 6");
					strcpy(Salas[i]->genero,"Accion");
					Salas[i]->clasificacion=14;
					Salas[i]->duracion=130;
					enc1++;
				}
			}
			if(pelicula==2)
			{
				if(enc2!=0)
				{
					printf("\nVuelva a seleccionar la pelicula en OTRA SALA");
				}else
				{
					fflush(stdin);
					strcpy(Salas[i]->pelicula,"Hotel Transilvania 3");
					strcpy(Salas[i]->genero,"Comedia");
					Salas[i]->clasificacion=0;
					Salas[i]->duracion=130;
					enc2++;
				}
			}
			
			if(pelicula==3)
			{
				if(enc3!=0)
				{
					printf("\nVuelva a seleccionar la pelicula en OTRA SALA");
				}else
				{
					fflush(stdin);
					strcpy(Salas[i]->pelicula,"Jurasic World 2");
					strcpy(Salas[i]->genero,"Ciencia Ficcion");
					Salas[i]->clasificacion=7;
					Salas[i]->duracion=130;
					enc3++;
				}
			}
			if(pelicula==4)
			{
				if(enc4!=0)
				{
					printf("\nVuelva a seleccionar la pelicula en OTRA SALA");
				}else
				{
					fflush(stdin);
					strcpy(Salas[i]->pelicula,"12 Horas");
					strcpy(Salas[i]->genero,"Accion");
					Salas[i]->clasificacion=14;
					Salas[i]->duracion=130;
					enc4++;
				}
			}
			if(pelicula==5)
			{
				if(enc5!=0)
				{
					printf("\nVuelva a seleccionar la pelicula en OTRA SALA");
				}else
				{
					fflush(stdin);
					strcpy(Salas[i]->pelicula,"Christopher Robin");
					strcpy(Salas[i]->genero,"Fantasia");
					Salas[i]->clasificacion=0;
					Salas[i]->duracion=130;
					enc5++;
				}
			}
		}while(enc1==0 && enc2==0 && enc3==0 && enc4==0 && enc5==0);
	}
	Salas[0]->capacidad=5;
	Salas[1]->capacidad=4;
	Salas[2]->capacidad=3;
	Salas[3]->capacidad=2;
	Salas[4]->capacidad=6;
	
	for(j=0;j<5;j++)
	{
		Salas[j]->Asistente=NULL;
	}

	printf("\n");
}

NodoRegistro* venderEntrada(NodoRegistro* ini, NodoSala* array[], int pago, char funcion[10], int cant, int hora)
{
	NodoSala* arraySala;
	NodoRegistro* fin;
	NodoRegistro* nodo;
	int i;
	int j;
	
	
	for(i=0;i<cant;i++)
	{
		nodo=crearNodo();
		nodo->numero=i+1;
		
		for(j=0;j<5;j++)
		{
			arraySala=array[j];
			if(!strcmp(arraySala->pelicula,funcion))
			{
				nodo->numSala=arraySala->numSala;
				do
				{
					printf("\nIngrese el pago correspondiente al precio: ");
					scanf("%i",&nodo->pago);
					hora=hora++;
				}while(nodo->pago<=pago);
				
				if(nodo->pago>pago)
				{
					nodo->recibo=nodo->pago-pago;
					hora=hora++;
					nodo->horaTran=hora;
					nodo->horaIng=0;
				}else
				{
					nodo->recibo=0;
					hora=hora++;
					nodo->horaTran=hora;
					nodo->horaIng=0;
				}
				printf("\n-------");
				printf("\n -->Pelicula: %s",funcion);
				printf("\n Sala: %i",nodo->numSala);
				printf("\n Entrada nro %i",nodo->numero);
				printf("\n Pago: $%i",nodo->pago);
				printf("\n Recibo: $%i",nodo->recibo);
				printf("\n Hora de transaccion: %i",nodo->horaTran);
				printf("\n Hora de ingreso: %i",nodo->horaIng);
				printf("\n-------");
			}
		}	
			
		if(ini==NULL)
		{
			ini=nodo;
			fin=ini;
		}else
		{
			fin->sig=nodo;
			fin=nodo;
		}
	}
	
	fin->sig=NULL;
	
	printf("\n");
	return ini;
}

void ingresarSala(NodoSala* array[])
{
	NodoSala* listaIngreso[5];
	NodoSala* auxTot;
	NodoSala* auxLista;
	NodoSala* headSala;
	NodoSala* ColaSala;
	NodoRegistro* Asis;
	int numSala;
	int total;
	int i;
	int j;
	
	total=0;
	headSala=NULL;
		
	do
	{
		printf("\n--> Sala: ");
		scanf("%i",&numSala);
	}while(numSala<1 || numSala>5);
	
	Asis->numSala=numSala-1;
	
	for(i=0;i<5;i++)
	{
		listaIngreso[i]=crearNodoSala();
		
		if(listaIngreso[i]->numSala == Asis->numSala)
		{
			auxTot=listaIngreso[i];
			
			while(auxTot->Asistente->sig!=NULL)
			{
				total++;
				auxTot->Asistente=auxTot->Asistente->sig;
			}
		}
	}
	
	for(i=0;i<5;i++)
	{
		ColaSala=array[i];
		
		if(headSala==NULL)
		{
			headSala=array[i];
		}
	}

	do
	{
		printf("\n--> Numero: ");
		scanf("%i",&Asis->numero);
	}while(Asis->numero<1 || Asis->numero>total);
	
	for(i=0;i<5;i++)
	{
		auxLista=array[i];
	
		for(j=0;j<5;j++)
		{
			if(auxLista->numSala == Asis->numSala)
			{
				printf("\n");
			}
		}
	}
}
