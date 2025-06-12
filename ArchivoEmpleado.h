#ifndef ARCHIVOEMPLEADO_H
#define ARCHIVOEMPLEADO_H

#include "Empleado.h"
#include <cstdio>
#include <cstring>

class ArchivoEmpleado {

private:
    char nombreArchivo [30];
    int tamRegistro;

public:
     ArchivoEmpleado(const char* n = "empleados.dat") {
     strcpy (nombreArchivo, n);
     tamRegistro = sizeof (Empleado);
     };

     int agregarRegistro (const Empleado& obj);

    bool generarNuevo();

    bool listarRegistros();

    int buscarEmpleado(int idEmpleado);

    Empleado leerRegistro(int pos);

    int modificarRegistro(const Empleado& e, int pos);

    int contarRegistros();
};

#endif // ARCHIVOEMPLEADO_H
