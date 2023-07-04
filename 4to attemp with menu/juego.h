#include <iostream>
#include <windows.h>
#include <unistd.h>
#include "mapita.h"
#include "Temporizador.h"

void actualizarJuego(){
        ultra();
        // Limpiar pantalla
        sleep(0.4);
        system("CLS");
}

int juegar() {
        actualizarJuego();

    return 0;
}
