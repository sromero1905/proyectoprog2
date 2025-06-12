#include <iostream>
#include <cstring>
#include "Cliente.h"

using namespace std;

Cliente::Cliente() : Persona() {
    IDCliente = 0;
    Cuit = 0;
    strcpy(Email, "");
    TipoCliente = 0;
    strcpy(Direccion, "");
    estado = true;
}

Cliente::Cliente(int id, const char* nom, const char* ape, int dni, int tel,
                int cuit, const char* email, int tipo, const char* dir, bool est)
                : Persona(nom, ape, dni, tel) {
    IDCliente = id;
    Cuit = cuit;
    strncpy(Email, email, sizeof(Email) - 1);
    Email[sizeof(Email) - 1] = '\0';
    TipoCliente = tipo;
    strncpy(Direccion, dir, sizeof(Direccion) - 1);
    Direccion[sizeof(Direccion) - 1] = '\0';
    estado = est;
}

void Cliente::cargarCliente() {
    cout << "CARGAR DATOS DEL CLIENTE:" << endl;

    cargarDatosPersona(); // Heredado de Persona

    cout << "INGRESAR ID CLIENTE: ";
    cin >> IDCliente;

    cout << "INGRESAR CUIT: ";
    cin >> Cuit;

    cout << "INGRESAR EMAIL: ";
    cin.ignore();
    cin.getline(Email, 50);

    cout << "INGRESAR TIPO CLIENTE (1-Particular, 2-Empresa): ";
    cin >> TipoCliente;

    cout << "INGRESAR DIRECCION: ";
    cin.ignore();
    cin.getline(Direccion, 100);

    estado = true;
}

void Cliente::MostrarCliente() {
    cout << "DATOS DEL CLIENTE:" << endl;
    cout << "ID CLIENTE: " << IDCliente << endl;

    mostrarDatosPersona(); // Heredado de Persona

    cout << "CUIT: " << Cuit << endl;
    cout << "EMAIL: " << Email << endl;
    cout << "TIPO CLIENTE: " << (TipoCliente == 1 ? "Particular" : "Empresa") << endl;
    cout << "DIRECCION: " << Direccion << endl;
    cout << "ESTADO: " << (estado ? "Activo" : "Inactivo") << endl;
}

void Cliente::ActualizarCliente() {
    cout << "ACTUALIZAR DATOS DEL CLIENTE:" << endl;

    cout << "NUEVO NOMBRE: ";
    cin.ignore();
    cin.getline(Nombre, 30);

    cout << "NUEVO APELLIDO: ";
    cin.getline(Apellido, 30);

    cout << "NUEVO DNI: ";
    cin >> DNI;

    cout << "NUEVO TELEFONO: ";
    cin >> Telefono;

    cout << "NUEVO CUIT: ";
    cin >> Cuit;

    cout << "NUEVO EMAIL: ";
    cin.ignore();
    cin.getline(Email, 50);

    cout << "NUEVO TIPO CLIENTE (1-Particular, 2-Empresa): ";
    cin >> TipoCliente;

    cout << "NUEVA DIRECCION: ";
    cin.ignore();
    cin.getline(Direccion, 100);
}

void Cliente::EliminarCliente() {
    estado = false;
    cout << "CLIENTE ELIMINADO (BAJA LOGICA)." << endl;
}
