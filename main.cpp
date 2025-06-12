#include <iostream>

using namespace std;

struct Producto{
    int codProducto;
    string nombreProducto;
    float precioVenta;
    float precioCompra;
    int stockDisponible;
    int codMarca;
};

int main()
{
    int opc;
    Producto productos[20];

 while(true){

    system("cls");

    cout << "-------Menu principal-------" << endl;
    cout << endl;
    cout << "1) Cargar lote de marcas" << endl;
    cout << "2) Cargar lote de productos" << endl;
    cout << "3) Cargar lote de formas de pago" << endl;
    cout << "4) Cargar lote de ventas" << endl;
    cout << "5) Mostrar reportes" << endl;
    cout << "0) Salir del Programa" << endl;
    cout << endl;
    cout << "Opcion: ";
    cin >> opc;

    system("cls");

    switch (opc){
    case 1:
        system("cls");
        system("pause");
        break;

    case 2:
        system("cls");

        cout << "Ingrese el listado de 20 productos: ";
        cout << "" << endl;

        for (int i=0; i<20; i++){

            cout << "Ingrese el codigo del producto: ";
            cin >> productos[i].codProducto;

            cout << "Ingrese el nombre del producto: ";
            cin >> productos[i].nombreProducto);

            cout << "Ingrese el precio de venta del producto: ";
            cin >> productos[i].precioVenta;

            cout << "Ingrese el precio de compra del producto: ";
            cin >> productos[i].precioCompra;

            cout << "Ingrese la cantidad de stock disponible del producto: ";
            cin >> productos[i].stockDisponible;

            cout << "Ingrese el codigo de marca del producto: ";
            cin >> productos[i].codMarca;

            cout << "----------------------------------------------";
        }
        system("pause");
        break;

    case 3:
        system("cls");
        system("pause");
        break;

    case 4:
        system("cls");
        system("pause");
        break;

    case 5:
        system("cls");
        system("pause");
        break;

    case 0:
        system ("cls");
        cout << "FIN DEL PROGRAMA, PRESIONE CUALQUIER TECLA PARA TERMINAR";
        return 0;
        break;

    default:
        system("cls");
        cout<< "Opcion invalida" << endl;
        cout << endl;
        system("pause");
    }


 }

    return 0;
}
