#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#define color SetConsoleTextAttribute
using namespace std;

int matriz[13][15], posRana[13][15];
int i, j, p, q, n;
int x, y;
int si = 30;
int Vidas;
int meta;
int puntuacion=0;
bool partidaTerminada;
// Meteoritos
int linea1[15] = {254, 254, 254, 176, 176, 176, 254, 254, 254, 176, 176, 254, 254, 176, 176}; //176= agua / 254 = tronco
int linea2[15] = {254, 254, 176, 176, 176, 176, 254, 254, 176, 176, 176, 254, 254, 176, 176};
int linea3[15] = {176, 254, 254, 254, 176, 176, 254, 254, 254, 176, 176, 176, 254, 254, 176};
int linea4[15] = {176, 176, 254, 254, 176, 254, 254, 254, 176, 176, 176, 254, 254, 176, 176};
int linea5[15] = {254, 176, 176, 176, 176, 254, 254, 254, 254, 176, 176, 176, 254, 254, 254};

int linea6[15] = {178, 178, 178, 178, 178, 178, 175, 175, 178, 178, 178, 178, 178, 175, 175}; //178= carretera / 175 = autos
int linea7[15] = {178, 178, 178, 178, 178, 178, 174, 178, 178, 178, 178, 178, 178, 178, 178};
int linea8[15] = {178, 178, 178, 178, 178, 178, 175, 178, 178, 178, 175, 178, 178, 178, 175};
int linea9[15] = {174, 178, 178, 178, 174, 178, 178, 178, 174, 178, 178, 178, 178, 178, 178};
int linea10[15] = {175, 178, 178, 178, 175, 178, 178, 178, 175, 178, 178, 178, 178, 178, 178};

// Intermedio y arranque
int sf1[15] = {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219}; //219= pasto

// Meta
int sf2[15] = {219, 219, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 219, 219}; //223= meta

void ultra() {
	partidaTerminada=false;
	x = 12; y = 7;
	Vidas=3;
		
    HANDLE lol;
    lol = GetStdHandle(STD_OUTPUT_HANDLE);

    int pos6 = 0;
    int pos7 = 0;
    int pos8 = 0;
    int pos9 = 0;
    int pos10 = 0;
   
	
	while (partidaTerminada == false)
		{
		if(matriz[x][y] == 176 || matriz[x][y] == 175)
		{
        	Sleep(500);
        	Vidas=Vidas-1;
        	x=12; y=7;
        	if (Vidas==0)
        	{
			partidaTerminada=true;
			system("CLS");
			printf("\n GAME OVER\n Tu puntuacion final es de: %d", puntuacion);
        	sleep(2.5);
        	system("CLS");
        	break;
			}
		}
		system("CLS");

        // Copiar los vectores a la matriz
        for (i = 0; i < 15; i++) {
            matriz[0][i] = sf2[i];
            matriz[1][i] = linea1[i];
            matriz[2][i] = linea2[i];
            matriz[3][i] = linea3[i];
            matriz[4][i] = linea4[i];
            matriz[5][i] = linea5[i];
            matriz[6][i] = sf1[i];
            matriz[7][i] = linea6[(i + pos6) % 15];
            matriz[8][i] = linea7[(i + pos7) % 15];
            matriz[9][i] = linea8[(i + pos8) % 15];
            matriz[10][i] = linea9[(i + pos9) % 15];
            matriz[11][i] = linea10[(i + pos10) % 15];
            matriz[12][i] = sf1[i];
        }
       
        //Define la posicion de la rana
        posRana[x][y] = si;
       
        // Imprimir la matriz
        for (i = 0; i < 13; i++) {
            for (j = 0; j < 15; j++) {
            	
                if (matriz[i][j] == 254) {
                    color(lol, 6);
                } else if (matriz[i][j] == 176) {
                    color(lol, 3);
                } else if (matriz[i][j] == 178) {
                    color(lol, 15);
                } else if (matriz[i][j] == 175) {
                    color(lol, 4);
                } else if (matriz[i][j] == 174) {
                    color(lol, 5);
                } else if (matriz[i][j] == 219) {
                    color(lol, 2);
                } else if (matriz[i][j] == 223) {
                    color(lol, 2);
                }
                
                if(i == x && j == y){ 
                	if(matriz[x][y] == 176 || matriz[x][y] == 175){
                		color(lol, 12);
					}else{
						color(lol, 10);
					}
                	printf("%c", posRana[i][j]);
				}else{
					printf("%c", matriz[i][j]);
				}
                
            }
            printf("\n");
        }
		
		printf ("PUNTUACION: %d \n", puntuacion); //muestra la puntuacion debajo del mapa
		printf ("VIDAS: %d", Vidas); //muestra las vidas
        Sleep(400);

        //Mover la rana
        if ((GetAsyncKeyState(VK_UP)& 1) || (GetAsyncKeyState(0x57)& 1)) //Arriba
        {
            if (x>0)
            {x--;}
            si = 30; //"la rana" se mueve hacia arriba (va a ser una flecha en  direccion en la que esta mirando "la rana")
            puntuacion=puntuacion+10; //cuando avanza suma 10 puntos
        }

        if ((GetAsyncKeyState(VK_DOWN) & 1) || (GetAsyncKeyState(0x53) & 1)) //Abajo
        {
            if (x<12)
            {x++;}
            si = 31; //"la rana" se mueve hacia abajo
            puntuacion=puntuacion-10; //cuando retrocede le resta 10 puntos
        }

        if ((GetAsyncKeyState(VK_LEFT)& 1) || (GetAsyncKeyState(0x41)& 1)) //Izquierda
        {
            if (y>0)
            {y--;}
            si = 17; //"la rana" se mueve hacia la izquierda
        }

        if ((GetAsyncKeyState(VK_RIGHT) & 1) || (GetAsyncKeyState(0x44)& 1)) //Derecha
        {
            if (y<14)
            {y++;}
            si = 16; //"la rana" se mueve hacia la izquierda
        }
        
        if(!(matriz[x][y] == 176 || matriz[x][y] == 175)) system("cls"); //si no perdiste actualiza la pantalla

		if (x==0) //cuando llega a la meta le suma mil puntos "por ganar" y lo devuelve al inicio
		{
			puntuacion=puntuacion+1000;
			x=12, y=7;
		}
       
        pos6++; //mueve las lineas
        pos7--;
        pos8++;
        pos9--;
        pos10++;

        for (p = 0; p < 15; p++) // actualizar lineas una posicion hacia la derecha
        {
            if (p == 0) {
                linea1[15] = linea1[0];
                linea3[15] = linea3[0];
                linea5[15] = linea5[0];
            }

            linea1[p] = linea1[p + 1];
            linea3[p] = linea3[p + 1];
            linea5[p] = linea5[p + 1];
        }

        for (q = 14; q >= 0; q--) // actualizar lineas una posicion a la izquierda
        {

            linea2[q + 1] = linea2[q];
            linea4[q + 1] = linea4[q];

            if (q == 0) {
                linea2[0] = linea2[15];
                linea4[0] = linea4[15];
            }
        }
    }
}
