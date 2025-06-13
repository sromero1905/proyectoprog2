#include <iostream>
#include <cstdlib>
#include "Cliente.h"
#include "ArchivoCliente.h"
#include "Reparacion.h"
#include "ArchivoReparacion.h"
#include "Factura.h"

using namespace std;

// Prototipos de funciones
void menuPrincipal();
void menuClientes();
void menuReparaciones();
void menuFacturas();
void menuListados();
void menuInformes();
void pausar();
void limpiarPantalla();

// Instancias globales de archivos
ArchivoCliente archivoClientes;
ArchivoReparacion archivoReparaciones;

int main() {
    cout << "========================================" << endl;
    cout << "    SISTEMA DE GESTION DE TALLER       " << endl;
    cout << "          MECANICO - V1.0              " << endl;
    cout << "========================================" << endl;

    menuPrincipal();

    cout << "\nGracias por usar el Sistema de Gestión de Taller!" << endl;
    return 0;
}

void menuPrincipal() {
    int opcion;

    do {
        limpiarPantalla();
        cout << "========== MENU PRINCIPAL ==========" << endl;
        cout << "1. Gestión de Clientes" << endl;
        cout << "2. Gestión de Reparaciones" << endl;
        cout << "3. Gestión de Facturas" << endl;
        cout << "0. Salir" << endl;
        cout << "====================================" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuReparaciones();
                break;
            case 3:
                menuFacturas();
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}

void menuClientes() {
    int opcion;

    do {
        limpiarPantalla();
        cout << "========== GESTION DE CLIENTES ==========" << endl;
        cout << "1. Agregar Cliente" << endl;
        cout << "2. Mostrar Cliente" << endl;
        cout << "3. Modificar Cliente" << endl;
        cout << "4. Eliminar Cliente" << endl;
        cout << "0. Volver al Menú Principal" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n=== AGREGAR CLIENTE ===" << endl;
                archivoClientes.AgregarCliente();
                pausar();
                break;
            case 2:
                cout << "\n=== MOSTRAR CLIENTE ===" << endl;
                archivoClientes.MostrarCliente();
                pausar();
                break;
            case 3:
                cout << "\n=== MODIFICAR CLIENTE ===" << endl;
                archivoClientes.ModificarCliente();
                pausar();
                break;
            case 4:
                cout << "\n=== ELIMINAR CLIENTE ===" << endl;
                archivoClientes.EliminarCliente();
                pausar();
                break;
            case 0:
                break;
            default:
                cout << "Opción inválida." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}

void menuReparaciones() {
    int opcion;

    do {
        limpiarPantalla();
        cout << "======== GESTION DE REPARACIONES ========" << endl;
        cout << "1. Agregar Reparación" << endl;
        cout << "2. Mostrar Reparación" << endl;
        cout << "3. Listar Todas las Reparaciones" << endl;
        cout << "4. Buscar Reparación por ID" << endl;
        cout << "5. Modificar Estado de Reparación" << endl;
        cout << "6. Marcar como Pagado" << endl;
        cout << "0. Volver al Menú Principal" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\n=== AGREGAR REPARACION ===" << endl;
                Reparacion reparacion;
                reparacion.cargarReparacion();

                if (archivoReparaciones.agregarRegistro(reparacion) != -1) {
                    cout << "Reparación agregada exitosamente!" << endl;
                } else {
                    cout << "Error al agregar la reparación." << endl;
                }
                pausar();
                break;
            }
            case 2: {
                cout << "\n=== MOSTRAR REPARACION ===" << endl;
                int id;
                cout << "Ingrese ID de la reparación: ";
                cin >> id;

                int pos = archivoReparaciones.buscarReparacion(id);
                if (pos != -1) {
                    Reparacion rep = archivoReparaciones.leerRegistro(pos);
                    rep.mostrarReparacion();
                } else {
                    cout << "Reparación no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 3:
                cout << "\n=== LISTAR REPARACIONES ===" << endl;
                archivoReparaciones.listarRegistros();
                pausar();
                break;
            case 4: {
                cout << "\n=== BUSCAR REPARACION ===" << endl;
                int id;
                cout << "Ingrese ID de la reparación: ";
                cin >> id;

                int pos = archivoReparaciones.buscarReparacion(id);
                if (pos != -1) {
                    Reparacion rep = archivoReparaciones.leerRegistro(pos);
                    rep.mostrarReparacion();
                } else {
                    cout << "Reparación no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 5: {
                cout << "\n=== MODIFICAR ESTADO ===" << endl;
                int id, nuevoEstado;
                cout << "Ingrese ID de la reparación: ";
                cin >> id;

                int pos = archivoReparaciones.buscarReparacion(id);
                if (pos != -1) {
                    Reparacion rep = archivoReparaciones.leerRegistro(pos);
                    rep.mostrarReparacion();

                    cout << "Nuevo estado (1-Pendiente, 2-En curso, 3-Finalizada): ";
                    cin >> nuevoEstado;

                    rep.setEstado(nuevoEstado);
                    if (archivoReparaciones.modificarRegistro(rep, pos) != -1) {
                        cout << "Estado actualizado exitosamente!" << endl;
                    } else {
                        cout << "Error al actualizar el estado." << endl;
                    }
                } else {
                    cout << "Reparación no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 6: {
                cout << "\n=== MARCAR COMO PAGADO ===" << endl;
                int id;
                cout << "Ingrese ID de la reparación: ";
                cin >> id;

                int pos = archivoReparaciones.buscarReparacion(id);
                if (pos != -1) {
                    Reparacion rep = archivoReparaciones.leerRegistro(pos);
                    rep.mostrarReparacion();

                    char confirma;
                    cout << "¿Marcar como pagado? (s/n): ";
                    cin >> confirma;

                    if (confirma == 's' || confirma == 'S') {
                        rep.setPagado(true);
                        if (archivoReparaciones.modificarRegistro(rep, pos) != -1) {
                            cout << "Reparación marcada como pagada!" << endl;
                        } else {
                            cout << "Error al actualizar el pago." << endl;
                        }
                    }
                } else {
                    cout << "Reparación no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 0:
                break;
            default:
                cout << "Opción inválida." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}

void menuFacturas() {
    int opcion;

    do {
        limpiarPantalla();
        cout << "========== GESTION DE FACTURAS ==========" << endl;
        cout << "1. Generar Factura" << endl;
        cout << "2. Mostrar Factura" << endl;
        cout << "3. Generar Factura desde Reparación" << endl;
        cout << "0. Volver al Menú Principal" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\n=== GENERAR FACTURA ===" << endl;
                Factura factura;
                factura.generarFactura();
                pausar();
                break;
            }
            case 2: {
                cout << "\n=== MOSTRAR FACTURA ===" << endl;
                Factura factura;
                factura.mostrarFactura();
                pausar();
                break;
            }
            case 3: {
                cout << "\n=== GENERAR FACTURA DESDE REPARACION ===" << endl;
                int idReparacion;
                cout << "Ingrese ID de la reparación: ";
                cin >> idReparacion;

                int pos = archivoReparaciones.buscarReparacion(idReparacion);
                if (pos != -1) {
                    Reparacion rep = archivoReparaciones.leerRegistro(pos);

                    // Crear factura con datos de la reparación
                    Factura factura(
                        1, // Número de factura (se podría hacer automático)
                        rep.getIDReparacion(),
                        rep.getImporte(),
                        rep.getFechaEntrega(),
                        rep.getPatente(),
                        rep.getIDCliente(),
                        rep.getImporte()
                    );

                    cout << "\n=== FACTURA GENERADA ===" << endl;
                    factura.mostrarFactura();
                } else {
                    cout << "Reparación no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 0:
                break;
            default:
                cout << "Opción inválida." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}



void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
