#include "Archivo.h"

boolean existeArchivoExpediente(String pNomArch)
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

