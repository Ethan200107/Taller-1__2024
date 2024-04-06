#pragma once
#include <iostream>
#include <string>

class Asistentes {
private:
    std::string nombre, tipo, rut, telefono, datos_ad;

public:
    // Constructor
    Asistentes(std::string tipo_, std::string rut_, std::string nombre_, std::string telefono_, std::string datos_ad_);

    // Métodos de acceso
    std::string getNombre() const;
    void setNombre(const std::string& nom);
    std::string getTipo() const;
    void setTipo(const std::string& tip);
    std::string getRut() const;
    void setRut(const std::string& ru);
    std::string getTelefono() const;
    void setTelefono(const std::string& tel);
    std::string getDatosAdicionales() const;
    void setDatosAdicionales(const std::string& dat);

    // Método para mostrar la información
    std::string mostrarInformacion() const;
};

