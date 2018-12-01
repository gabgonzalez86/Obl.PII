#include "Expediente.h"
/*
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
}*/

void cargarExpediente(Expediente &exp, long codigo)
{
    exp.codigo = codigo;

    printf("\nINGRESE LOS DATOS EL EXPEDIENTE");

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
    printf("\nCantidad de paginas: %d\n", exp.cantidadPaginas);
}

long darCodigo(Expediente exp)
{
    return exp.codigo;
}

int  darCantidadPaginas (Expediente exp)
{
    return exp.cantidadPaginas;
}

void darCaratula(Expediente exp, String &pCaratula)
{
    strcrear(pCaratula);
    strcop(pCaratula, exp.caratula);
}

void darNombreExpediente(Expediente exp, String &pNombre)
{
    strcrear(pNombre);
    strcop(pNombre, exp.nombre);
}


void darApellidoExpediente(Expediente exp, String &pApellido)
{
    strcrear(pApellido);
    strcop(pApellido, exp.apellido);
}

void AgregarExpAArchivo(Expediente exp, FILE * f)
{
    agregarStringAArchivo(exp.caratula, f);
    agregarStringAArchivo(exp.nombre, f);
    agregarStringAArchivo(exp.apellido, f);
    fwrite(&exp.codigo, sizeof(long), 1, f);
    fwrite(&exp.cantidadPaginas, sizeof(int), 1, f);
}

void leerExpDeArchivo(Expediente &exp, FILE * f)
{
    strcrear(exp.caratula);
    strcrear(exp.nombre);
    strcrear(exp.apellido);
    leerStringDeArchivo(exp.caratula, f);
    leerStringDeArchivo(exp.nombre, f);
    leerStringDeArchivo(exp.apellido, f);
    fread(&exp.codigo, sizeof(long), 1, f);
    fread(&exp.cantidadPaginas, sizeof(int), 1, f);
}
