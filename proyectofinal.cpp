#include <iostream>

using namespace std;

int main() {
  
    //menu principal y estructura base del programa
    while (true) {
        int opcion;
        cout << "Bienvenido a X!" << endl;
        cout << "Menu principal:" << endl;
        cout << "1. Hacer una reserva" << endl;
        cout << "2. Menu de administrador" << endl;
        cout << "3. Ver horarios de servicio" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                //funcion para hacer una reserva
                break;
            case 2:
                // Menú de administrador
                int opcionAdmin;
                cout << "Menu de administrador:" << endl;
                cout << "1. Ver reservas hechas" << endl;
                cout << "2. Ver resenias hechas" << endl;
                cout << "3. Eliminar reservas y/o resenias" << endl;
                cout << "4. Generar archivos con las reservas y comentarios hechos" << endl;
                cout << "Seleccione una opcion: ";
                cin >> opcionAdmin;

                switch (opcionAdmin) {
                    case 1:
                        //funcion para ver reservas hechas
                        break;
                    case 2:
                        //funcion para ver reseñas hechas
                        break;
                    case 3:
                        //funcion para eliminar reservas y/o reseñas
                        break;
                    case 4:
                        //funcion para generar archivos con reservas y comentarios
                        break;
                    default:
                        cout << "Opción no válida en el menú de administrador." << endl;
                        break;
                }
                break;
            case 3:
                cout << "Horarios de servicio: 08:00, 11:00, 13:00, 15:00, 17:00, 19:00" << endl;
                break;
            case 4:
                cout << "Gracias por visitarnos. Hasta luego!" << endl;
                return 0;
            default:
                cout << "Por favor, seleccione una opcion valida" << endl;
                break;
        }
    }

    return 0;
}
