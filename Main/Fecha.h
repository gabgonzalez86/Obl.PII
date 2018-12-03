#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "Boolean.h"

typedef struct {int dia;
                int mes;
                int anio;
                }Fecha;

//Devuelve el dia
int darDia(Fecha fec);

//Devuelve el mes
int darMes(Fecha fec);

//Devuelve el anio
int darAnio(Fecha fec);

//Devuelve la fecha
Fecha darFecha(Fecha fec);

//Carga una fecha
void cargarFecha(Fecha &pFec);

//Muestra una fecha
void mostrarFecha(Fecha pFec);

//Verifica si la fecha ingresada es valida
boolean validarFecha(Fecha pFec);

//Devuelve si la primer fecha es menor o igual a la segunda
boolean esMenorIgual(Fecha pFec1, Fecha pFec2);

//Devuelve si la primer fecha es mayor o igual a la segunda
boolean esMayorIgual(Fecha pFec1, Fecha pFec2);

//agrega al archivo los datos de la Fecha
void agregarFechaAArchivo(Fecha pFecha, FILE * f);
//PRECONDICION: El archivo debe estar abierto para escritura.

//lee desde el archivo los datos de la Fecha
void leerFechaDeArchivo(Fecha &pFecha, FILE * f);
//PRECONDICION: El archivo debe estar abierto para lectura

#endif // FECHA_H_INCLUDED
