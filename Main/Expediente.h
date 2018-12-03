#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED
#include "string.h"

typedef struct {long codigo;
                String caratula;
                String nombre;
                String apellido;
                int cantidadPaginas ;
               }Expediente;

//Devuelve el codigo del expediente
long darCodigo(Expediente pExp);
//PRECONDICION: El expediente debe existir

//Devuelve el nombre del escribano
void darNombreExpediente(Expediente pExp, String &pNombre);
//PRECONDICION: El expediente no puede estar vacio

//Devuelve el apellido del escribano
void darApellidoExpediente(Expediente pExp, String &pApellido);
//PRECONDICION: El expediente no puede estar vacio

//Devuelve la caratula del expediente
void darCaratula(Expediente pExp, String &pCaratula);
//PRECONDICION: El expediente no puede estar vacio

//Devuelve la cantidad de paginas del expediente
int  darCantidadPaginas (Expediente pExp);
//PRECONDICION: El expediente debe existir

//Carga el expediente
void cargarExpediente(Expediente &pExp, long pCodigo);
//PRECONDICION: se debe validar que NO exista el código de Expediente

//Muestra los datos del expediente
void mostrarExpediente (Expediente pExp);
//PRECONDICION: El expediente debe existir

//agrega al archivo los datos del Expediente
void AgregarExpAArchivo(Expediente pExp, FILE * f);
//PRECONDICION: El archivo debe estar abierto para escritura.

//lee desde el archivo los datos del Expediente
void leerExpDeArchivo(Expediente &pExp, FILE * f);
//PRECONDICION: El archivo debe estar abierto para lectura

#endif // EXPEDIENTE_H_INCLUDED
