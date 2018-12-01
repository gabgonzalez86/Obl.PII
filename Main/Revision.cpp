#include "Revision.h"

void cargarRevision(Revision &rev, long codigoExp)
{
    rev.codigoExpediente = codigoExp;
    cargarFecha(rev.fchRealizacion);

    printf("Motivo: ");
    strcrear(rev.motivo);
    scan(rev.motivo);

    printf("Ingrese un resultado (1- Satisfacoria, 2-Incompleta, 3- Pendiente ): ");
    int opcion;
    scanf("%d",&opcion);

    while(opcion >3 || opcion <1)
    {
        printf("Opcion incorrecta.\n");
        scanf("%d",&opcion);
    }

    cargarResultado(opcion, rev.resultadoRevision);
}

void mostrarRevision(Revision rev)
{
    printf("\nDatos de la revision:\n");
    mostrarFecha(rev.fchRealizacion);
    printf(" - Motivo: ");
    print(rev.motivo);
    printf(" - Codigo expediente: ");
    printf("%ld", rev.codigoExpediente);
    printf(" - Resultado: ");
    mostrarResultado(rev.resultadoRevision);
}

void cargarResultado(int opcion, resultado &resultadoRevision)
{
    switch(opcion)
    {
    case 1:
        resultadoRevision = Satisfacoria;
        break;

    case 2:
        resultadoRevision = Incompleta;
        break;
    case 3:
        resultadoRevision = Pendiente;
        break;
    }
}

Fecha darFechaRevision(Revision rev)
{
    return rev.fchRealizacion;
}

void darMotivo(Revision rev, String &pMotivo)
{
    strcrear(pMotivo);
    strcop(pMotivo, rev.motivo);
}

long darCodigoExpediente(Revision rev)
{
    return rev.codigoExpediente;
}

resultado darResultadoRevision(Revision rev)
{
    return rev.resultadoRevision;
}

void agregarRevAArchivo(Revision rev, FILE * f)
{
    agregarStringAArchivo(rev.motivo, f);
    agregarFechaAArchivo(rev.fchRealizacion, f);
    fwrite(&rev.codigoExpediente, sizeof(long), 1, f);
    fwrite(&rev.resultadoRevision, sizeof(resultado), 1, f);
}

void leerRevDeArchivo(Revision &rev, FILE * f)
{
    strcrear(rev.motivo);
    leerStringDeArchivo(rev.motivo, f);
    leerFechaDeArchivo(rev.fchRealizacion, f);
    fread(&rev.codigoExpediente, sizeof(long), 1, f);
    fread(&rev.resultadoRevision, sizeof(resultado), 1, f);
}
