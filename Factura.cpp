#include <iostream>
#include <cstring>
#include "Factura.h"

using namespace std;

Factura::Factura() {
    NFactura = 0;
    NReparacion = 0;
    Importe = 0;
    FechaEntrega = Fecha();
    strcpy(NPatente, "");
    IDCliente = 0;
    ImporteTotal = 0;
}

Factura::Factura(int nFact, int nRep, int imp, Fecha fecha, const char* pat, int idCli, int impTotal) {
    NFactura = nFact;
    NReparacion = nRep;
    Importe = imp;
    FechaEntrega = fecha;
    strncpy(NPatente, pat, sizeof(NPatente) - 1);
    NPatente[sizeof(NPatente) - 1] = '\0';
    IDCliente = idCli;
    ImporteTotal = impTotal;
}

void Factura::generarFactura() {
    cout << "=== GENERAR NUEVA FACTURA ===" << endl;

    cout << "Ingrese número de factura: ";
    cin >> NFactura;

    cout << "Ingrese número de reparación: ";
    cin >> NReparacion;

    cout << "Ingrese importe: ";
    cin >> Importe;

    cout << "Ingrese fecha de entrega:" << endl;
    FechaEntrega.cargarFecha();

    cout << "Ingrese patente: ";
    cin.ignore();
    cin.getline(NPatente, 20);

    cout << "Ingrese ID del cliente: ";
    cin >> IDCliente;

    cout << "Ingrese importe total: ";
    cin >> ImporteTotal;

    cout << "Factura generada exitosamente!" << endl;
}

void Factura::mostrarFactura() {
    cout << "DATOS DE LA FACTURA:" << endl;
    cout << "NUMERO DE FACTURA: " << NFactura << endl;
    cout << "NUMERO DE REPARACION: " << NReparacion << endl;
    cout << "IMPORTE: $" << Importe << endl;
    cout << "FECHA DE ENTREGA: ";
    FechaEntrega.mostrarFecha();
    cout<<endl;
    cout << "PATENTE: " << NPatente << endl;
    cout << "ID CLIENTE: " << IDCliente << endl;
    cout << "IMPORTE TOTAL: $" << ImporteTotal << endl;
}
