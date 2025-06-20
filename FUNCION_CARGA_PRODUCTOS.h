#ifndef FUNCION_CARGA_PRODUCTOS_H_INCLUDED
#define FUNCION_CARGA_PRODUCTOS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

//DECLARACION DE STRUCT PRODUCTO

struct Producto{
    int codProducto;
    string nombreProducto;
    float precioVenta;
    float precioCompra;
    int stockDisponible;
    int codMarca;
};
//DECLARACION FUNCION PARA CARGAR PRODUCTOS

bool cargaProductos(Producto productos[]);

#endif
