#include <iostream>
#include <windows.h>
#include <unistd.h>
#include "mapita.h"

void actualizarJuego() {
    while (1){
        ultra();
        // Limpiar pantalla
        sleep(0.1);
        system("CLS");
    }
}

int main(int argc, char** argv) {
    while (1) {
        actualizarJuego();
    }

    return 0;
}
