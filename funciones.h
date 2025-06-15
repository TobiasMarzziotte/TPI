#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


 int suma(int n1, int n2);

 void pedirNumeros();

struct FormaPago {
    string codigo;  // EF, MP, TR, TC, CT
    string nombre;
    int porcentaje;
};

void CargarFormasPago(FormaPago formasPago[]);


#endif // FUNCIONES_H_INCLUDED
