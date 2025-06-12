#include <iostream>
#include "Empleado.h"
#include "ArchivoEmpleado.h"
#include "Persona.h"
#include <cstring>
using namespace std;


Empleado::Empleado () {
setNombre (" ");
setApellido(" ");
setDNI (0);
setTelefono(0);
_idEmpleado = 0;
strcpy(_especialidad,  "");
}

Empleado::Empleado(const char* nombre, const char* apellido, int dni, int telefono, int idEmpleado, const char* especialidad) {

setNombre (nombre);
setApellido (apellido);
setDNI(dni);
setTelefono (telefono);
_idEmpleado = idEmpleado;
strcpy (_especialidad, especialidad);
_activo = true;
}






//getters

int ArchivoEmpleado::agregarRegistro(const Empleado& obj) {
    FILE* pEmpleado = fopen(nombreArchivo, "ab");
    if (!pEmpleado) return -1;

    int escribio = fwrite(&obj, tamRegistro, 1, pEmpleado);
    fclose(pEmpleado);
    return escribio;
}



