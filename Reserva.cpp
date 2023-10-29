#include <iostream>
using namespace std;
void mesas();

int main()
{
    int opcion;

    cout << "Seleccione un dia para ver la disponibilidad de las mesas\n";
    cout << "1.Lunes \n";
    cout << "2.Martes \n";
    cout << "3.Miercoles \n";
    cout << "4.Jueves \n";
    cout << "5.Viernes \n";
    cout << "6.Sabado \n";
    cout << "7.Domingo \n";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cout<<"Disponibilidad del dia lunes\n";
        cout<<"Elija una mesa que este disponible\n";
        mesas();
        break;
    case 2:
        cout<<"Disponibilidad del dia martes\n";
        cout<<"Elija una mesa que este disponible\n";
        mesas();
        break;
    case 3:
        cout<<"Disponibilidad del dia miercoles\n";
        cout<<"Elija una mesa que este disponible\n";
        mesas();
        break;
    case 4:
        cout<<"Disponibilidad del dia jueves\n";
        cout<<"Elija una mesa que este disponible\n";
        mesas();
        break;
    case 5:
        cout<<"Disponibilidad del dia viernes\n";
        cout<<"Elija una mesa que este disponible\n";
        mesas();
        break;
    case 6:
        cout<<"Disponibilidad del dia sabado\n";
        cout<<"Elija una mesa que este disponible\n";
        mesas();
        break;
    case 7:
        cout<<"Disponibilidad del dia domingo\n";
        cout<<"Elija una mesa que este disponible\n";
        mesas();
        break;

    default:cout<<"<elija una opcion correcta";
        break;
    }

    return 0;
}

void mesas(){
    int eleccion,cantidadPErsonas,confirmacion;
    float hora;
    string fecha,correo;
    cout<<"Mesa 1 - disponible\n";
    cout<<"Mesa 2 - disponible\n";
    cout<<"Mesa 3 - disponible\n";
    cin>>eleccion;
    switch (eleccion)
    {
    case 1:
    while (true)
    {
        cout<<"Escriba la fecha de reservacion (dd/mm/anio) \n";
        cin>>fecha;
        cout<<"Escriba la hora de reservacion en formato 24 horas\n";
        cin>>hora;
        cout<<"Escriba la cantidad de personas que estara en la mesa (maximo 4)\n";
        cin>>cantidadPErsonas;
        if (cantidadPErsonas > 4)
        {
            cout<<"La cantidad maxima es de 4 personas";
        }else{
            break;
        }
    }      
        cout<<"Escriba su correo electronico para que le enviemos la confirmacion de reserva: ";
        cin>>correo;
        cout<<"Esta seguro de confirmar la reservacion 1-si, 2-no\n";
        cin>>confirmacion;
        cout<<"Se realizo su confirmacion con exito, se le envio el comprobante a su correo.";
        break;

    case 2:
    while (true)
    {
        cout<<"Escriba la fecha de reservacion (dd/mm/anio) \n";
        cin>>fecha;
        cout<<"Escriba la hora de reservacion en formato 24 horas\n";
        cin>>hora;
        cout<<"Escriba la cantidad de personas que estara en la mesa (maximo 4)\n";
        cin>>cantidadPErsonas;
        if (cantidadPErsonas > 4)
        {
            cout<<"La cantidad maxima es de 4 personas";
        }else{
            break;
        }
    }            
        cout<<"Escriba su correo electronico para que le enviemos la confirmacion de reserva: ";
        cin>>correo;
        cout<<"Esta seguro de confirmar la reservacion 1-si, 2-no\n";
        cin>>confirmacion;
        cout<<"Se realizo su confirmacion con exito, se le envio el comprobante a su correo.";
        break;

    case 3:
    while (true)
    {
        cout<<"Escriba la fecha de reservacion (dd/mm/anio) \n";
        cin>>fecha;
        cout<<"Escriba la hora de reservacion en formato 24 horas\n";
        cin>>hora;
        cout<<"Escriba la cantidad de personas que estara en la mesa (maximo 4)\n";
        cin>>cantidadPErsonas;
        if (cantidadPErsonas > 4)
        {
            cout<<"La cantidad maxima es de 4 personas\n";
        }else{
            break;
        }
    }
        cout<<"Escriba su correo electronico para que le enviemos la confirmacion de reserva: \n";
        cin>>correo;
        cout<<"Esta seguro de confirmar la reservacion 1-si, 2-no\n";
        cin>>confirmacion;
        cout<<"Se realizo su confirmacion con exito, se le envio el comprobante a su correo.";
    
        
        
        break;    
    default: cout<<"Elija una mesa por favor";
        break;
    }
}