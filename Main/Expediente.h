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
void cargarExpediente(Expediente &exp);
//PRECONDICION: se debe validar que NO exista el código de Expediente

//Muestra los datos del expediente
void mostrarExpediente (Expediente exp);
//PRECONDICION: El expediente debe existir

//Devuelve el codigo del expediente
long darCodigo(Expediente exp);
//PRECONDICION: El expediente debe existir

//Muestra el nombre del escribano
void darNombreExpediente(Expediente exp);
//PRECONDICION: El expediente no puede estar vacio

//Muestra el apellido del escribano
void darApellidoExpediente(Expediente exp);
//PRECONDICION: El expediente no puede estar vacio

//Muestra la caratula del expediente
void darCaratula(Expediente exp);
//PRECONDICION: El expediente no puede estar vacio

//Devuelve la cantidad de paginas del expediente
int  darCantidadPaginas (Expediente exp);
//PRECONDICION: El expediente debe existir


#endif // EXPEDIENTE_H_INCLUDED
