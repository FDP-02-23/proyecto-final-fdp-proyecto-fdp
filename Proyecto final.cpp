#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Reserva {
    int id;
    string fecha;
    int numero_personas;

    Reserva(int _id, const string& _fecha, int _numero_personas)
        : id(_id), fecha(_fecha), numero_personas(_numero_personas) {}
};

class Restaurante {
private:
    vector<Reserva> reservas;

public:
    // Muestra todas las reservas actuales
    void mostrarReservas() const {
        cout << "Reservas actuales:\n";
        for (const auto& reserva : reservas) {
            cout << "ID: " << reserva.id << ", Fecha: " << reserva.fecha << ", Personas: " << reserva.numero_personas << "\n";
        }
        cout << "-------------------------\n";
    }

// Cancela una reserva por ID
 void cancelarReserva(int idReserva) {
        auto it = find_if(reservas.begin(), reservas.end(),
            [idReserva](const Reserva& r) { return r.id == idReserva; });

        if (it != reservas.end()) {
            reservas.erase(it);
            cout << "Reserva cancelada con éxito.\n";
        } else {
            cout << "No se encontró la reserva con el ID proporcionado.\n";
        }
    }

    // Modifica una reserva por ID, cambiando fecha y número de personas
    void modificarReserva(int idReserva, const string& nuevaFecha, int nuevoNumeroPersonas) {
        auto it = find_if(reservas.begin(), reservas.end(),
            [idReserva](const Reserva& r) { return r.id == idReserva; });

        if (it != reservas.end()) {
            it->fecha = nuevaFecha;
            it->numero_personas = nuevoNumeroPersonas;
            cout << "Reserva modificada con éxito.\n";
        } else {
            cout << "No se encontró la reserva con el ID proporcionado.\n";
        }
    }

    // Agrega una nueva reserva al restaurante
    void agregarReserva(const Reserva& nuevaReserva) {
        reservas.push_back(nuevaReserva);
        cout << "Reserva añadida con éxito.\n";
    }

    // Recomienda tres platos de comida
    vector<string> recomendarPlatos() {
        return {"Pasta", "Carne asada", "Hamburguesa doble carne"};
    }
};

int main() {
    Restaurante restaurante;

    // Crear algunas reservas
    restaurante.mostrarReservas();
    restaurante.cancelarReserva(123);

    restaurante.mostrarReservas();
    restaurante.modificarReserva(456, "2023-01-01", 4);

    restaurante.mostrarReservas();

    vector<string> platosRecomendados = restaurante.recomendarPlatos();
    cout << "Platos recomendados:\n";
    for (const auto& plato : platosRecomendados) {
        cout << plato << "\n";
    }

    return 0;
}
