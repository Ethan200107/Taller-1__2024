// Taller 1_2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>
#include <sstream>
#include "Reservas.h"
#include "Asistentes.h"
using namespace std;

//Bloque para obtener el informe
static void hacer_Informes(vector<Reservas> Lista_Reservas) {
    cout<< "los eventos que estan disponibles son las siguientes:"<< endl;
    for (int i = 0;i < Lista_Reservas.size(); i++) {
            cout << Lista_Reservas[i].mostrarInformacion();
            //cout << Lista_Reservas[i].mostrarLista();
            //cout<< Lista_Reservas[i].estadisticas();
        }
        

    
    

}

// Bloque para ver la reserve por nombre y tipo o ver todas las reservas
static void consultar_eventos(vector<Reservas>Lista_Reservas) {
    cout << "Reservas" << endl;
    string nombre, tipo;
    int option;
    cout << "1) Consultar por nombre y tipo de reserva" << endl;
    cout << "2) Ver toda la lista de reservas" << endl;
    cout << "opcion: "; 
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "nombre: "; 
        cin >> nombre;

        cout << "tipo: "; 
        getline(cin,tipo);
        
        for (int i = 0; i < Lista_Reservas.size(); i++) {
            if (Lista_Reservas[i].getNombre() == nombre && Lista_Reservas[i].getTipo() == tipo) {
                cout << "-----------------------------" << endl;
                cout << Lista_Reservas[i].mostrarInformacion() << endl;
                cout << "-----------------------------" << endl;
            }
        }

        break;
    case 2:
        for (int i = 0;i < Lista_Reservas.size(); i++) {
            cout << "-----------------------------" << endl;
            cout << Lista_Reservas[i].mostrarInformacion() << endl;
            cout << "-----------------------------" << endl;
        }

        break;

    default:
        break;
    }
}

// Bloque de saida y guardado del programa
static void salir(vector<Asistentes>Lista_Asistentes, vector<Reservas> Lista_Reservas) {
    ofstream arch("Asistentes.txt");
    for (int i = 0;i < Lista_Asistentes.size();i++) {
        arch << Lista_Asistentes[i].getTipo() << "," << Lista_Asistentes[i].getRut() << "," << Lista_Asistentes[i].getNombre() << "," << Lista_Asistentes[i].getTelefono() << "," << Lista_Asistentes[i].getDatosAdicionales();
        if (i < Lista_Asistentes.size()-1) {
            arch << endl;
        }
    }
    arch.close();
    vector<string> ruts;
    ofstream arch1("Reservas.txt");
    for (int i = 0; i < Lista_Reservas.size(); i++) {
        ruts = Lista_Reservas[i].getListaAsistentes();
        
        arch1 << Lista_Reservas[i].getTipo() << "," << (Lista_Reservas[i].getListaAsistentes().size()) << ",";
        for (int r = 0; r < ruts.size(); r++) {
            arch1 << ruts[r] << ",";
        }
        arch1 << Lista_Reservas[i].getDur() << "," << Lista_Reservas[i].getNombre() << "," << Lista_Reservas[i].getLugar() << "," << Lista_Reservas[i].getOtros();
        
        if (i < Lista_Reservas.size() - 1) {
            arch1 << endl;
        }
        cout << endl;
    }
    arch1.close();
    
}

// Bloque de Eliminar el evento a aprtir del nombre y tipo
static vector<Reservas> Eliminar_Evento(vector<Reservas>Lista_Reservas) {
    cout << "Eliminar evento con nombre y el tipo de evento" << endl;
    string nombre, tipo;
    cout << "Nombre del evento: "; cin >> nombre;
    cout << "Tipo de evento: "; cin >> tipo;
    vector<Reservas> nuevo;
    for (int i = 0; i < Lista_Reservas.size(); i++) {
        if (Lista_Reservas[i].getNombre() != nombre || Lista_Reservas[i].getTipo() != tipo) {
            nuevo.push_back(Lista_Reservas[i]);
        }
    }
    return nuevo;
}

// Bloque de Eliminar Asistente a apartir del rut
static vector<Asistentes> Eliminar_Asistente(vector<Asistentes> Lista_Asistentes) {
    cout << "Ingrea rut del asistente a eliminar" << endl;
    string rut;
    cout << "Rut: "; cin >> rut;

    vector<Asistentes> nueva;

    for (int i = 0; i < Lista_Asistentes.size(); i++) {
        if (Lista_Asistentes[i].getRut() != rut ) {
            nueva.push_back(Lista_Asistentes[i]);
        }
    }

    return nueva;
}

// Bloque de Hacer evento
static vector<Reservas> Hacer_evento(vector<Reservas>Lista_Reservas) {

    string tipo, Lista_Asistentes, duracion, nombre, lugar, datos_Adicionales;
    
    cout << "tipo: "; cin >> tipo;
    int cant;
    cout << "Cantidad de Asistentes: "; cin >> cant;
    vector<string> ruts;
    string rut;
    for (int i = 0; i < cant ; i++) {
        cout << "Rut del asistente: "; cin >> rut;
        // poner verificacion de existencia

        ruts.push_back(rut);
    }
    cout << "Duracion: "; cin >> duracion;
    cout << "nombre: "; cin >> nombre;
    cout << "lugar: "; cin >> lugar;
    cout << "datos adicionales (si hay) (ejemplo: calle, dia, entradas , etc): "; cin >> datos_Adicionales;

    // Crear un nuevo objeto Reservas con los datos ingresados
    Reservas reserva = Reservas(tipo, ruts, duracion, nombre, lugar, datos_Adicionales);

    // Agregar el nuevo evento a la lista de reservas
    Lista_Reservas.push_back(reserva);

    cout << "¡Evento creado exitosamente!" << endl;
    
    return Lista_Reservas;
}

// Bloque de Registrar Asistente
static vector<Asistentes> Registrar_asistente(vector<Asistentes>Lista_Asistentes) {
    
    string tipo, rut, nombre, telefono, datos_ad;

    // Solicitar los datos del nuevo asistente al usuario
    cout << "Ingrese el tipo de asistente: "; cin >> tipo;

    cout << "Ingrese el RUT del asistente: "; cin >> rut;

    cout << "Ingrese el nombre del asistente: "; cin >> nombre;

    cout << "Ingrese el teléfono del asistente: "; cin >> telefono;

    cout << "Ingrese datos adicionales del asistente (si hay) (ejemplo: cobra 23000,trabaja demasiado, tiene asma ): "; cin >> datos_ad;

    // Crear un nuevo objeto Asistentes
    Asistentes nuevo_asistente(tipo, rut, nombre, telefono, datos_ad);

    // Agregar el nuevo asistente a la lista
    Lista_Asistentes.push_back(nuevo_asistente);

    cout << "¡Asistente registrado exitosamente!" << endl;

    return Lista_Asistentes;
}

// Bloque de consultar asistentes por rut o todos los que se encuentran en la base de datos
static void consultar_asistentes(vector<Asistentes> Lista_Asistentes) {

    cout << "----------------------------------------" << endl;
    cout << "1) ver a un asistente (ingresar rut)" << endl;
    cout << "2) ver a todos los asistentes" << endl;
    int option;
    cout << "opcion: ";  cin >> option;
    cout << "----------------------------------------" << endl;

    string rut;
    bool bandera = false;
    switch (option)
    {
    case 1:
        cout << "Ingrear rut: "; cin >> rut;
        cout << "----------------------------------------" << endl;
        for (int i = 0; i < Lista_Asistentes.size(); i++) {
            if (rut == Lista_Asistentes[i].getRut()) {
                cout << Lista_Asistentes[i].mostrarInformacion() << endl;
                bandera = true;
                break;
            }
        }
        if (bandera == false) {
            cout << "no se encontro el rut dentro de la base de datos, intente con otro" << endl;
        }
        cout << "----------------------------------------" << endl;
        break;
    case 2:
        for (int i = 0; i < Lista_Asistentes.size(); i++) {
            cout << i << ")" << endl;
            cout << Lista_Asistentes[i].mostrarInformacion() << endl;
            cout << "----------------------------------------" << endl;
        }
        break;
    default:
        break;
    }
}

// Bloque de Lectura de Reservas.txt
static vector<Reservas> Lectura_Reservas() {
    vector<Reservas> Lista;
    string linea;
    // estructura para generar una variable archivo
    ifstream arch("Reservas.txt");
    if (!arch) {
        cout << "No se encontro archivo de Reservas";
        return Lista;
    }

    while (getline(arch,linea)) {
        // datos para rellenar el vector
        string tipo;
        int cantidad_De_Asistentes;
        vector<string> Lista_Asistentes;
        string datos_Adicionales;

        istringstream iss(linea);

        string token;

        vector<string> vec;  // Usar un vector dinámico para almacenar los tokens
        // hacer la separacion
        while (getline(iss, token, ',')) {
            vec.push_back(token);
           
        }
         
        tipo = vec[0];

        cantidad_De_Asistentes = stoi(vec[1]);
        int i;
        for (i = 0; i < cantidad_De_Asistentes; i++) {
           
            Lista_Asistentes.push_back(vec[i + 2]);

        }
        i += 2;
        string duracion = vec[i];
        string nombre = vec[i + 1];
        string lugar = vec[i + 2];
        for (int i = cantidad_De_Asistentes + 5; i < vec.size(); i++) {
            
            datos_Adicionales = datos_Adicionales + vec[i];
            if (i < vec.size() - 1) {
                datos_Adicionales = datos_Adicionales + ",";
            }
           
        }
        // crear y rellear objeto Reservas
        // Reservas(tipo_,Lista_Asistentes,duracion_,nombre_,lugar_,otros_);
        Reservas reserva =  Reservas(tipo,Lista_Asistentes,duracion,nombre,lugar,datos_Adicionales);
        Lista.push_back(reserva);
    }
    return Lista;
}

// Bloque de Lectura de Asistentes.txt
static vector<Asistentes> Lectura_Astsitentes() {
    
    vector<Asistentes> Lista;
    string linea;
    // estructura para generar una variable archivo
    ifstream arch("Asistentes.txt");
    if (!arch) {
        cout << "No se encontro archivo de Asistentes";
    }

    while (getline(arch, linea)) {
        istringstream iss(linea);

        string token;

        vector<string> vec;  // Usar un vector dinámico para almacenar los tokens
        // hacer la separacion
        while (getline(iss, token, ',')) {
            vec.push_back(token);
            
        }
        // datos para rellenar el vector
        string tipo, rut, nombre, fono,datos_adicionales;
        tipo = vec[0];
        rut = vec[1];
        nombre = vec[2];
        fono = vec[3];
        for (int i = 4; i < vec.size(); i++) {
            datos_adicionales = datos_adicionales + vec[i];
            if (i < vec.size() - 1) {
                datos_adicionales = datos_adicionales + ",";
            }
        }
        // se crea el objeto asistentes
        // se rellena el vector de los asistentes{
        Asistentes asistente(tipo, rut, nombre, fono, datos_adicionales);
        
        Lista.push_back(asistente);
    }
    
    return Lista;
}

// Bloque de menu
static void menu() {
    // lista de eventos
    vector<Reservas> Lista_Reservas;
    //lectura de Reservas
    Lista_Reservas = Lectura_Reservas();
    // Lista de asistentes
    vector<Asistentes> Lista_Asistentes;
    // lectura de asistentes
    Lista_Asistentes = Lectura_Astsitentes();

    // iniciamos el menu
    int option = 0 ;
    while (option != 8) {
        cout << "********** Menu **********" << endl;
        cout << "1) Consultar lista de asistentes" << endl;
        cout << "2) Consultar reservas" << endl;
        cout << "3) Registrar asistente" << endl;
        cout << "4) Hacer informes" << endl;
        cout << "5) Hacer evento" << endl;
        cout << "6) Eliminar Asistente" << endl;
        cout << "7) Eliminar evento" << endl;
        cout << "8) salir y guardar" << endl;
        cout << "*******************************" << endl;

        cout << "Opcion: "; cin >> option ;
        cout << "----------------------------------------" << endl;
        switch (option)
        {
        case 1:
            consultar_asistentes(Lista_Asistentes);
            break;
        case 2:
            consultar_eventos(Lista_Reservas);
            break;
        case 3:
            Lista_Asistentes = Registrar_asistente(Lista_Asistentes);
            break;
        case 4:
            hacer_Informes(Lista_Reservas);
            break;
        case 5:
            Lista_Reservas = Hacer_evento(Lista_Reservas);
            break;
        case 6:
            Lista_Asistentes = Eliminar_Asistente(Lista_Asistentes);
            break;
        case 7:
            Lista_Reservas = Eliminar_Evento(Lista_Reservas);
            break;
        case 8:
            salir(Lista_Asistentes,Lista_Reservas);
            break;
        default:
            cout << "Ingresa una opcion del menu!" << endl;
            break;
        }
        cout << "----------------------------------------" << endl;
    }

}

// Inicio de sesion de un unico admin
static void Inicio_De_Sesion() {
    string name, Password;
    while (name != "Jose" || Password != "123123") {

        cout << "Username:"; cin >> name;
        cout << "Password:"; cin >> Password;

        if (name != "Jose" || Password != "123123") {
            cout << "Contraseña o nombre incorrecto" << endl;
            cout << "------------------------------" << endl;
        }
    }
   
    menu();

}

// inicio del programa
int main()
{
    Inicio_De_Sesion();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
