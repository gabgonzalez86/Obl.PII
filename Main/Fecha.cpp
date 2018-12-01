#include "Fecha.h"

//Carga una fecha
void cargarFecha(Fecha &fec)
{
   printf("Ingrese la fecha de revision en el siguiente formato dd mm aaaa: ");
   scanf("%d", &fec.dia);
   scanf("%d", &fec.mes);
   scanf("%d", &fec.anio);

//agregar while
   if(!validarFecha(fec))
   {
        printf("\nFecha ingresada incorrecta.");
        cargarFecha(fec);
   }

}

//Muestra una fecha
void mostrarFecha(Fecha fec)
{
    printf("Fecha: %d %d %d", fec.dia, fec.mes, fec.anio);

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

boolean esMayor(Fecha fec1, Fecha fec2)
{
  boolean  mayor = FALSE;

    if(darAnio(fec1)> darAnio(fec2))
        mayor = TRUE;
    else
        if(darAnio(fec2)> darAnio(fec1))
            mayor = FALSE;
        else
            if(darMes(fec1)>darMes(fec2))
                mayor = TRUE;
            else
                if(darMes(fec2)>darMes(fec1))
                   mayor = FALSE;
                 else
                    if(darDia(fec1)>darDia(fec2))
                        mayor = TRUE;
                    else
                        mayor = FALSE;

    return mayor;

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
