#include "Expediente.h"

void cargarExpediente(Expediente &exp, long codigo)
{
    exp.codigo = codigo;

    printf("Caratula: ");
    strcrear(exp.caratula);
    scan(exp.caratula);

    printf("Nombre del escribana/o: ");
    strcrear(exp.nombre);
    scan(exp.nombre);

    printf("Apellido del escribana/o: ");
    strcrear(exp.apellido);
    scan(exp.apellido);

    printf("Cantidad de paginas: ");
    scanf("%d", &exp.cantidadPaginas);
}

void mostrarExpediente (Expediente exp)
{
    printf("\n%ld", exp.codigo);
    printf(" - ");
    print(exp.caratula);
    printf(" - ");
    print(exp.nombre);
    printf(" ");
    print(exp.apellido);
    printf(" - ");
    printf("%d\n", exp.cantidadPaginas);
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
    leerStringDeArchivo(exp.caratula, f);
    strcrear(exp.nombre);
    leerStringDeArchivo(exp.nombre, f);
    strcrear(exp.apellido);
    leerStringDeArchivo(exp.apellido, f);
    fread(&exp.codigo, sizeof(long), 1, f);
    fread(&exp.cantidadPaginas, sizeof(int), 1, f);
}
