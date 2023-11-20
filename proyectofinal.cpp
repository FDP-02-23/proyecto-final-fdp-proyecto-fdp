#include <iostream>
#include <string>
#include <vector> //permite usar vectores para almacenar datos mas facil
#include <ctime> //se utiliza para trabajar con el tiempo
#include <iomanip> //ayuda a formatear la salida
#include <fstream> //para el manejo de archivos 

using namespace std;

//struct para representar una mesa
struct Mesa {
    int numero;
    int capacidad;
    bool reservada;
};

//struct para representar una reserva
struct Reserva {
    string fecha;
    string hora;
    int numPersonas;
    int mesaAsignada;
    string nombreCliente;
    string correoCliente;
};

//funcion para mostrar mesas disponibles con capacidad suficiente
void mostrarMesasDisponibles(const vector<Mesa>& mesas, int numPersonas) {
    cout << "Mesas disponibles para " << numPersonas << " personas:" << endl;
    for (const Mesa& mesa : mesas) {
        if (!mesa.reservada && mesa.capacidad >= numPersonas) {
            cout << "Mesa #" << mesa.numero << " (Capacidad: " << mesa.capacidad << " personas)" << endl;
        }
    }
}

//funcion para realizar una reserva (se utilizara la hora del dispositivo del usuario para evitar que se hagan reservaciones en horarios pasados)
void hacerReserva(vector<Mesa>& mesas, vector<Reserva>& reservas) {
    string fecha, hora;
    int numPersonas;

    time_t now = time(0); //obtiene la hora actual en segundos
    tm* localTime = localtime(&now); //convierte la hora actual a una estructura de tiempo


    char currentTime[9];
    strftime(currentTime, 9, "%H:%M:%S", localTime); //formatea la hora actual

    string currentHour(currentTime);

    char opcionDia;
    cout << "Desea hacer la reserva para hoy (H) o para un dia futuro (F)?: ";
    cin >> opcionDia;

    if (opcionDia == 'H' || opcionDia == 'h') {
        if (currentHour >= "08:00:00") { 
            currentHour = "08:00";
        }
        fecha = "hoy";
    } else if (opcionDia == 'F' || opcionDia == 'f') {
        cout << "Ingrese la fecha: ";
        cin >> fecha;
        currentHour = "08:00";  //reinicia la hora para futuras reservas a las 8:00 AM
    } else {
        cout << "Opcion no valida. Seleccione 'H' para hoy o 'F' para un dia futuro." << endl;
        return;
    }

    cout << "Horarios disponibles: 08:00, 11:00, 13:00, 15:00, 17:00, 19:00" << endl;
    cout << "Ingrese la hora (HH:MM): ";
    cin >> hora;

    //comprueba que la hora sea válida
    if (hora != "08:00" && hora != "11:00" && hora != "13:00" && hora != "15:00" && hora != "17:00" && hora != "19:00") {
        cout << "Las reservas solo se permiten en horarios ya especificados." << endl;
        return;
    }

    cout << "Numero de personas: ";
    cin >> numPersonas;

    //buscar mesas disponibles que cumplan con la capacidad que pida el user
    mostrarMesasDisponibles(mesas, numPersonas);

    int mesaSeleccionada;
    cout << "Seleccione el numero de la mesa deseada: ";
    cin >> mesaSeleccionada;

    for (Mesa& mesa : mesas) {
        if (mesa.numero == mesaSeleccionada && !mesa.reservada) {
            mesa.reservada = true; //marca la mesa como reservada

            string nombre, correo;
            cout << "Ingrese su nombre: ";
            cin.ignore();
            getline(cin, nombre); //lee el nombre del cliente, incluyendo los espacios
            cout << "Ingrese su correo electronico: ";
            cin >> correo;

            Reserva nuevaReserva = {fecha, hora, numPersonas, mesa.numero, nombre, correo};
            reservas.push_back(nuevaReserva);  //agrega la reserva al vector de reservas
            cout << "Reserva exitosa para la Mesa #" << mesa.numero << endl;
            return;
        }
    }

    cout << "La mesa seleccionada no esta disponible." << endl;
}

//funcion para mostrar las reservas hechas
void verReservas(const vector<Reserva>& reservas, const string& password) {
    string empleadoPassword; //variable para almacenar la contraseña
    cout << "Ingrese la contrasenia de empleado: ";
    cin >> empleadoPassword;

    if (empleadoPassword == password) { //comprueba si la contraseña ingresada coincide con la contraseña proporcionada
        cout << "Reservas hechas:" << endl;
        for (const Reserva& reserva : reservas) { //itera a traves de cada reserva en el vector de reservas
            cout << "Fecha: " << reserva.fecha << " -- Hora: " << reserva.hora << " -- Mesa: #" << reserva.mesaAsignada
                 << " -- Personas: " << reserva.numPersonas << " -- Nombre: " << reserva.nombreCliente << " -- Correo: " << reserva.correoCliente << endl;
        }
    } else {
        cout << "Contrasenia incorrecta. No tiene acceso a ver las reservas." << endl;
    }

//funcion para limpiar la info de los vectores de reservas y reseñas
void eliminarReservasYResenas(vector<Reserva>& reservas) {
// Limpiar el vector de reservas
    reservas.clear();
    cout << "Todas las reservas y reseñas han sido eliminadas." << endl;
}

//funcion para generar los archivos de reservas y los de reseñas
void generarArchivos(const vector<Reserva>& reservas) {
    ofstream archivo("reservas_y_comentarios.txt");

    if (archivo.is_open()) {
        for (const Reserva& reserva : reservas) {
            // Escribe la información en el archivo
            archivo << "Fecha: " << reserva.fecha << " -- Hora: " << reserva.hora << " -- Mesa: #" << reserva.mesaAsignada
                    << " -- Personas: " << reserva.numPersonas << " -- Nombre: " << reserva.nombreCliente << " -- Correo: " << reserva.correoCliente << endl;
        }

        archivo.close();
        cout << "Archivo generado exitosamente: reservas_y_comentarios.txt" << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}



int main() {

  //vector donde se registran las mesas del restaurante
  vector<Mesa> mesas = { 
        {1, 4, false},
        {2, 6, false},
        {3, 2, false},
        {4, 4, false},
        {5, 8, false},
        {6, 4, false},
        {7, 6, false},
        {8, 2, false},
        {9, 4, false},
        {10, 8, false},
        {11, 4, false},
        {12, 6, false},
        {13, 2, false},
        {14, 4, false},
        {15, 8, false},
        {16, 4, false},
        {17, 6, false},
        {18, 2, false},
        {19, 4, false},
        {20, 8, false}
    };
  
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
                hacerReserva(mesas, reservas);
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
                         verReservas(reservas, empleadoPassword);
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
