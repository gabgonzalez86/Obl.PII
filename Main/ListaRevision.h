#ifndef LISTAREVISION_H_INCLUDED
#define LISTAREVISION_H_INCLUDED
#include "Revision.h"
#include "Expediente.h"

typedef struct nodoL{Revision revisiones;
                     nodoL * sig;
                    }nodoLista;

typedef nodoLista * Lista;

//Crea la lista
void crearLista(Lista &l);

//Verifica si la lista esta vacia
boolean listaVacia(Lista l);

//Devuelve el primer valor de la lista
Revision primerElementoListado(Lista l);
//PRECONDICION: La lista no puede estar vacia

//Agrega una revision al Principio listado
void agregarRevisionFront(Lista &l, Revision rev);

//Agrega una revision al Final listado
void agregarRevisionBack(Lista &l, Revision rev);

//Borra una revision en el listado
void borrarRevision(Lista &l, long codigo);
//PRECONDICION: La revision debe existir

//Muesta todas las revisiones realizadas
void listarRevisiones (Lista l);

//Muestra las revisiones para el expediente
void listarRevisionesPorExpediente (Lista l, long codigo);

int cantidadRevPorExp(Lista l, long pCodigo);


void masRevPorExp(Lista pListaRevisiones, long &pCodigo, int &pCantidad);

//Devuelvela cantidad de revisiones por fecha
int cantidadRevisionesPorFecha(Lista l, Fecha fec1, Fecha fec2);

void cantidadRevisionesPorTipo(Lista l, int &pSatisfactorias, int &pIncompletas, int &pPendientes);

int mayorCantidadRevisiones(Lista vListaRevisiones);

// Abre el archivo para escritura y agrega al archivo los datos de la lista
void agregarListaAArchivo(Lista L, String pArchivo);

//Abre el archivo para lectura y agrega en la lista los datos de las revisiones,
//llamando al procedimiento agregarRevisionBack
void leerListaDeArchivo(Lista &L, String pArchivo);
//PRECONDICION: validar que exista el archivo

#endif // LISTAREVISION_H_INCLUDED
