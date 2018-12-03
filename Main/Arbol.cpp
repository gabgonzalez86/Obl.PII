#include "Arbol.h"

void crearArbol(Arbol &a)
{
    a = NULL;
}

boolean arbolVacio(Arbol a)
{
    return (boolean) (a == NULL);
}

Expediente DarRaiz(Arbol a)
{
    return a->expedientes;
}

Arbol darHijoIzquierdo(Arbol a)
{
    return a->hizq;
}

Arbol darHijoDerecho(Arbol a)
{
    return a->hder;
}

void GuardarExpediente(Arbol &a, Expediente pExp)
{
    if(arbolVacio(a))
    {
        a = new nodo;
        a->expedientes = pExp;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        if(darCodigo(pExp) < darCodigo(a->expedientes))
            GuardarExpediente(a->hizq, pExp);
        else
            GuardarExpediente(a->hder, pExp);
    }
}

void mostrarArbol(Arbol pArbolExpedientes)
{
    if(!arbolVacio(pArbolExpedientes))
    {
        mostrarArbol(pArbolExpedientes->hizq);
        mostrarExpediente(pArbolExpedientes->expedientes);
        mostrarArbol(pArbolExpedientes->hder);
    }
}

int cantidadExpedientesPorEscribano(Arbol a, String pApellido)
{
    String vApellido;

    if(arbolVacio(a))
        return 0;
    else
    {
        darApellidoExpediente(a->expedientes, vApellido);
        if(streq(pApellido, vApellido))
            return 1 + cantidadExpedientesPorEscribano (a -> hizq, pApellido) + cantidadExpedientesPorEscribano (a -> hder, pApellido);
        else
            return cantidadExpedientesPorEscribano (a -> hizq, pApellido) + cantidadExpedientesPorEscribano (a -> hder, pApellido);
    }
}

Expediente Minimo(Arbol a)
{
     while (a->hizq != NULL)
     {
        a = a->hizq;
     }
     return (a->expedientes);
}

Expediente Maximo(Arbol a)
{
     while (a->hder != NULL)
     {
        a = a->hder;
     }
     return (a->expedientes);
}

void borrarMinimo(Arbol &a)
{
    Arbol vAux;
    if(a->hizq == NULL)
    {
        vAux = a->hder;
        delete a;
        a = vAux;
    }
    else
        borrarMinimo(a->hizq);
}

void borrarExpedientePorCodigo(Arbol &a, long pCodigo)
{
    Arbol vAux;
    if(pCodigo == darCodigo(a->expedientes))
    {
        if(a->hder == NULL)
        {
            vAux = a->hizq;
            delete a;
            a = vAux;
        }
        else
        {
            if(a->hizq == NULL)
            {
                vAux = a->hder;
                delete a;
                a = vAux;
            }
            else
            {
                a->expedientes = Minimo(a->hder);
                borrarMinimo(a->hder);
            }
        }
    }
    else
    {
        if(pCodigo < darCodigo(a->expedientes))
            borrarExpedientePorCodigo(a->hizq, pCodigo);
        else
            borrarExpedientePorCodigo(a->hder, pCodigo);
    }
}

boolean existeExpediente(Arbol a, long pCodigo)
{
    if(arbolVacio(a))
        return FALSE;
    else
    {
        if(pCodigo == darCodigo(a->expedientes))
            return TRUE;
        else
        {
            if(pCodigo < darCodigo(a->expedientes))
                return existeExpediente(a->hizq, pCodigo);
            else
                return existeExpediente(a->hder, pCodigo);
        }
    }
}

void masRevProExp(Arbol pArbolExpedientes, Lista pListaRevisiones, long &pCodigo, int &pCantidad)
{
    int vCantidadAux = 0;
    long vCodigoAux;
     if(!arbolVacio(pArbolExpedientes))
    {
        masRevProExp(pArbolExpedientes->hizq, pListaRevisiones, pCodigo, pCantidad);
        vCodigoAux = darCodigo(pArbolExpedientes->expedientes);
        vCantidadAux = cantidadRevPorExp(pListaRevisiones, vCodigoAux);
        if(vCantidadAux > pCantidad)
        {
            pCantidad = vCantidadAux;
            pCodigo = vCodigoAux;
        }
        masRevProExp(pArbolExpedientes->hder, pListaRevisiones, pCodigo, pCantidad);
    }
}

void agregarArbolAuxArchivo(Arbol a, FILE * f)
{
    if(!arbolVacio(a))
    {
        AgregarExpAArchivo(a->expedientes, f);
        agregarArbolAuxArchivo(a-> hizq, f);
        agregarArbolAuxArchivo(a-> hder, f);
    }
}

void agregarArbolAArchivo(Arbol a, String pArchivo)
{
    FILE * f = fopen(pArchivo, "wb");
    agregarArbolAuxArchivo(a, f);
    fclose (f);
}

void leerArbolDeArchivo(Arbol &a, String pArchivo)
{
    FILE * f = fopen(pArchivo, "rb");
    Expediente vExp;

    leerExpDeArchivo(vExp, f);

    while(!feof(f))
    {
        GuardarExpediente(a, vExp);
        leerExpDeArchivo(vExp, f);
    }
    fclose (f);
}
