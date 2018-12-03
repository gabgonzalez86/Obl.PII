#include "ListaRevision.h"

void crearLista(Lista &l)
{
    l = NULL;
}

boolean listaVacia(Lista l)
{
    boolean es = FALSE;
    if(l == NULL)
        es = TRUE;

    return es;
}

Fecha fechaPrimerElementoListado(Lista l)
{
    return darFechaRevision(l -> revisiones);
}//PRECONDICION: La lista no puede estar vacia

void agregarRevisionFront(Lista &l, Revision pRev)
{
    Lista vAux = new nodoLista;
    vAux -> revisiones = pRev;
    vAux -> sig = l;
    l = vAux;
}

void agregarRevisionBack(Lista &l, Revision pRev)
{
    Lista vLista = new nodoLista;
    vLista ->revisiones = pRev;
    vLista -> sig = NULL;
    //se puede usar la funcion vacia
    if(listaVacia(l))
    {
        l = vLista;
    }
    else
    {
        Lista vAux = l;
        while (vAux -> sig != NULL)
        {
            vAux = vAux -> sig;
        }
        vAux -> sig = vLista;
    }
}

void borrarRevision(Lista &l, long pCodigo)
{
    if (!listaVacia(l))
    {
        if (pCodigo == darCodigoExpediente(l->revisiones))
        {
            Lista vAux = l;
            l = l -> sig;
            delete vAux;
            borrarRevision (l, pCodigo);
        }
        else
            borrarRevision (l -> sig, pCodigo);
    }
}
//PRECONDICION: La revision debe existir

void listarRevisiones (Lista l)
{
    while(!listaVacia(l))
    {
        mostrarRevision(l -> revisiones);
        l = l -> sig;
    }
}

void listarRevisionesPorExpediente (Lista l, long pCodigo)
{
    while(!listaVacia(l))
    {
        if( darCodigoExpediente(l -> revisiones) == pCodigo)
        {
            mostrarRevision(l -> revisiones);
        }
        l = l -> sig;
    }
}

int cantidadRevPorExp(Lista l, long pCodigo)
{
    int vCntRevisiones = 0;
    while(!listaVacia(l))
    {
        if(darCodigoExpediente(l->revisiones) == pCodigo)
        {
            vCntRevisiones++;
        }
        l = l -> sig;
    }
    return vCntRevisiones;
}

int cantidadRevisionesPorFecha(Lista l, Fecha pFec1, Fecha pFec2)
{
    int vCntRevisiones = 0;
    while(!listaVacia(l))
    {
        if(esMayorIgual(darFechaRevision(l->revisiones), pFec1) && esMenorIgual(darFechaRevision(l->revisiones), pFec2))
        {
            vCntRevisiones++;
        }
        l = l -> sig;
    }
    return vCntRevisiones;
}

void cantidadRevisionesPorTipo(Lista l, int &pSatisfactorias, int &pIncompletas, int &pPendientes)
{
    while(!listaVacia(l))
    {
        switch(darResultadoRevision(l -> revisiones))
        {
        case Satisfacoria:
            pSatisfactorias++;
            break;
        case Incompleta:
            pIncompletas++;
            break;
        case Pendiente:
            pPendientes++;
            break;
        }
        l = l -> sig;
    }
}

void agregarListaAArchivo(Lista L, String pArchivo)
{
    FILE * f = fopen(pArchivo, "wb");
    while(L != NULL)
    {
        agregarRevAArchivo(L->revisiones, f);
        L = L->sig;
    }
    fclose(f);
}

void leerListaDeArchivo(Lista &L, String pArchivo)
{
    FILE * f = fopen (pArchivo, "rb");
    Revision rev;

    leerRevDeArchivo(rev, f);

    while(!feof(f))
    {
        agregarRevisionBack(L, rev);
        leerRevDeArchivo(rev, f);
    }
    fclose (f);
}
