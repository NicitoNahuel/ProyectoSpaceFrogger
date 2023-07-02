#include <stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<windows.h>
#define color SetConsoleTextAttribute
using namespace std;

//EL SIGUIENTE CODIGO DUELE A LA VISTA PERO LA PROFESORA RITA FASOLINO LO ABALO / ACEPTA QUE ES LA MEJOR MANERA DE HACERLO.

int i, j, p, q;

//meteoritos
int linea1[15]{254,254,254,176,176,176,254,254,254,176,176,254,254,176,176}; 
int linea2[15]{254,254,176,176,176,176,254,254,176,176,176,254,254,176,176};
int linea3[15]{176,254,254,254,176,176,254,254,254,176,176,176,254,254,176};
int linea4[15]{176,176,254,254,176,254,254,254,176,176,176,254,254,176,176};
int linea5[15]{254,176,176,176,176,254,254,254,254,176,176,176,254,254,254};


//naves
int linea6[15]{178,178,178,178,178,178,175,175,178,178,178,178,178,175,175};
int linea7[15]{178,178,178,178,178,178,174,178,178,178,178,178,178,178,178};
int linea8[15]{178,178,178,178,178,178,175,178,178,178,175,178,178,178,175};
int linea9[15]{174,178,178,178,174,178,178,178,174,178,178,178,178,178,178};
int linea10[15]{175,178,178,178,175,178,178,178,175,178,178,178,178,178,178};

//Intermedio y arranque
int sf1[15]{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219};
//Meta
int sf2[15]{219,219,223,219,223,219,223,219,223,219,223,219,223,219,219};

void mapa()
{
	HANDLE lol;
	lol =  GetStdHandle(STD_OUTPUT_HANDLE);
	

		for(i=0;i<15;i++)
		{
			color(lol,2); //Cambiar color
			printf("%c", sf2[i]); //Imprimir Meta
		}
		printf("\n");
		
		//Imprimir otras lineas
		for(i=0;i<15;i++)
		{
			
			if(linea1[i]==254)
			{
				color(lol,6); //Cambiar el color si es obstaculo
			}
			else if(linea1[i] == 176)
			{
				color(lol,3); //Cambiar el color si es suelo
			}
			printf("%c", linea1[i]); //Imprimir linea
		}
		printf("\n"); //Salto
		for(i=0;i<15;i++)
		{
			if(linea2[i]==254)
			{
				color(lol,6);
			}
			else if(linea2[i] == 176)
			{
				color(lol,3);
			}
			printf("%c", linea2[i]);
		}
		printf("\n");
		for(i=0;i<15;i++)
		{
			if(linea3[i]==254)
			{
				color(lol,6);
			}
			else if(linea3[i] == 176)
			{
				color(lol,3);
			}
			printf("%c", linea3[i]);
		}
		printf("\n");
		for(i=0;i<15;i++)
		{
			if(linea4[i]==254)
			{
				color(lol,6);
			}
			else if(linea4[i] == 176)
			{
				color(lol,3);
			}
			printf("%c", linea4[i]);
		}
		printf("\n");
		for(i=0;i<15;i++)
		{
			if(linea5[i]==254)
			{
				color(lol,6);
			}
			else if(linea5[i] == 176)
			{
				color(lol,3);
			}
			printf("%c", linea5[i]);
		}
		
		printf("\n");
		
		for(i=0;i<15;i++)
		{
			color(lol,2); //Color del intermedio
			printf("%c", sf1[i]); //Imprimir intermedio
		}
		
		printf("\n");
		
		for(i=0;i<15;i++)
		{
			if(linea6[i]==178)
			{
				color(lol,15);
			}
			else if(linea6[i] == 175)
			{
				color(lol,4);
			}
			printf("%c", linea6[i]);
		}
		
		printf("\n");
		
		for(i=0;i<15;i++)
		{
			if(linea7[i]==178)
			{
				color(lol,15);
			}
			else if(linea7[i] == 174)
			{
				color(lol,4);
			}
			printf("%c", linea7[i]);
		}	
			
		printf("\n");
		
		for(i=0;i<15;i++)
		{
			if(linea8[i]==178)
			{
				color(lol,15);
			}
			else if(linea8[i] == 175)
			{
				color(lol,4);
			}
			printf("%c", linea8[i]);
		}		
		
		printf("\n");
		
		for(i=0;i<15;i++)
		{
			if(linea9[i]==178)
			{
				color(lol,15);
			}
			else if(linea9[i] == 174)
			{
				color(lol,4);
			}
			printf("%c", linea9[i]);
		}		
		
		printf("\n");
		
		for(i=0;i<15;i++)
		{
			if(linea10[i]==178)
			{
				color(lol,15);
			}
			else if(linea10[i] == 175)
			{
				color(lol,4);
			}
			printf("%c", linea10[i]);
		}		
		
		printf("\n");
		
		for(i=0;i<15;i++)
		{
			color(lol,2); //Color de la zona de inicio
			printf("%c", sf1[i]); //Imprimir zona de inicio
		}		
	
		for(p=0;p<15;p++)	//actualizar lineas una posicion hacia la derecha
		{
			if(p==0)
			{
				linea1[15] = linea1[0];
				linea3[15] = linea3[0];
				linea5[15] = linea5[0];
				linea7[15] = linea7[0];
				linea9[15] = linea9[0];
			}

			linea1[p] = linea1[p+1];
			linea3[p] = linea3[p+1];
			linea5[p] = linea5[p+1];		
			linea7[p] = linea7[p+1];	
			linea9[p] = linea9[p+1];
		}
		
		for(q=14;q>=0;q--) //actualizar lineas una posicion a la izquierda
		{
	
			linea2[q+1] = linea2[q];			
			linea4[q+1] = linea4[q];
			linea6[q+1] = linea6[q];
			linea8[q+1] = linea8[q];
			linea10[q+1] = linea10[q];
			
			if(q==0)
			{
				linea2[0] = linea2[15];					
				linea4[0] = linea4[15];	
				linea6[0] = linea6[15];	
				linea8[0] = linea8[15];	
				linea10[0] = linea10[15];	
			}
		}
		


}
