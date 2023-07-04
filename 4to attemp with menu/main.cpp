#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "juego.h"
int main() {
	FILE *texto;
    int opcion;
    char caracter;
    while (1){
	system ("CLS");
    printf("\n Bienvenido a Flogger\n");

        printf("\n----- MENU -----\n");
        printf("1. Iniciar juego\n");
        printf("2. Abrir manual de usuario\n");
        printf("3. Salir\n");

        opcion=_getch(); // guarda la tecla que se esta tocando
        if(opcion=='1')
        {
            opcion=1;
        }
        else if(opcion=='2')
        {
            opcion=2;
        }
        else if(opcion=='3')
        {
            opcion=3;
        }
		else if (opcion=='4')
		{
			opcion=4;
		}
        
        
        switch (opcion) { //ejecuta la opcion
            case 1: //inicia el juego
            	system ("CLS");
            	juegar();
                break;
                
            case 2: //muestra los controles
  				//abre el archivo de texto
  				int salir;
				texto = fopen("texto.txt", "r");

  				//muestra lo que dice el txt
			    while ((caracter = fgetc(texto)) != EOF) 
				{printf("%c", caracter);}
    			
   				fclose(texto); // Cerrar el archivo
   				
   				printf ("\n toque una tecla para continuar"); //pide verificacion para limpiar la pantalla al terminar de leer
   				salir=_getch();
				   if (salir != 0)
                {break;}
                
            case 3: //cierra el juego
                printf("Saliendo...\n");
                exit(0);
               
			case 4:
				printf ("agradecimientos especiales a Vallesteros y Oliveira");
				sleep (2);
				break;

            default: 
                 printf("Opcion invalida, porfavor ingresar otra.\n");
                break;
        }
}
}
