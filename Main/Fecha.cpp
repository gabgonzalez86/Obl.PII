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
    printf("\n%d-%d-%d", pFec.dia, pFec.mes, pFec.anio);
}

//Verifica si la fecha ingresada es valida
boolean validarFecha(Fecha pFec)
{
    boolean vValida = FALSE;

    switch (pFec.mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: if (pFec.dia >= 1 && pFec.dia <= 31)
                    vValida = TRUE;
                else
                    vValida = FALSE;
                break;
        case 4:
        case 6:
        case 9:
        case 11: if (pFec.dia >= 1 && pFec.dia <= 30)
                   vValida = TRUE;
                else
                   vValida = FALSE;
                break;

        case 2: if (pFec.anio % 4 == 0)
                {
                    if (pFec.dia >= 1 && pFec.dia <= 29)
                       vValida = TRUE;
                    else
                       vValida = FALSE;
                }
                else
                {
                    if (pFec.dia >= 1 && pFec.dia <= 28)
                        vValida = TRUE;
                    else
                        vValida = FALSE;
                }
                break;
    }
    return vValida;
}

boolean esMenorIgual(Fecha pFec1, Fecha pFec2)
{
  boolean  vMenorIgual = FALSE;

    if(pFec1.anio == pFec2.anio && pFec1.mes == pFec2.mes && pFec1.dia == pFec2.dia)
       vMenorIgual = TRUE;
    else
        if(pFec1.anio < pFec2.anio)
            vMenorIgual = TRUE;
        else
            if(pFec2.anio < pFec1.anio)
                vMenorIgual = FALSE;
            else
                if(pFec1.mes < pFec2.mes)
                    vMenorIgual = TRUE;
                else
                    if(pFec2.mes < pFec1.mes)
                       vMenorIgual = FALSE;
                     else
                        if(pFec1.dia < pFec2.dia)
                            vMenorIgual = TRUE;
                        else
                            vMenorIgual = FALSE;

    return vMenorIgual;
}

boolean esMayorIgual(Fecha pFec1, Fecha pFec2)
{
  boolean  vMayorIgual = FALSE;

    if(pFec1.anio == pFec2.anio && pFec1.mes == pFec2.mes && pFec1.dia == pFec2.dia)
       vMayorIgual = TRUE;
    else
        if(pFec1.anio > pFec2.anio)
            vMayorIgual = TRUE;
        else
            if(pFec2.anio > pFec1.anio)
                vMayorIgual = FALSE;
            else
                if(pFec1.mes > pFec2.mes)
                    vMayorIgual = TRUE;
                else
                    if(pFec2.mes > pFec1.mes)
                       vMayorIgual = FALSE;
                     else
                        if(pFec1.dia > pFec2.dia)
                            vMayorIgual = TRUE;
                        else
                            vMayorIgual = FALSE;

    return vMayorIgual;
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
