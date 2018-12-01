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

//Agrega una revision al listado
void agregarRevision(Lista &l, Revision rev);

//Borra una revision en el listado
void borrarRevision(Lista &l, long codigo);
//PRECONDICION: La revision debe existir

//Muesta todas las revisiones realizadas
void listarRevisiones (Lista l);

//Muestra las revisiones para el expediente
void listarRevisionsPorExpediente (Lista l, long codigo);

//Devuelvela cantidad de revisiones por fecha
int cantidadRevisionesPorFecha(Lista l, Fecha fec1, Fecha fec2);

void cantidadRevisionesPorTipo(Lista l, int &pSatisfactorias, int &pIncompletas, int &pPendientes);

// Abre el archivo para escritura y agrega al archivo los datos de la lista
void agregarListaAArchivo(Lista L, String pArchivo);

#endif // LISTAREVISION_H_INCLUDED
