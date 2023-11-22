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

