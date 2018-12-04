#include "Expediente.h"

long darCodigo(Expediente pExp)
{
    return pExp.codigo;
}

void darCaratula(Expediente pExp, String &pCaratula)
{
    strcrear(pCaratula);
    strcop(pCaratula, pExp.caratula);
}

void darNombreExpediente(Expediente pExp, String &pNombre)
{
    strcrear(pNombre);
    strcop(pNombre, pExp.nombre);
}

void darApellidoExpediente(Expediente pExp, String &pApellido)
{
    strcrear(pApellido);
    strcop(pApellido, pExp.apellido);
}

int darCantidadPaginas(Expediente pExp)
{
    return pExp.cantidadPaginas;
}

void cargarExpediente(Expediente &pExp, long pCodigo)
{
    pExp.codigo = pCodigo;

    printf("Caratula: ");
    strcrear(pExp.caratula);
    scan(pExp.caratula);

    printf("Nombre del escribana/o: ");
    strcrear(pExp.nombre);
    scan(pExp.nombre);

    printf("Apellido del escribana/o: ");
    strcrear(pExp.apellido);
    scan(pExp.apellido);

    printf("Cantidad de paginas: ");
    scanf("%d", &pExp.cantidadPaginas);
}

void mostrarExpediente (Expediente pExp)
{
    printf("\n%ld", pExp.codigo);
    printf(" - ");
    print(pExp.caratula);
    printf(" - ");
    print(pExp.nombre);
    printf(" ");
    print(pExp.apellido);
    printf(" - ");
    printf("%d\n", pExp.cantidadPaginas);
}

void AgregarExpAArchivo(Expediente pExp, FILE * f)
{
    agregarStringAArchivo(pExp.caratula, f);
    agregarStringAArchivo(pExp.nombre, f);
    agregarStringAArchivo(pExp.apellido, f);
    fwrite(&pExp.codigo, sizeof(long), 1, f);
    fwrite(&pExp.cantidadPaginas, sizeof(int), 1, f);
}

void leerExpDeArchivo(Expediente &pExp, FILE * f)
{
    strcrear(pExp.caratula);
    leerStringDeArchivo(pExp.caratula, f);
    strcrear(pExp.nombre);
    leerStringDeArchivo(pExp.nombre, f);
    strcrear(pExp.apellido);
    leerStringDeArchivo(pExp.apellido, f);
    fread(&pExp.codigo, sizeof(long), 1, f);
    fread(&pExp.cantidadPaginas, sizeof(int), 1, f);
}
