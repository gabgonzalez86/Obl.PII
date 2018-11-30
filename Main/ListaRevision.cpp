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

void agregarRevision(Lista &l, Revision rev)
{
    Lista aux = new nodoLista;
    aux -> revisiones = rev;
    aux -> sig = l;
    l = aux;
}

void borrarRevision(Lista &l, long codigo)
{
    while(l != NULL)
    {

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
void listarRevisionsPorExpediente (Lista l, long codigo)
{
    boolean encontre = FALSE;
    while(l != NULL && encontre)
    {
        if( darCodigoExpediente(l -> revisiones) == codigo)
        {
            mostrarRevision(l -> revisiones);
            encontre = TRUE;
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
