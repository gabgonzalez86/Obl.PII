#include "Fecha.h"

//Carga una fecha
void cargarFecha(Fecha &fec)
{
   scanf("%d", &fec.dia);
   scanf("%d", &fec.mes);
   scanf("%d", &fec.anio);

//agregar while
   while(!validarFecha(fec))
   {
        printf("Fecha ingresada incorrecta, ingresela nuevamente: ");
        cargarFecha(fec);
   }

}

//Muestra una fecha
void mostrarFecha(Fecha fec)
{
    printf("%d-%d-%d", fec.dia, fec.mes, fec.anio);

}

//Verifica si la fecha ingresada es valida
boolean validarFecha(Fecha fec)
{
    boolean valida = FALSE;

    switch (fec.mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: if (fec.dia >= 1 && fec.dia <= 31)
                    valida = TRUE;
                else
                    valida = FALSE;
                break;
        case 4:
        case 6:
        case 9:
        case 11: if (fec.dia >= 1 && fec.dia <= 30)
                   valida = TRUE;
                else
                   valida = FALSE;
                break;

        case 2: if (fec.anio % 4 == 0)
                {
                    if (fec.dia >= 1 && fec.dia <= 29)
                       valida = TRUE;
                    else
                       valida = FALSE;
                }
                else
                {
                    if (fec.dia >= 1 && fec.dia <= 28)
                        valida = TRUE;
                    else
                        valida = FALSE;
                }
                break;

    }
    return valida;
}


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

boolean esMenorIgual(Fecha fec1, Fecha fec2)
{
  boolean  menorIgual = FALSE;

    if(darAnio(fec1) == darAnio(fec2) && darMes(fec1) == darMes(fec2) && darDia(fec1)== darDia(fec2))
       menorIgual = TRUE;
    else
        if(darAnio(fec1) < darAnio(fec2))
            menorIgual = TRUE;
        else
            if(darAnio(fec2) < darAnio(fec1))
                menorIgual = FALSE;
            else
                if(darMes(fec1) < darMes(fec2))
                    menorIgual = TRUE;
                else
                    if(darMes(fec2) < darMes(fec1))
                       menorIgual = FALSE;
                     else
                        if(darDia(fec1) < darDia(fec2))
                            menorIgual = TRUE;
                        else
                            menorIgual = FALSE;

    return menorIgual;

}

boolean esMayorIgual(Fecha fec1, Fecha fec2)
{
  boolean  mayorIgual = FALSE;

    if(darAnio(fec1) == darAnio(fec2) && darMes(fec1) == darMes(fec2) && darDia(fec1)== darDia(fec2))
       mayorIgual = TRUE;
    else
        if(darAnio(fec1)> darAnio(fec2))
            mayorIgual = TRUE;
        else
            if(darAnio(fec2)> darAnio(fec1))
                mayorIgual = FALSE;
            else
                if(darMes(fec1)>darMes(fec2))
                    mayorIgual = TRUE;
                else
                    if(darMes(fec2)>darMes(fec1))
                       mayorIgual = FALSE;
                     else
                        if(darDia(fec1)>darDia(fec2))
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
