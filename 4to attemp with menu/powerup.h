#include <stdio.h>

void generar_powerup(int x, int y, int powerups){
srand(time(NULL));
		
x=rand()%15; //Genera numero aleatorio para el power up de vidas.
y=rand()%13; 

powerups=rand()%2; //que powerup genera (0 = 1up, 1 = bonus points)
}
