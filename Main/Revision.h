#ifndef REVISION_H_INCLUDED
#define REVISION_H_INCLUDED
#include "Fecha.h"
#include "Resultado.h"
//#include "Expediente.h"
#include "string.h"


typedef struct {Fecha fchRealizacion;
                String motivo;
                long codigoExpediente;
                resultado resultadoRevision;
                }Revision;

//Carga una revision
//void cargarRevision(Revision &rev);
//PRECONDICION: se debe validar que exista el codigo de Expediente

void cargarRevision(Revision &rev, long codigoExp, Fecha fechaRev);
//PRECONDICION: se debe validar que exista el código de Expediente

//Muestra la revision
void mostrarRevision(Revision rev);
//PRECONDICION: La revision debe existir

//Carga un resultado
void cargarResultado(int opcion, resultado &resultadoRevision);
//PRECONDICION: La opcion debe estar entre 1 y 3

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

//agrega al archivo los datos de la Revision
void agregarRevAArchivo(Revision rev, FILE * f);
//PRECONDICION: El archivo debe estar abierto para escritura.

//lee desde el archivo los datos de la Revision
void leerRevDeArchivo(Revision &rev, FILE * f);
//PRECONDICION: El archivo debe estar abierto para lectura

#endif // REVISION_H_INCLUDED
