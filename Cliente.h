#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente : public Persona {
public:
    int IDCliente;
    int Cuit;
    char Email[50];
    int TipoCliente;
    char Direccion[100];
    bool estado;

    Cliente();
    Cliente(int id, const char* nom, const char* ape, int dni, int tel, int cuit, const char* email, int tipo, const char* dir, bool est);

    void cargarCliente();
    void MostrarCliente();
    void ActualizarCliente();
    void EliminarCliente();
};

#endif // CLIENTE_H
