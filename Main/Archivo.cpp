#include "Archivo.h"

void crearArchivo(String pNombAch, FILE * fd)
{
    fd = fopen(pNombAch, "wb");
}

boolean existeArchivo(String pNomArch)
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


