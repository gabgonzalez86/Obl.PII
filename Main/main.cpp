#include <iostream>
#include <stdio.h>
#include "Menu.h"
#include "Arbol.h"
#include "Revision.h"
#include "Archivo.h"



int main()
{

  int vOpcion;
  boolean vSalir = FALSE,
          vSalirSubMenu = FALSE;

    do
    {
        mostrarMenu(vOpcion);
        switch(vOpcion)
        {
            case 1:printf("\nFuncion de la opcion 1\n.");
            break;

            case 2:printf("\nFuncion de la opcion 2\n.");
            break;

            case 3:printf("\nFuncion de la opcion 3\n.");
            break;

            case 4: int vOpcionSubMenuListado;
                    do
                    {
                        mostrarSubMenuListados(vOpcionSubMenuListado);
                        switch(vOpcionSubMenuListado)
                        {
                            case 1: printf("\nSubMenu Listado 1.\n");
                            break;
                            case 2: printf("\nSubMenu Listado 2.\n");
                            break;
                            case 3: printf("\nSubMenu Listado 3.\n");
                            break;
                            case 4: printf("\nSubMenu Listado 4.\n");
                            break;
                            case 5: vSalirSubMenu=TRUE;
                            break;
                            default: printf("Opcion invalida.\n");
                        }
                    }while(!vSalirSubMenu);
                    break;



            case 5: int vOpcionSubMenuConsultas;
                     do
                    {
                         mostrarSubMenuConsultas(vOpcionSubMenuConsultas);
                        switch(vOpcionSubMenuConsultas)
                        {
                            case 1: printf("\nSubMenu Consulta 1.\n");
                            break;
                            case 2: printf("\nSubMenu Consulta 2.\n");
                            break;
                            case 3: printf("\nSubMenu Consulta 3.\n");
                            break;
                            case 4: printf("\nSubMenu Consulta 4.\n");
                            break;
                            case 5: vSalirSubMenu=TRUE;
                            break;
                            default: printf("Opcion invalida.\n");
                        }
                    }while(!vSalirSubMenu);
                    break;
            break;

            case 6: vSalir = TRUE;
                    break;

            default: printf("Opcion invalida.\n\n");
        }

    }
    while(!vSalir);



/*   Aplicacion para probar modulo fecha
    Fecha fec1,
          fec2;

    cargarFecha(fec1);
    mostrarFecha(fec1);
    cargarFecha(fec2);

    if(esMayor(fec1, fec2))
        print("\nLa fecha 1 es mayor");
    else
        printf("\nLa fecha 2 es mayor.");

*/
//Prueba expediente
 /*Expediente vExp;
 cargarExpediente(vExp);
 mostrarExpediente(vExp);*/
 //

 //Prueba expediente
/*Revision vRev;
cargarRevision(vRev);
mostrarRevision(vRev);*/

//Prueba de listado revision


 //Prueba expediente HEBERT
/*long codigo = 12345;
Revision vRev;
cargarRevision(vRev, codigo);
mostrarRevision(vRev);*/
}
