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

//Devuelve si la primer fecha es mayor a la segunda
boolean esMayor(Fecha fec1, Fecha fec2);

#endif // FECHA_H_INCLUDED
