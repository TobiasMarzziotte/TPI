#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


// DECLARACION DE STRUCT

struct marca{
    int codigoMarca;
    string nombreMarca;
    };

struct FormaPago {
    string codigo;  // EF, MP, TR, TC, CT
    string nombre;
    int porcentaje;
};

struct Producto{
    int codProducto;
    string nombreProducto;
    float precioVenta;
    float precioCompra;
    int stockDisponible;
    int codMarca;
};

struct venta{
    int numeroCompra;
    int codigoProducto;
    string formaPago;
    int cantidadVendida;
    int codigoCliente;
    int diaVenta;

};





// DECLARACION DE FUNCIONES

void reportePunto2(int contadorVentasPorForma[], int totalVentas, FormaPago formasPago[]);

int menuPrincipal();

void mayusculas(string &str);

void CargarFormasPago(FormaPago formasPago[]);

void cargarMarcas(marca marcas[], int cantidad);

void cargarVentas(int contadorVentasPorForma[], int& totalVentas, FormaPago formasPago[]);

bool cargaProductos(Producto productos[]);




#endif // FUNCIONESTPI_H_INCLUDED

#endif // FUNCIONES_H_INCLUDED
