#ifndef REVISION_H_INCLUDED
#define REVISION_H_INCLUDED
#include "Fecha.h"
#include "Resultado.h"
#include "string.h"

typedef struct {Fecha fchRealizacion;
                String motivo;
                long codigoExpediente;
                resultado resultadoRevision;
                }Revision;

//Devuelve la fecha de la revision
Fecha darFechaRevision(Revision rev);
//PRECONDICION: La revision debe existir

//Devuelve el motivo de la revision
void darMotivo(Revision rev, String &pMotivo);
//PRECONDICION: La revision debe existir

//Se obtiene el codigo del expediente asociado a la revision
long darCodigoExpediente(Revision rev);
//PRECONDICION: La revision debe existir

//Devuelve el resultado de la revision
resultado darResultadoRevision(Revision rev);
//PRECONDICION: La revision debe existir

//Carga una revision
void cargarRevision(Revision &pRev, long pCodigoExp, Fecha pFechaRev);
//PRECONDICION: se debe validar que exista el código de Expediente

//Muestra la revision
void mostrarRevision(Revision pRev);
//PRECONDICION: La revision debe existir

//Carga un resultado
void cargarResultado(int pOpcion, resultado &pResultadoRevision);
//PRECONDICION: La opcion debe estar entre 1 y 3

//agrega al archivo los datos de la Revision
void agregarRevAArchivo(Revision pRev, FILE * f);
//PRECONDICION: El archivo debe estar abierto para escritura.

//lee desde el archivo los datos de la Revision
void leerRevDeArchivo(Revision &pRev, FILE * f);
//PRECONDICION: El archivo debe estar abierto para lectura

#endif // REVISION_H_INCLUDED
