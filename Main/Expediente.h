#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED
#include "String.h"

typedef struct {long codigo;
                String caratula;
                String nombre;
                String apellido;
                int cantidadPaginas ;
               }Expediente;


//Carga el expediente
void cargarExpediente(Expediente &exp, long codigo);
//PRECONDICION: se debe validar que NO exista el código de Expediente

//Muestra los datos del expediente
void mostrarExpediente (Expediente exp);
//PRECONDICION: El expediente debe existir

//Devuelve el codigo del expediente
long darCodigo(Expediente exp);
//PRECONDICION: El expediente debe existir

//Devuelve el nombre del escribano
void darNombreExpediente(Expediente exp, String &pNombre);
//PRECONDICION: El expediente no puede estar vacio

//Devuelve el apellido del escribano
void darApellidoExpediente(Expediente exp, String &pApellido);
//PRECONDICION: El expediente no puede estar vacio

//Devuelve la caratula del expediente
void darCaratula(Expediente exp, String &pCaratula);
//PRECONDICION: El expediente no puede estar vacio

//Devuelve la cantidad de paginas del expediente
int  darCantidadPaginas (Expediente exp);
//PRECONDICION: El expediente debe existir

//agrega al archivo los datos del Expediente
void AgregarExpAArchivo(Expediente exp, FILE * f);
//PRECONDICION: El archivo debe estar abierto para escritura.

#endif // EXPEDIENTE_H_INCLUDED
