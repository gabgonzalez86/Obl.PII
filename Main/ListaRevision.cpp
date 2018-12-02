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

Revision primerElementoListado(Lista l)
{
    return l -> revisiones;
}//PRECONDICION: La lista no puede estar vacia

void agregarRevisionFront(Lista &l, Revision rev)
{
    Lista aux = new nodoLista;
    aux -> revisiones = rev;
    aux -> sig = l;
    l = aux;
}

void agregarRevisionBack(Lista &l, Revision rev)
{
    Lista vLista = new nodoLista;
    vLista ->revisiones = rev;
    vLista -> sig = NULL;
    //se puede usar la funcion vacia
    if(l == NULL)
    {
        l = vLista;
    }
    else
    {
        Lista aux = l;
        while (aux -> sig != NULL)
        {
            aux = aux -> sig;
        }
        aux -> sig = vLista;
    }
}

void borrarRevision(Lista &l, long codigo)
{
    while(l != NULL)
    {
        if(codigo == darCodigoExpediente(l -> revisiones))
        {
            Lista aux = l;
            l = l->sig;
            delete aux;
        }
    }
}
//PRECONDICION: La revision debe existir

void listarRevisiones (Lista l)
{
    while(l != NULL)
    {
        mostrarRevision(l -> revisiones);
        l = l -> sig;
    }
}
//asumo que ingresa un nro expediente valido? agregar sele
void listarRevisionesPorExpediente (Lista l, long codigo)
{
    while(l != NULL )
    {
        if( darCodigoExpediente(l -> revisiones) == codigo)
        {
            mostrarRevision(l -> revisiones);
        }
        l = l -> sig;
    }
}

int cantidadRevisionesPorFecha(Lista l, Fecha fec1, Fecha fec2)
{
    int cntRevisiones = 0;
    while(l != NULL)
    {
        if(esMayor(l->revisiones.fchRealizacion, fec1) && !esMayor(l->revisiones.fchRealizacion, fec2))
        {
            cntRevisiones++;
        }
        l = l -> sig;
    }
    return cntRevisiones;
}

void cantidadRevisionesPorTipo(Lista l, int &pSatisfactorias, int &pIncompletas, int &pPendientes)
{
    while(l != NULL)
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
