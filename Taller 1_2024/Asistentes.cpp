#include "Asistentes.h"

// Constructor
Asistentes::Asistentes(std::string tipo_, std::string rut_, std::string nombre_, std::string telefono_, std::string datos_ad_)
    : tipo(tipo_), rut(rut_), nombre(nombre_), telefono(telefono_), datos_ad(datos_ad_) {}

// Métodos de acceso
std::string Asistentes::getNombre() const {
    return nombre;
}

void Asistentes::setNombre(const std::string& nom) {
    nombre = nom;
}

std::string Asistentes::getTipo() const {
    return tipo;
}

void Asistentes::setTipo(const std::string& tip) {
    tipo = tip;
}

std::string Asistentes::getRut() const {
    return rut;
}

void Asistentes::setRut(const std::string& ru) {
    rut = ru;
}

std::string Asistentes::getTelefono() const {
    return telefono;
}

void Asistentes::setTelefono(const std::string& tel) {
    telefono = tel;
}

std::string Asistentes::getDatosAdicionales() const {
    return datos_ad;
}

void Asistentes::setDatosAdicionales(const std::string& dat) {
    datos_ad = dat;
}

// Método para mostrar la información
std::string Asistentes::mostrarInformacion() const {
    return "Nombre: " + nombre + "\nTipo: " + tipo + "\nRUT: " + rut + "\nTeléfono: " + telefono + "\nDatos adicionales: " + datos_ad + "\n";
}
