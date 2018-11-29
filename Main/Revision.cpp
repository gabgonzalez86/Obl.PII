#include "Revision.h"

void cargarRevision(Revision &rev)
{
    printf("\nINGRESE LOS DATOS DE LA REVISION");
    cargarFecha(rev.fchRealizacion);

    printf("\nMotivo: ");
    strcrear(rev.motivo);
    scan(rev.motivo);

    printf("\nCodigo expediente: ");
    //validar que exista codigo expediente
    scanf("%ld", &rev.codigoExpediente);

    printf("\nIngrese un resultado (1- Satisfacoria, 2-Incompleta, 3- Pendiente ): ");
    int opcion;
    scanf("%d",&opcion);

    while(opcion >3 || opcion <1)
    {
        printf("Opcion incorrecta.\n");
        scanf("%d",&opcion);
    }

    cargarResultado(opcion, rev.resultadoRevision);

}
/*
void cargarRevision(Revision &rev, long codigoExp)
{
    rev.codigoExpediente = codigoExp;

    printf("\nINGRESE LOS DATOS DE LA REVISION");
    cargarFecha(rev.fchRealizacion);

    printf("\nMotivo: ");
    strcrear(rev.motivo);
    scan(rev.motivo);

    printf("\nIngrese un resultado (1- Satisfacoria, 2-Incompleta, 3- Pendiente ): ");
    int opcion;
    scanf("%d",&opcion);

    while(opcion >3 || opcion <1)
    {
        printf("Opcion incorrecta.\n");
        scanf("%d",&opcion);
    }

    cargarResultado(opcion, rev.resultadoRevision);
}
*/
void mostrarRevision(Revision rev)
{
    printf("\nDatos de la revision:\n");
    mostrarFecha(rev.fchRealizacion);
    printf("\nMotivo: ");
    print(rev.motivo);
    printf("\nCodigo expediente: ");
    printf("%ld", rev.codigoExpediente);
    printf("\nResultado: ");
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

long darCodigoExpediente(Revision rev)
{
    return rev.codigoExpediente;
}

resultado darResultadoRevision(Revision rev)
{
    return rev.resultadoRevision;
}
