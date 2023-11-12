#include <iostream>
#include <fstream> //libreria para los archivos txt
using namespace std;
void comentariosUsuario();
void resenia();

int main()
{
    int opcion,repiteMenu;
    
do {
    cout << "Seleccione un dia para ver la disponibilidad de las mesas\n";
    cout << "1.Dejar un comentario sobre nustros servicios: \n";
    cout << "2.Ver resenias:\n";
    cout << "3.Caficar servicion: \n";
    cin  >> opcion;
    system("cls");
    switch (opcion)
    {
    
    case 1:
        cout<<"Esta en el apartado de comentarios.\n";
        comentariosUsuario();
        break;
    case 2:
        cout<<"Resenias de usuarios\n";
        break;
    case 3:
        cout<<"calificar servicio\n";
        resenia();
        break;
    default:cout<<"<elija una opcion correcta";
        break;
    }
        cout << "Desea hacer otro movimiento? (1-Si, 2-No): \n";
        cin >> repiteMenu;
} while (repiteMenu == 1);
cout<<"Muchas gracias por preferirnos :)";
    return 0;
}


void comentariosUsuario(){
string comentario,nombreCliente;
int opcion;

cout<<"Ingrese su nombre por favor: ";
cin>>nombreCliente;
cin.ignore();//ignorara el bufer antes de usar el getline
cout<<"Esrcribra su comentario por favor y presione ENTER cuando termine: \n";
getline(cin, comentario);//guardara toda la reseña del usuario.
cout<<"Esta seguro de dejar este comentario? (1=si/2=no)\n";
cin>>opcion;

if (opcion == 1) {
        cout << "Muchas gracias por brindarnos sus comentarios, los tomaremos en cuenta para mejorar la experiencia.\n";

        // Guardar el comentario en un archivo
        ofstream archivo_comentarios("comentarios.txt", ios::app); // Abre el archivo en modo append
        if (archivo_comentarios.is_open()) {
            archivo_comentarios << "Nombre: " << nombreCliente << "\nComentario: " << comentario << "\n\n";
            archivo_comentarios.close();
        } else {
            cout << "No se pudo abrir el archivo para guardar el comentario.\n";
        }
    }
}



void resenia(){
int  calificacion, estrellas;
string nombre;

cout << "ingrese su nombre\n";
cin >> nombre;
cout << "califique nuestros servicios del 1 al 5, siendo 5 la maxima nota: \n";
cin >> estrellas;

if (estrellas >= 1 && estrellas <= 5)
{
    for (int i = 0; i < estrellas; i++)
    {
        cout << "*";
    }
    calificacion = estrellas;
}
else
    cout << "ponga un numero dentro del rango por favor\n";
}