#include "Revision.h"

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

void cargarRevision(Revision &pRev, long pCodigoExp, Fecha pFechaRev)
{
    pRev.codigoExpediente = pCodigoExp;
    pRev.fchRealizacion = pFechaRev;

    printf("Motivo: ");
    strcrear(pRev.motivo);
    scan(pRev.motivo);

    printf("Ingrese un resultado (1- Satisfacoria, 2-Incompleta, 3- Pendiente ): ");
    int vOpcion;
    scanf("%d",&vOpcion);

    while(vOpcion >3 || vOpcion <1)
    {
        printf("Opcion incorrecta.\n");
        scanf("%d",&vOpcion);
    }
    cargarResultado(vOpcion, pRev.resultadoRevision);
}

void mostrarRevision(Revision pRev)
{
    mostrarFecha(pRev.fchRealizacion);
    printf(" - ");
    print(pRev.motivo);
    printf(" - ");
    printf("%ld", pRev.codigoExpediente);
    printf(" - ");
    mostrarResultado(pRev.resultadoRevision);
}

void cargarResultado(int pOpcion, resultado &pResultadoRevision)
{
    switch(pOpcion)
    {
    case 1:
        pResultadoRevision = Satisfacoria;
        break;

    case 2:
        pResultadoRevision = Incompleta;
        break;
    case 3:
        pResultadoRevision = Pendiente;
        break;
    }
}

void agregarRevAArchivo(Revision pRev, FILE * f)
{
    agregarStringAArchivo(pRev.motivo, f);
    agregarFechaAArchivo(pRev.fchRealizacion, f);
    fwrite(&pRev.codigoExpediente, sizeof(long), 1, f);
    fwrite(&pRev.resultadoRevision, sizeof(resultado), 1, f);
}

void leerRevDeArchivo(Revision &pRev, FILE * f)
{
    strcrear(pRev.motivo);
    leerStringDeArchivo(pRev.motivo, f);
    leerFechaDeArchivo(pRev.fchRealizacion, f);
    fread(&pRev.codigoExpediente, sizeof(long), 1, f);
    fread(&pRev.resultadoRevision, sizeof(resultado), 1, f);
}
