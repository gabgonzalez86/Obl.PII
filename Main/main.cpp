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
          vSalirSubMenuListado = FALSE,
          vSalirSubMenuConsulta = FALSE;

  Expediente vExpediente;
  Revision   vRevision;
  Arbol vArbolExpedientes;
  Lista vListaRevisiones;

  crearArbol(vArbolExpedientes);


  crearLista(vListaRevisiones);

    do
    {
        mostrarMenu(vOpcion);
        switch(vOpcion)
        {
            case 1: int vCodigoexpediente;

                    printf("\nIngrese el codigo del expediente: ");
                    scanf("%ld", &vCodigoexpediente);

                    if(!existeExpediente(vArbolExpedientes, vCodigoexpediente))
                        {
                          cargarExpediente(vExpediente, vCodigoexpediente);
                          GuardarExpediente(vArbolExpedientes, vExpediente);
                        }
                    else
                        printf("No se puede realizar la carga, ya existe un expediente con ese codigo.\n");
            break;

            case 2: printf("\nIngrese el codigo del expediente asociado a la revision: ");
                    scanf("%ld", &vCodigoexpediente);
                    if(existeExpediente(vArbolExpedientes, vCodigoexpediente))
                        {
                            cargarRevision(vRevision, vCodigoexpediente);
                            agregarRevisionFront(vListaRevisiones, vRevision);

                        }
                    else
                        printf("No existe expediente para asociar la revision.\n");
            break;

            case 3:printf("\nFuncion de la opcion 3\n.");
            break;

            case 4: int vOpcionSubMenuListado;
                    do
                    {
                        mostrarSubMenuListados(vOpcionSubMenuListado);
                        vSalirSubMenuListado = FALSE;

                        switch(vOpcionSubMenuListado)
                        {
                            case 1: mostrarArbol(vArbolExpedientes);
                            break;
                            case 2: listarRevisiones(vListaRevisiones);
                            break;
                            case 3: printf("\nExpediente con menor codigo:");
                                    mostrarExpediente(Minimo(vArbolExpedientes));
                                    printf("\nExpediente con mayor codigo:");
                                    mostrarExpediente(Maximo(vArbolExpedientes));
                            break;
                            case 4: printf("\nIngrese el codigo del expediente: ");
                                    scanf("%ld", &vCodigoexpediente);
                                    if(existeExpediente(vArbolExpedientes, vCodigoexpediente))
                                    {
                                        listarRevisionesPorExpediente(vListaRevisiones, vCodigoexpediente);

                                    }
                                    else
                                        printf("No existe expediente para asociar la revision.\n");
                            break;
                            case 5: vSalirSubMenuListado=TRUE;
                            break;
                            default: printf("Opcion invalida.\n");
                        }
                    }while(!vSalirSubMenuListado);
                    break;



            case 5: int vOpcionSubMenuConsultas;
                     do
                    {
                         mostrarSubMenuConsultas(vOpcionSubMenuConsultas);
                         vSalirSubMenuConsulta = FALSE;

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
                            case 5: vSalirSubMenuConsulta=TRUE;
                            break;
                            default: printf("Opcion invalida.\n");
                        }
                    }while(!vSalirSubMenuConsulta);

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
