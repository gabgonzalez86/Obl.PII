#include "Archivo.h"

boolean existeExpediente(String pNomArch)
{
    boolean vResultado = FALSE;

    FILE * f = fopen(pNomArch, "rb");

    if(f==NULL)
        vResultado =  FALSE;
    else
       {
         vResultado =  TRUE;
         fclose(f);
       }

    return vResultado;
}



boolean expedienteVacio (String pNomArch)
//El archivo debe existir
{
    boolean vResultado = FALSE;
    FILE * f = fopen(pNomArch, "rb");
    Expediente vExpediente;

    fread(&vExpediente, sizeof(Expediente), 1, f);
    if(feof(f))
       vResultado = TRUE;

    fclose(f);

    return vResultado;
}

boolean expedientePertenece (String pNomArch, Expediente pExpediente)
{
    boolean vEncontrado = FALSE;
    Expediente vAuxExpediente;

    FILE * f = fopen (pNomArch, "rb");
    fread(&vAuxExpediente, sizeof(Expediente), 1, f);

    while(!feof(f) && !vEncontrado)
    {
        if(vAuxExpediente.codigo==pExpediente.codigo)
            vEncontrado = TRUE;
        else
        {
            fread(&vAuxExpediente, sizeof(Expediente), 1, f);
        }
    }
    fclose(f);
    return vEncontrado;
}



void agregarRevision(String pNomArch, Revision pRevision)
{
    FILE * f = fopen(pNomArch, "ab");
    fwrite(&pRevision, sizeof(Revision), 1, f);
    fclose(f);

}

boolean existeRevision(String pNomArch)
{
    boolean vResultado = FALSE;

    FILE * f = fopen(pNomArch, "rb");

    if(f==NULL)
        vResultado =  FALSE;
    else
       {
         vResultado =  TRUE;
         fclose(f);
       }

    return vResultado;

}

boolean revisionVacio (String pNomArch)
{
    boolean vResultado = FALSE;
    FILE * f = fopen(pNomArch, "rb");
    Revision vRevision;

    fread(&vRevision, sizeof(Revision), 1, f);
    if(feof(f))
       vResultado = TRUE;

    fclose(f);

    return vResultado;

}

boolean revisionPertenece (String pNomArch, Revision pRevision)
{
    boolean vEncontrado = FALSE;
    Revision vAuxRevision;

    FILE * f = fopen (pNomArch, "rb");
    fread(&vAuxRevision, sizeof(Revision), 1, f);

    while(!feof(f) && !vEncontrado)
    {
        if(vAuxRevision.codigoExpediente==pRevision.codigoExpediente)
            vEncontrado = TRUE;
        else
        {
            fread(&vAuxRevision, sizeof(Revision), 1, f);
        }
    }
    fclose(f);
    return vEncontrado;
}
