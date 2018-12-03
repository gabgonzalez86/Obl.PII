#include "Fecha.h"

//Devuelve el dia
int darDia(Fecha fec)
{
    return fec.dia;
}

//Devuelve el mes
int darMes(Fecha fec)
{
    return fec.mes;
}

//Devuelve el anio
int darAnio(Fecha fec)
{
    return fec.anio;
}

//Devuelve la fecha
Fecha darFecha(Fecha fec)
{
    return fec;
}

//Carga una fecha
void cargarFecha(Fecha &pFec)
{
   scanf("%d", &pFec.dia);
   scanf("%d", &pFec.mes);
   scanf("%d", &pFec.anio);

   while(!validarFecha(pFec))
   {
        printf("Fecha ingresada incorrecta, ingresela nuevamente: ");
        cargarFecha(pFec);
   }
}

//Muestra una fecha
void mostrarFecha(Fecha pFec)
{
    printf("%d-%d-%d", pFec.dia, pFec.mes, pFec.anio);
}

//Verifica si la fecha ingresada es valida
boolean validarFecha(Fecha pFec)
{
    boolean valida = FALSE;

    switch (pFec.mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: if (pFec.dia >= 1 && pFec.dia <= 31)
                    valida = TRUE;
                else
                    valida = FALSE;
                break;
        case 4:
        case 6:
        case 9:
        case 11: if (pFec.dia >= 1 && pFec.dia <= 30)
                   valida = TRUE;
                else
                   valida = FALSE;
                break;

        case 2: if (pFec.anio % 4 == 0)
                {
                    if (pFec.dia >= 1 && pFec.dia <= 29)
                       valida = TRUE;
                    else
                       valida = FALSE;
                }
                else
                {
                    if (pFec.dia >= 1 && pFec.dia <= 28)
                        valida = TRUE;
                    else
                        valida = FALSE;
                }
                break;

    }
    return valida;
}

boolean esMenorIgual(Fecha pFec1, Fecha pFec2)
{
  boolean  menorIgual = FALSE;

    if(darAnio(pFec1) == darAnio(pFec2) && darMes(pFec1) == darMes(pFec2) && darDia(pFec1)== darDia(pFec2))
       menorIgual = TRUE;
    else
        if(darAnio(pFec1) < darAnio(pFec2))
            menorIgual = TRUE;
        else
            if(darAnio(pFec2) < darAnio(pFec1))
                menorIgual = FALSE;
            else
                if(darMes(pFec1) < darMes(pFec2))
                    menorIgual = TRUE;
                else
                    if(darMes(pFec2) < darMes(pFec1))
                       menorIgual = FALSE;
                     else
                        if(darDia(pFec1) < darDia(pFec2))
                            menorIgual = TRUE;
                        else
                            menorIgual = FALSE;

    return menorIgual;
}

boolean esMayorIgual(Fecha pFec1, Fecha pFec2)
{
  boolean  mayorIgual = FALSE;

    if(darAnio(pFec1) == darAnio(pFec2) && darMes(pFec1) == darMes(pFec2) && darDia(pFec1)== darDia(pFec2))
       mayorIgual = TRUE;
    else
        if(darAnio(pFec1)> darAnio(pFec2))
            mayorIgual = TRUE;
        else
            if(darAnio(pFec2)> darAnio(pFec1))
                mayorIgual = FALSE;
            else
                if(darMes(pFec1)>darMes(pFec2))
                    mayorIgual = TRUE;
                else
                    if(darMes(pFec2)>darMes(pFec1))
                       mayorIgual = FALSE;
                     else
                        if(darDia(pFec1)>darDia(pFec2))
                            mayorIgual = TRUE;
                        else
                            mayorIgual = FALSE;

    return mayorIgual;
}

void agregarFechaAArchivo(Fecha pFecha, FILE * f)
{
    fwrite(&pFecha.dia, sizeof(int), 1, f);
    fwrite(&pFecha.mes, sizeof(int), 1, f);
    fwrite(&pFecha.anio, sizeof(int), 1, f);
}

void leerFechaDeArchivo(Fecha &pFecha, FILE * f)
{
    fread(&pFecha.dia, sizeof(int), 1, f);
    fread(&pFecha.mes, sizeof(int), 1, f);
    fread(&pFecha.anio, sizeof(int), 1, f);
}
