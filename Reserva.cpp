#include <iostream>
using namespace std;
void comentariosUsuario();
void resenia();

int main()
{
    int opcion,repiteMenu,calificarServicio;
    
do {
    cout << "Seleccione un dia para ver la disponibilidad de las mesas\n";
    cout << "1.Dejar un comentario sobre nustros servicios: \n";
    cout << "2.Ver resenias:\n";
    cout << "3.Caficar servicion: \n";
    cin >> opcion;
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
cout<<"Esrcribra su comentario por favor y presione ENTER cuando termine: ";
cin>>comentario;
cout<<"Esta seguro de dejar este comentario? (1=si/2=no)\n";
cin>>opcion;
if (opcion == 1)
{
    cout<<"Muchas gracias por brindarnos sus comentarios, los tomaremos en cuenta para mejorar la experencia.\n";
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
}
else
    cout << "ponga un numero dentro del rango por favor\n";
}