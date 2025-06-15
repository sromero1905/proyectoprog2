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

//setters
void Empleado::setIDEmpleado(int id) {
    _idEmpleado = id;
}

void Empleado::setEspecialidad(const char* esp) {
    strcpy(_especialidad, esp);
}

void Empleado::setActivo(bool a) {
    _activo = a;
}


//getters
int Empleado::getIDEmpleado() {
    return _idEmpleado;
}

const char* Empleado::getEspecialidad() {
    return _especialidad;
}

bool Empleado::estaActivo() {
    return _activo;
}


int ArchivoEmpleado::agregarRegistro() {
    Empleado obj;
    obj.cargarEmpleado();

    int nuevoID = obtenerSiguienteId();
    obj.setIDEmpleado(nuevoID);

    FILE* pEmpleado = fopen(nombreArchivo, "ab");
    if (!pEmpleado) return -1;

    int escribio = fwrite(&obj, tamRegistro, 1, pEmpleado);
    fclose(pEmpleado);
    return escribio;
}

int ArchivoEmpleado::buscarEmpleado(int idEmpleado) {
    Empleado obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (!p) return -1;

    int pos = 0;
    while (fread(&obj, tamRegistro, 1, p)) {
        if (obj.getIDEmpleado() == idEmpleado && obj.estaActivo()) {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose (p);
    return -1;
}

Empleado ArchivoEmpleado::leerRegistro (int pos) {
  Empleado obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (!p) return obj;

    fseek(p, pos * tamRegistro, SEEK_SET);
    fread(&obj, tamRegistro, 1, p);
    fclose(p);

    return obj;

}

void Empleado::cargarEmpleado () {
  char nombre[50], apellido[50], especialidad[50];
    int dni, telefono, id;

    cout << "INGRESE EL NOMBRE: ";
    cin >> nombre;
    setNombre (nombre);

     cout << "INGRESE EL APELLIDO: ";
     cin >> apellido;
     setApellido (apellido);

     cout << "INGRESE DNI: ";
    cin >> dni;
    setDNI(dni);

      cout << "INGRESE TELEFONO: ";
    cin >> telefono;
    setTelefono(telefono);

    cout << "INGRESE ESPECIALIDAD: ";
    cin >> especialidad;
    setEspecialidad (especialidad);

    setActivo (true);
}


bool ArchivoEmpleado::bajaEmpleado (int IdEmpleado) {
int pos = buscarEmpleado (IdEmpleado);
if (pos < 0) {
    return false;
}
Empleado obj = leerRegistro (pos);

obj.setActivo (false);

FILE* p =fopen (nombreArchivo, "rb+");
if (!p) return false;

fseek (p, pos * tamRegistro, SEEK_SET);
int escribio = fwrite (&obj, tamRegistro, 1, p);
fclose (p);

return (escribio == 1);
}


void Empleado::mostrarEmpleado () {
    cout << endl;
    cout << "ID Empleado: " << getIDEmpleado() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Apellido: " << getApellido() << endl;
    cout << "DNI: " << getDNI() << endl;
    cout << "Telefono: " << getTelefono() << endl;
    cout << "Especialidad: " << getEspecialidad() << endl;
    cout << "Estado: " << (estaActivo() ? "Activo" : "Baja") << endl;
}

void Empleado::actualizarEmpleado ( ){
char nuevoNombre [50];
int nuevoValor;

cout << "Nombre ["<< getNombre () <<  "]: ";
cin  >> nuevoNombre;
setNombre (nuevoNombre);

cout << "Apellido [" << getApellido () << "]: ";
cin >> nuevoNombre;
setApellido (nuevoNombre);

 cout << "DNI [" << getDNI() << "] (NO MODIFICABLE)" << endl;

cout << "Telefono [" << getTelefono() << "]: ";
cin >> nuevoValor;
setTelefono (nuevoValor);

cout << "Especialidad [" << getEspecialidad() << "]: ";
cin >> nuevoNombre;
setEspecialidad (nuevoNombre);

}


bool ArchivoEmpleado::modificarEmpleado(int idEmpleado) {
    int pos = buscarEmpleado(idEmpleado);
    if (pos < 0) return false;


    Empleado obj = leerRegistro(pos);
    cout << "Datos actuales del empleado: ";
    obj.mostrarEmpleado();

    cout << " --- Actualizar campos --- ";
    obj.actualizarEmpleado();


    FILE* p = fopen(nombreArchivo, "rb+");
    if (!p) return false;
    fseek(p, pos * tamRegistro, SEEK_SET);
    int wrote = fwrite(&obj, tamRegistro, 1, p);
    fclose(p);

    return (wrote == 1);
}

bool ArchivoEmpleado::listarRegistros () {
    Empleado obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (!p) {
        cout << "No se pudo abrir el archivo de empleados. ";
        return false;
    }

    while (fread(&obj, tamRegistro, 1, p)) {
        if (obj.estaActivo()) {
            obj.mostrarEmpleado();
            cout << "------------------------";
        }
    }

    fclose(p);

  return true;
}

int ArchivoEmpleado::obtenerSiguienteId() {
Empleado obj;
FILE* p = fopen (nombreArchivo, "rb");
if (!p) return 1;
    int maxID = 0;
    while (fread(&obj, tamRegistro, 1, p)) {
        if (obj.getIDEmpleado() > maxID) {
            maxID = obj.getIDEmpleado();
        }
    }
    fclose(p);
    return maxID + 1;
}



