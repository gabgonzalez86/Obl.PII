#include "Expediente.h"

#include "Expediente.h"

void cargarExpediente(Expediente &exp)
{
    printf("\INGRESE LOS DATOS EL EXPEDIENTE");
    printf("\nNumero: ");
    scanf("%ld", &exp.codigo);

    printf("\nCaratula: ");
    strcrear(exp.caratula);
    scan(exp.caratula);

    printf("\nNombre del escribana/o: ");
    strcrear(exp.nombre);
    scan(exp.nombre);

    printf("\nApellido del escribana/o: ");
    strcrear(exp.apellido);
    scan(exp.apellido);

    printf("\nCantidad de paginas: ");
    scanf("%d", &exp.cantidadPaginas);
}

void mostrarExpediente (Expediente exp)
{
    printf("\n**Datos del Expediente:** ");
    printf("\nCodigo: %ld", exp.codigo);
    printf("\nCaratula: ");
    print(exp.caratula);
    printf("\nEscribana: ");
    print(exp.nombre);
    printf(" ");
    print(exp.apellido);
    printf("\nCantidad de paginas: %ld\n", exp.cantidadPaginas);
}

long darCodigo(Expediente exp)
{
    return exp.codigo;
}

int  darCantidadPaginas (Expediente exp)
{
    return exp.cantidadPaginas;
}
