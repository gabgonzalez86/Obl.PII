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

void GuardarExpediente(Arbol &a, Expediente exp)
{
    if(a == NULL)
    {
        a = new nodo;
        a->expedientes = exp;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        if(darCodigo(exp) < darCodigo(a->expedientes))
            GuardarExpediente(a->hizq, exp);
        else
            GuardarExpediente(a->hder, exp);
    }
}

void mostrarArbol(Arbol pArbolExpedientes)
{
    if(pArbolExpedientes!=NULL)
    {
        mostrarArbol(pArbolExpedientes->hizq);
        mostrarExpediente(pArbolExpedientes->expedientes);
        mostrarArbol(pArbolExpedientes->hder);
    }

}



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

int cantidadExpedientesPorEscribano(Arbol a, String pApellido)
{
    String vApellido;

    if(a == NULL)
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
    Arbol aux;
    if(a->hizq == NULL)
    {
        aux = a->hder;
        delete a;
        a = aux;

    }
    else
        borrarMinimo(a->hizq);
}

void borrarExpediente(Arbol &a, Expediente exp)
{
    Arbol aux;
    if(darCodigo(exp) == darCodigo(a->expedientes))
    {
        if(a->hder == NULL)
        {
            aux = a->hizq;
            delete a;
            a = aux;

        }
        else
        {
            if(a->hizq == NULL)
            {
                aux = a->hder;
                delete a;
                a = aux;


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
        if(darCodigo(exp) < darCodigo(a->expedientes))
            borrarExpediente(a->hizq, exp);
        else
            borrarExpediente(a->hder, exp);
    }
}

void borrarExpedientePorCodigo(Arbol &a, long pCodigo)
{
    Arbol aux;
    if(pCodigo == darCodigo(a->expedientes))
    {
        if(a->hder == NULL)
        {
            aux = a->hizq;
            delete a;
            a = aux;
        }
        else
        {
            if(a->hizq == NULL)
            {
                aux = a->hder;
                delete a;
                a = aux;

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

void masRevProExp(Arbol pArbolExpedientes, Lista pListaRevisiones, long &pCodigo, int &pCantidad)
{
    int vCantidadAux = 0;
    long vCodigoAux;
     if(pArbolExpedientes!=NULL)
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
    if(a != NULL)
    {
        fwrite (&(a->expedientes), sizeof (Expediente), 1, f);
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
        fread(&vExp, sizeof (Expediente), 1, f);
    }
    fclose (f);
}
