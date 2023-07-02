#include <iostream>
#include <windows.h>
#include <unistd.h>
#include "mapita.h"
#include "ranita.h"

void actualizarJuego() {
    while (1){
        ultra();
        dibujar();
        // Limpiar pantalla
        sleep(1);
        system("CLS");
    }
}

int main(int argc, char** argv) {
    while (1) {
        actualizarJuego();
    }

    return 0;
}
