#include <iostream>
#include <windows.h>
#include <unistd.h>
#include "mapa.h"
#include "temporizador.h"

void actualizarJuego() {
    mapa();
    printf("\n\n");
    actualizarTemporizador();
    // Limpiar pantalla
    sleep(1);
    system("CLS");
}

int main(int argc, char** argv) {
    while (1) {
        actualizarJuego();
    }

    return 0;
}
