#include "Reservas.h"
#include "Asistentes.h"
#include <vector>
#include <string>

Reservas::Reservas(std::string tipo_, const std::vector<std::string>& Lista_Asistentes,
    std::string duracion_, std::string nombre_, std::string lugar_, std::string otros_)
    : tipo(tipo_), Lista_Asistentes_(Lista_Asistentes), duracion(duracion_), nombre(nombre_), lugar(lugar_), otros(otros_) {}

std::vector<std::string> Reservas::getListaAsistentes() {
    return Lista_Asistentes_;
}

void Reservas::setListaAsistentes(const std::vector<std::string>& lista) {
    Lista_Asistentes_ = lista;
}

std::string Reservas::getNombre() {
    return nombre;
}

void Reservas::setNombre(std::string nom) {
    nombre = nom;
}

std::string Reservas::getLugar() {
    return lugar;
}

void Reservas::setLugar(std::string lug) {
    lugar = lug;
}

std::string Reservas::getDur() {
    return duracion;
}

void Reservas::setDur(std::string Dura) {
    duracion = Dura;
}

std::string Reservas::getTipo() {
    return tipo;
}

void Reservas::setTipo(std::string tip) {
    tipo = tip;
}

std::string Reservas::getOtros() {
    return otros;
}

void Reservas::setOtros(std::string otro) {
    otros = otro;
}

std::string Reservas::mostrarInformacion() {
    std::string ss = "Nombre: " + nombre + "\nLugar: " + lugar + "\nDuracion: " + duracion + "\nTipo: " + tipo + "\nOtros: " + otros;
    return ss;
}
/*
std:: string Reservas :: mostrarLista(){
    std:: string sa; 
    for (int i = 0;i < Lista_Asistentes_.size(); i++) {
            sa += Lista_Asistentes[i].mostrarInformacion()+"\n\n";
        } 
    return sa; 
} 
std:: string Reservas:: estadisticas(){
    std::  string sc;
    sc += "el total de asistentes es: "+ to_string(Lista_Asistentes_.size())+"\n\n";
    return sc;
}

*/