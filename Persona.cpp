#include <cstring>
#include "Persona.h"

Persona::Persona() {
    strcpy(_Nombre, "");
    strcpy(_Apellido, "");
    _dni = 0;
    _Telefono = 0;
}
//setters
void Persona::setNombre(const char* nombre) {
    strcpy(_Nombre, nombre);
}

void Persona::setApellido(const char* apellido) {
    strcpy(_Apellido, apellido);
}

void Persona::setDNI(int d) {
    _dni = d;
}

void Persona::setTelefono(int t) {
    _Telefono = t;
}

//getters
const char* Persona::getNombre() {
    return _Nombre;
}

const char* Persona::getApellido() {
    return _Apellido;
}

int Persona::getDNI() {
    return _dni;
}

int Persona::getTelefono()  {
    return _Telefono;
}
