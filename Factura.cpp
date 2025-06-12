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
    cout << "GENERAR FACTURA:" << endl;

    cout << "INGRESAR NUMERO DE FACTURA: ";
    cin >> NFactura;

    cout << "INGRESAR NUMERO DE REPARACION: ";
    cin >> NReparacion;

    cout << "INGRESAR IMPORTE: ";
    cin >> Importe;

    cout << "INGRESAR FECHA DE ENTREGA:" << endl;
    FechaEntrega.AgregarFecha();

    cout << "INGRESAR PATENTE: ";
    cin.ignore();
    cin.getline(NPatente, 20);

    cout << "INGRESAR ID CLIENTE: ";
    cin >> IDCliente;

    ImporteTotal = Importe; // Se podría agregar IVA u otros cálculos

    cout << "FACTURA GENERADA EXITOSAMENTE." << endl;
}

void Factura::mostrarFactura() {
    cout << "DATOS DE LA FACTURA:" << endl;
    cout << "NUMERO DE FACTURA: " << NFactura << endl;
    cout << "NUMERO DE REPARACION: " << NReparacion << endl;
    cout << "IMPORTE: $" << Importe << endl;
    cout << "FECHA DE ENTREGA: ";
    FechaEntrega.MostrarFecha();
    cout << "PATENTE: " << NPatente << endl;
    cout << "ID CLIENTE: " << IDCliente << endl;
    cout << "IMPORTE TOTAL: $" << ImporteTotal << endl;
}
