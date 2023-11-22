#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Reserva {
    int id;
    string fecha;
    int numero_personas;

   // Constructor para facilitar la creación de reservas
    Reserva(int _id, const string& _fecha, int _numero_personas)
        : id(_id), fecha(_fecha), numero_personas(_numero_personas) {}
};

class Restaurante {
private:
    vector<Reserva> reservas;

public:
    void mostrarReservas() const {
        cout << "Reservas actuales:\n";
        for (const auto& reserva : reservas) {
            cout << "ID: " << reserva.id << ", Fecha: " << reserva.fecha << ", Personas: " << reserva.numero_personas << "\n";
        }
        cout << "-------------------------\n";
    }

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

void modificarReserva(int idReserva, const string& nuevaFecha, int nuevoNumeroPersonas) {
        auto it = find_if(reservas.begin(), reservas.end(),
            [idReserva](const Reserva& r) { return r.id == idReserva; });
