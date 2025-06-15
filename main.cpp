#include <iostream>
#include <cstdlib>
#include "Cliente.h"
#include "ArchivoCliente.h"
#include "Reparacion.h"
#include "ArchivoReparacion.h"
#include "ArchivoEmpleado.h"
#include "Factura.h"

using namespace std;

// Prototipos de funciones
void menuPrincipal();
void menuEmpleado();
void menuClientes();
void menuReparaciones();
void menuFacturas();
void menuListados();
void menuInformes();
void pausar();
void limpiarPantalla();

// Instancias globales de archivos
ArchivoEmpleado ArchivoEmpleado;
ArchivoCliente archivoClientes;
ArchivoReparacion archivoReparaciones;

int main() {

    cout << "========================================" << endl;
    cout << "    SISTEMA DE GESTION DE TALLER       " << endl;
    cout << "          MECANICO - V1.0              " << endl;
    cout << "========================================" << endl;

    menuPrincipal();

    cout << "\nGracias por usar el Sistema de Gestion de Taller!" << endl;
   return 0;
}

void menuPrincipal() {
    int opcion;

    do {
        limpiarPantalla();
        cout << "========== MENU PRINCIPAL ==========" << endl;
        cout << "1. Gestion de Clientes" << endl;
        cout << "2. Gestion de Reparaciones" << endl;
        cout << "3. Gestion de Facturas" << endl;
        cout << "4. Gestion de Empleados" << endl;
        cout << "0. Salir" << endl;
        cout << "====================================" << endl;
        cout << "Seleccione una opcion: ";
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
            case 4:
                menuEmpleado();
            break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
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
        cout << "0. Volver al Menu Principal" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion: ";
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
                cout << "Opcion invalida." << endl;
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
        cout << "1. Agregar Reparacion" << endl;
        cout << "2. Mostrar Reparacion" << endl;
        cout << "3. Listar Todas las Reparaciones" << endl;
        cout << "4. Buscar Reparacion por ID" << endl;
        cout << "5. Modificar Estado de Reparacion" << endl;
        cout << "6. Marcar como Pagado" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\n=== AGREGAR REPARACION ===" << endl;
                Reparacion reparacion;
                reparacion.cargarReparacion();

                if (archivoReparaciones.agregarRegistro(reparacion) != -1) {
                    cout << "Reparacion agregada exitosamente!" << endl;
                } else {
                    cout << "Error al agregar la reparacion." << endl;
                }
                pausar();
                break;
            }
            case 2: {
                cout << "\n=== MOSTRAR REPARACION ===" << endl;
                int id;
                cout << "Ingrese ID de la reparacion: ";
                cin >> id;

                int pos = archivoReparaciones.buscarReparacion(id);
                if (pos != -1) {
                    Reparacion rep = archivoReparaciones.leerRegistro(pos);
                    rep.mostrarReparacion();
                } else {
                    cout << "Reparacion no encontrada." << endl;
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
                cout << "Ingrese ID de la reparacion: ";
                cin >> id;

                int pos = archivoReparaciones.buscarReparacion(id);
                if (pos != -1) {
                    Reparacion rep = archivoReparaciones.leerRegistro(pos);
                    rep.mostrarReparacion();
                } else {
                    cout << "Reparacion no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 5: {
                cout << "\n=== MODIFICAR ESTADO ===" << endl;
                int id, nuevoEstado;
                cout << "Ingrese ID de la reparacion: ";
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
                    cout << "Reparaci0n no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 6: {
                cout << "\n=== MARCAR COMO PAGADO ===" << endl;
                int id;
                cout << "Ingrese ID de la reparacion: ";
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
                            cout << "Reparacion marcada como pagada!" << endl;
                        } else {
                            cout << "Error al actualizar el pago." << endl;
                        }
                    }
                } else {
                    cout << "Reparacion no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
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
        cout << "3. Generar Factura desde Reparacion" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion: ";
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
                cout << "Ingrese ID de la reparacion: ";
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
                    cout << "Reparacion no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}


void menuEmpleado () {
    int opcion, id;

    while (true) {
        system("cls");

        cout << "\n=== MENU EMPLEADO ===" << endl;
        cout << "1. Agregar Empleado" << endl;
        cout << "2. Eliminar Empleado" << endl;
        cout << "3. Modificar Empleado" << endl;
        cout << "4. Listar Empleados" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion) {
            case 1:
                cout << "\n=== GENERAR EMPLEADO ===" << endl;
                if (ArchivoEmpleado.agregarRegistro() == 1) {
                    cout << "Empleado agregado correctamente (ID asignado automaticamente)." << endl;
                } else {
                    cout << "Error al agregar empleado." << endl;
                }
                cout << endl;
                system("pause");
                break;
            case 2:
                cout << "\n=== ELIMINAR EMPLEADO ===" << endl;
                cout << "Ingrese ID de empleado a dar de baja: ";
                cin >> id;
                if (ArchivoEmpleado.bajaEmpleado(id)) {
                    cout << "Empleado dado de baja correctamente." << endl;
                } else {
                    cout << "No se encontro el empleado o ya está dado de baja." << endl;
                }
                system("pause");
                break;
            case 3:
                cout << "\n=== MODIFICAR EMPLEADO ===" << endl;
                cout << "Ingrese ID de empleado a modificar: ";
                cin >> id;
                if (ArchivoEmpleado.modificarEmpleado(id)) {
                    cout << "Empleado modificado correctamente." << endl;
                } else {
                    cout << "No se encontro el empleado o está dado de baja." << endl;
                }
                system("pause");
                break;
            case 4:
                cout << "\n=== MOSTRAR EMPLEADOS ===" << endl;
                ArchivoEmpleado.listarRegistros();
                cout << endl;
                system("pause");
                break;
            case 0:
                return;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                system("pause");
        }
    }
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
