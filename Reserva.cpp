#include <iostream>
#include <fstream> //libreria para los archivos txt
using namespace std;
void comentariosUsuario();
void verResenias();
void resenia();

int main()
{
    int opcion,repiteMenu;
    
do {
    cout << "Seleccione una de las opciones\n";
    cout << "1.Dejar un comentario sobre nustros servicios: \n";
    cout << "2.Ver resenias:\n";
    cout << "3.Caficar servicion: \n";
    cout << "su opcion es: ";
    cin  >> opcion;
    system("cls");
    switch (opcion)
    {
    
    case 1:
        cout<<"--------Esta en el apartado de comentarios--------\n";
        comentariosUsuario();
        
        break;
    case 2:
        cout<<"--------Resenias de usuarios--------\n";
        verResenias();
        break;
    case 3:
        cout<<"--------calificar servicio--------\n";
        resenia();
        
        break;
    default:cout<<"Elija una opcion correcta \n";
        break;
    }
        cout << "Desea hacer otro movimiento? (1-Si, 0-No): \n";
        cin >> repiteMenu;
        system("cls");
} while (repiteMenu == 1);
cout<<"Muchas gracias por preferirnos :)";
    return 0;
}


void comentariosUsuario(){
string comentario,nombreCliente,apellido_cliente;
int opcion;

cin.ignore();//ignorara el bufer antes de usar el getline
cout<<"Ingrese su nombres por favor: \n";
getline(cin, nombreCliente);
cout<<"Ingrese su apellidos por favor: \n";
getline(cin, apellido_cliente);
cout<<"Esrcribra su comentario por favor y presione ENTER cuando termine: \n";
getline(cin, comentario);//guardara toda la reseña del usuario.
cout<<"Esta seguro de dejar este comentario? (1=si/2=no)\n";
cin>>opcion;
system("cls");

if (opcion == 1) {
        cout << "Muchas gracias por brindarnos sus comentarios, los tomaremos en cuenta para mejorar la experiencia.\n";

        // Guardar el comentario en un archivo
        ofstream archivo_comentarios("comentarios.txt", ios::app); // Crea el archivo a nombre de comentarios.txt
        if (archivo_comentarios.is_open())//abre el archivo y comienza a capturar los datos
        {
            archivo_comentarios << "Nombre del cliente: " << nombreCliente << "\nApellido del cliente: "<<apellido_cliente <<"\nComentario: " << comentario << "\n\n";
            archivo_comentarios.close();//cierra el archivo y deja de capturar los datos
        } else {
            cout << "No se pudo abrir el archivo para guardar el comentario.\n";
        }
    }
}

void verResenias(){
    ifstream archivo_comentarios("comentarios.txt");
    string linea;

    if (archivo_comentarios.is_open()) {
        while (getline(archivo_comentarios, linea)) {
            cout << linea << endl;
        }
        archivo_comentarios.close();
    } else {
        cout << "No se pudo abrir el archivo de resenias." << endl;
    }

}

void resenia()
{
    int calificacion, estrellas;
    string nombre;

    cout << "ingrese su nombre\n";
    cin >> nombre;
    do
    {
        cout << "califique nuestros servicios del 1 al 5, siendo 5 la maxima nota: \n";
        cin >> estrellas;
        system("cls");

        if (estrellas >= 1 && estrellas <= 5)
        {
            //imprimira el nombre del cliente y el numero de estrellas que puso el cliente
            cout<<"Nombre del cliente: "<<nombre<<"\n";
            cout<<"Numero de estrellas que puso el cliente: ";
            
            for (int i = 0; i < estrellas; i++)
            {
                cout << "*";  
                
            }
            cout << "\n";
            
        }
        else
            cout << "ponga un numero dentro del rango por favor\n";
    } while (estrellas < 1 || estrellas > 5);//se ocupara un do while por si el usuario ingresa un numero fuera del rango, el programa le volvera a solicitar el numero
}