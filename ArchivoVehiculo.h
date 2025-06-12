#ifndef ARCHIVOVEHICULO_H
#define ARCHIVOVEHICULO_H

#include "Vehiculo.h"
#include <cstdio>

class ArchivoVehiculo {
private:
    char nombreArchivo[30];
    int tamRegistro;

public:
    ArchivoVehiculo(const char* nombre = "vehiculos.dat");

    bool generarNuevo();

    int agregarRegistro(const Vehiculo& v);
    bool listarRegistros();
    int buscarVehiculoPorPatente(const char* patente);
    Vehiculo leerRegistro(int pos);
    int modificarRegistro(const Vehiculo& v, int pos);
    int contarRegistros();
};

#endif // ARCHIVOVEHICULO_H
