#ifndef RESERVAS_H
#define RESERVAS_H

#include "Asistentes.h"
#include <vector>
#include <string>

class Reservas {
private:
    std::string nombre;
    std::string lugar;
    std::string tipo;
    std::string duracion;
    std::string otros;
    std::vector<std::string> Lista_Asistentes_;

public:
    Reservas(std::string tipo_, const std::vector<std::string>& Lista_Asistentes,
        std::string duracion_, std::string nombre_, std::string lugar_, std::string otros_);

    std::vector<std::string> getListaAsistentes();
    void setListaAsistentes(const std::vector<std::string>& lista);

    std::string getNombre();
    void setNombre(std::string nom);

    std::string getLugar();
    void setLugar(std::string lug);

    std::string getDur();
    void setDur(std::string Dura);

    std::string getTipo();
    void setTipo(std::string tip);

    std::string getOtros();
    void setOtros(std::string otro);

    std::string mostrarInformacion();

    //std::string mostrarLista();
    //std:: string estadisticas();
    Reservas() = default;
};

#endif
