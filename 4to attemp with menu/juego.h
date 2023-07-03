#include <iostream>
#include <windows.h>
#include <unistd.h>
#include "mapita.h"


void actualizarJuego() {
    while (1){
        ultra();
        // Limpiar pantalla
        sleep(0.4);
        system("CLS");
    }
}

int juegar() {
    while (1) {
        actualizarJuego();
    }

    return 0;
}
