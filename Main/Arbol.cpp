#include "Arbol.h"

boolean existeExpediente(Arbol a, long codigo)
{
    if(a == NULL)
        return FALSE;
    else
    {
        if(codigo == darCodigo(a->expedientes))
            return TRUE;
        else
        {
            if(codigo < darCodigo(a->expedientes))
                return existeExpediente(a->hizq, codigo);
            else
                return existeExpediente(a->hder, codigo);
        }
    }
}
