#include <iostream>
#include <cstring>
#include <cstdio>

#include "ArchivoVehiculo.h"
#include "Fecha.h"

using namespace std;

ArchivoVehiculo::ArchivoVehiculo(const char* nombre) {
    strncpy(nombreArchivo, nombre, sizeof(nombreArchivo) - 1);
    nombreArchivo[sizeof(nombreArchivo)-1] = '\0';
    tamRegistro = sizeof(Vehiculo);
}

bool ArchivoVehiculo::generarNuevo() {
    FILE* pVehiculo;
    pVehiculo = fopen("Vehiculos.dat", "wb");
    if (pVehiculo == nullptr) {
        cout << "ERROR AL CREAR ARCHIVO." << endl;
        return false;
    }
    fclose(pVehiculo);
    cout << "ARCHIVO CREADO EXITOSAMENTE." << endl;
    return true;
}

void ArchivoVehiculo::AgregarVehiculo(){
Vehiculo v;

cout << " INGRESAR PATENTE: " << endl;
cin.getline(v.Patente, 20);
cout << " INGRESAR MARCA: " << endl;
cin.getline(v.Marca, 20);
cout << " INGRESAR MODELO: " << endl;
cin.getline(v.Modelo, 20);
cout << " INGRESAR ANIO: " << endl;
cin >> v.Anio;
cout << " INGRESAR FALLA: " << endl;
cin.getline(v.Falla, 50);
cout << " INGRESAR TIPO DE VEHICULO: " << endl;
cin >> v.TipoVehiculo;
cout << " INGRESAR FECHA DE INGRESO (DIA, MES, ANIO): " << endl;
v.FechaIngreso.AgregarFecha();

FILE* pVehiculo;
pVehiculo = fopen ("Vehiculos","ab");
if (pVehiculo == nullptr){
    cout << " ERROR AL ABRIR EL ARCHIVO. " << endl;
    return;
}
fwrite(&v, TamRegistro, 1, pVehiculo);
fclose(pVehiculo);

cout << " VEHICULO AGREGADO EXITOSAMENTE. " << endl;
}

void ArchivoVehiculo::MostrarVehiculo(){
    FILE* pVehiculo;
    pVehiculo = fopen ("Vehiculos.dat","rb");
    if (pVehiculo == nullptr){
        cout << " ERROR AL ABRIR EL ARCHIVO DE LECTURA. " << endl;
        return;
    }
    Vehiculo v;
    while(fread(&v, TamRegistro, 1,pVehiculo) == 1){
        cout << " PATENTE: " << v.Patente << endl;
        cout << " MARCA: " << v.Marca << endl;
        cout << " MODELO: " << v.Modelo << endl;
        cout << " ANIO: " << v.Anio << endl;
        cout << " FALLA: " << v.Falla << endl;
        cout << " TIPO DE VEHICULO: " << v.TipoVehiculo << endl;
        cout << " FECHA DE INGRESO: " << endl;
        v.FechaIngreso.MostrarFecha(); 
        cout << "__________________________________" << endl;

    }
    fclose(pVehiculo);
}

void ArchivoVehiculo::ModificarVehiculo(){
char pat[20];
cout << " INGRESAR LA PATENTE DEL VEHICULO A MODIFICAR: " << endl;
cin.getline(pat, 20);

FILE* pVehiculo;
pVehiculo = fopen ("Vehiculos.dat","rb+");
if (pVehiculo == nullptr){
    cout << " ERROR AL ABRIR EL ARCHIVO PARA MODIFICAR VEHICULO. " << endl;
    return;
}
Vehiculo v;
bool VehiculoEncontrado = false;
while(fread(&v, TamRegistro, 1, pVehiculo) == 1){
    if (strcmp(v.Patente, pat) == 0){
        cout << " VEHICULO ENCONTRADO. INGRESAR LOS NUEVOS DATOS: " << endl;
        cout << " INGRESAR NUEVA MARCA: " << endl;
        cin.getline(v.Marca, 20);
        cout << " INGRESAR NUEVO MODELO: " << endl;
        cin.getline(v.Modelo, 20);
        cout << " INGRESAR NUEVO ANIO: " << endl;
        cin >> v.Anio;
        cin.ignore();
        cout << " INGRESAR NUEVA FALLA: " << endl;
        cin.getline(v.Falla, 50);
        cout << " INGRESAR NUEVO TIPO DE VEHICULO: " << endl;
        cin >> v.TipoVehiculo;
        cout << " INGRESAR NUEVA FECHA DE INGRESO (DIA, MES, ANIO): " << endl;
        cin >> v.FechaIngreso.AgregarFecha();
        cin.ignore();

        fseek(pVehiculo, -TamRegistro, SEEK_CUR);
        fwrite(&v, TamRegistro, 1, pVehiculo);

        cout << " VEHICULO MODIFICADO CORRECTAMENTE. " << endl;
        VehiculoEncontrado = true;
        break;
      }
    }
    fclose(pVehiculo);

    if(!VehiculoEncontrado)
        cout << " NO SE ENCONTRO UN VEHICULO CON LA PATENTE INDICADA. " << endl;
}

void ArchivoVehiculo::EliminarVehiculo(){
    char pat[20];
    cout << " INGRESAR LA PATENTE DEL VEHICULO A ELIMINAR: " << endl;
    cin.getline(pat, 20);

    FILE* pVehiculo;
    pVehiculo = fopen ("Vehiculos.dat","rb");
    if (pVehiculo == nullptr){
        cout << " ERROR AL ABRIR EL ARCHIVO. " << endl;
        return;
    }

    FILE* pTemporal;
    pTemporal = fopen ("Temporal.dat","wb");
    if (pTemporal == nullptr){
        cout << " ERROR AL CREAR ARCHIVO TEMPORAL. " << endl;
        fclose(pVehiculo);
        return;
    }
    Vehiculo v;
    bool VehiculoEliminado = false;
    while (fread(&v, TamRegistro, 1, pVehiculo) == 1){
        if (strcmp(v.Patente, pat) == 0){
            VehiculoEliminado = true;
        } else {
            fwrite(&v, TamRegistro, 1, pTemporal);
        }
    }
    fclose(pVehiculo);
    fclose(pTemporal);

    remove ("Vehiculos.dat");
    rename ("Temporal.dat", "Vehiculos.dat");

    if (VehiculoEliminado == true)
        cout << " VEHICULO ELIMINADO CORRECTAMENTE. " << endl;
    else
        cout << " NO SE ENCONTRO UN VEHICULO CON LA PATENTE INDICADA. " << endl;

}
