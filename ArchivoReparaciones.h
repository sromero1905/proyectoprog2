#ifndef ARCHIVOREPARACION_H
#define ARCHIVOREPARACION_H

#include "Reparacion.h"
#include <cstdio>

class ArchivoReparacion {
private:
    char nombreArchivo[30];
    int tamRegistro;

public:

    ArchivoReparacion(const char* nombre = "reparaciones.dat");

    bool generarNuevo();

    int agregarRegistro(const Reparacion r);

    bool listarRegistros();

    int buscarReparacion(int id);

    Reparacion leerRegistro(int pos);

    int modificarRegistro(const Reparacion r, int pos);

    int contarRegistros();
};

#endif
