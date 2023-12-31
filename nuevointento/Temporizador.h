#include <stdio.h>
#include <unistd.h>

#define BAR_LENGTH 30  // Longitud de la barra

void mostrarBarra(int progreso) {
    int i;
    printf("[");
    for (i = 0; i < BAR_LENGTH; i++) {
        if (i < progreso)
            printf("%c", 219);
        else
            printf(" ");
    }
    printf("]\r");
    fflush(stdout);
}

void actualizarTemporizador() {
    static int tiempo_restante = 30; // Duración del temporizador en segundos

    if (tiempo_restante > 0) {
        mostrarBarra(tiempo_restante);
        sleep(1); // Esperar 1 segundo
        tiempo_restante--;
    } else {
        mostrarBarra(0); // Mostrar la barra vacía al finalizar el temporizador
        printf("\n¡Tiempo agotado!\n");
        // Reiniciar el temporizador
        tiempo_restante = 30;
    }
}
