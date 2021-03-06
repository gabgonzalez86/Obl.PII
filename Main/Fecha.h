#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "Boolean.h"

typedef struct {int dia;
                int mes;
                int anio;
                }Fecha;

//Carga una fecha
void cargarFecha(Fecha &fec);

//Muestra una fecha
void mostrarFecha(Fecha fec);

//Verifica si la fecha ingresada es valida
boolean validarFecha(Fecha fec);

//Devuelve el dia
int darDia(Fecha fec);

//Devuelve el mes
int darMes(Fecha fec);

//Devuelve el anio
int darAnio(Fecha fec);

//Devuelve la fecha
Fecha darFecha(Fecha fec);

//Devuelve si la primer fecha es menor o igual a la segunda
boolean esMenorIgual(Fecha fec1, Fecha fec2);

//Devuelve si la primer fecha es mayor o igual a la segunda
boolean esMayorIgual(Fecha fec1, Fecha fec2);


//agrega al archivo los datos de la Fecha
void agregarFechaAArchivo(Fecha pFecha, FILE * f);
//PRECONDICION: El archivo debe estar abierto para escritura.

//lee desde el archivo los datos de la Fecha
void leerFechaDeArchivo(Fecha &pFecha, FILE * f);
//PRECONDICION: El archivo debe estar abierto para lectura

#endif // FECHA_H_INCLUDED
