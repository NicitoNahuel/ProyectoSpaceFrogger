#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#define color SetConsoleTextAttribute
using namespace std;

int i, j, p, q, n;

// Meteoritos
int linea1[15] = {254, 254, 254, 176, 176, 176, 254, 254, 254, 176, 176, 254, 254, 176, 176};
int linea2[15] = {254, 254, 176, 176, 176, 176, 254, 254, 176, 176, 176, 254, 254, 176, 176};
int linea3[15] = {176, 254, 254, 254, 176, 176, 254, 254, 254, 176, 176, 176, 254, 254, 176};
int linea4[15] = {176, 176, 254, 254, 176, 254, 254, 254, 176, 176, 176, 254, 254, 176, 176};
int linea5[15] = {254, 176, 176, 176, 176, 254, 254, 254, 254, 176, 176, 176, 254, 254, 254};

int linea6[15] = {178, 178, 178, 178, 178, 178, 175, 175, 178, 178, 178, 178, 178, 175, 175};
int linea7[15] = {178, 178, 178, 178, 178, 178, 174, 178, 178, 178, 178, 178, 178, 178, 178};
int linea8[15] = {178, 178, 178, 178, 178, 178, 175, 178, 178, 178, 175, 178, 178, 178, 175};
int linea9[15] = {174, 178, 178, 178, 174, 178, 178, 178, 174, 178, 178, 178, 178, 178, 178};
int linea10[15] = {175, 178, 178, 178, 175, 178, 178, 178, 175, 178, 178, 178, 178, 178, 178};

// Intermedio y arranque
int sf1[15] = {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219};

// Meta
int sf2[15] = {219, 219, 223, 219, 223, 219, 223, 219, 223, 219, 223, 219, 223, 219, 219};

void ultra() {
    HANDLE lol;
    lol = GetStdHandle(STD_OUTPUT_HANDLE);

    int pos6 = 0;
    int pos7 = 0;
    int pos8 = 0;
    int pos9 = 0;
    int pos10 = 0;
    while (1){
        int matriz[13][15]; // Matriz para almacenar los vectores

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
                printf("%c", matriz[i][j]);
            }
            printf("\n");
        }

        Sleep(600);

        system("cls");

        pos6++;
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
