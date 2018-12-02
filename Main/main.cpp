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

    long vCodigoexpediente;
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
            //Proceso de alta en el sistema de un nuevo expediente
        case 1:

            printf("\nIngrese el codigo del expediente: ");
            scanf("%ld", &vCodigoexpediente);

            //Controlo que no exista en el sistema un expediente con el mismo numero
            if(!existeExpediente(vArbolExpedientes, vCodigoexpediente))
            {
                cargarExpediente(vExpediente, vCodigoexpediente);
                GuardarExpediente(vArbolExpedientes, vExpediente);
            }
            else
                printf("No se puede realizar la carga, ya existe un expediente con ese codigo.\n");
            break;

            //Proceso de alta en el sistema de una nueva revision
        case 2:

            printf("\nIngrese el codigo del expediente asociado a la revision: ");
            scanf("%ld", &vCodigoexpediente);
            //Controlo que exista un expediente que tenga el codigo ingresado
            if(existeExpediente(vArbolExpedientes, vCodigoexpediente))
            {
                Fecha vFchRevision;
                printf("Ingrese la fecha de revision en el siguiente formato dd mm aaaa: ");
                cargarFecha(vFchRevision);

                cargarRevision(vRevision, vCodigoexpediente, vFchRevision);
                agregarRevisionFront(vListaRevisiones, vRevision);
            }
            else
                printf("\n---No existe expediente para asociar la revision.---\n");
            break;

        case 3:
            printf("\nIngrese el codigo del expediente a eliminar: ");
            scanf("%ld", &vCodigoexpediente);

            if(existeExpediente(vArbolExpedientes,vCodigoexpediente))
            {

                borrarExpedientePorCodigo(vArbolExpedientes,vCodigoexpediente);
                borrarRevision(vListaRevisiones, vCodigoexpediente);
                printf("\n---Se eliminaron los registros.---\n");
            }
            else
                printf("\n---No existe expediente con ese codigo.---\n");

            break;

        case 4:
            int vOpcionSubMenuListado;
            do
            {
                mostrarSubMenuListados(vOpcionSubMenuListado);
                vSalirSubMenuListado = FALSE;

                switch(vOpcionSubMenuListado)
                {
                case 1:
                    mostrarArbol(vArbolExpedientes);
                    break;
                case 2:
                    listarRevisiones(vListaRevisiones);
                    break;
                case 3:
                    printf("\nExpediente con menor codigo:");
                    mostrarExpediente(Minimo(vArbolExpedientes));
                    printf("\nExpediente con mayor codigo:");
                    mostrarExpediente(Maximo(vArbolExpedientes));
                    break;
                case 4:
                    printf("\nIngrese el codigo del expediente: ");
                    scanf("%ld", &vCodigoexpediente);
                    if(existeExpediente(vArbolExpedientes, vCodigoexpediente))
                    {
                        listarRevisionesPorExpediente(vListaRevisiones, vCodigoexpediente);

                    }
                    else
                        printf("No existe expediente para asociar la revision.\n");
                    break;
                case 5:
                    vSalirSubMenuListado=TRUE;
                    break;
                default:
                    printf("Opcion invalida.\n");
                }
            }
            while(!vSalirSubMenuListado);
            break;



        case 5:
            int vOpcionSubMenuConsultas;
            do
            {
                mostrarSubMenuConsultas(vOpcionSubMenuConsultas);
                vSalirSubMenuConsulta = FALSE;

                switch(vOpcionSubMenuConsultas)
                {
                case 1:
                {
                    String vApellido;
                    printf("\nIngrese un apellido: ");
                    scan(vApellido);
                    int cntExpedientesPorApellido = cantidadExpedientesPorEscribano(vArbolExpedientes,vApellido);
                    printf("\nCantidad de expedientes : %d \n",cntExpedientesPorApellido);
                }

                break;
                case 2:
                    printf("\nSubMenu Consulta 2.\n");
                    break;
                case 3:
                    Fecha vFechaDesde,
                          vFechaHasta;


                    printf("\nIngrese la fecha desde (dd mm aaaa): ");
                    cargarFecha(vFechaDesde);

                    printf("\nIngrese la fecha hasta (dd mm aaaa): ");
                    cargarFecha(vFechaHasta);
                    if(esMayor(vFechaHasta, vFechaDesde))
                    {
                        printf("Se realizaron %d revisiones durante ese periodo.\n", cantidadRevisionesPorFecha(vListaRevisiones, vFechaDesde, vFechaHasta));
                    }
                    else
                       printf("\nLa fecha hasta ingresada debe ser mayor a la fecha desde.\n") ;
                break;
                case 4:
                {
                        int vCntSatisfactorias = 0,
                        vCntIncompletas    = 0,
                        vCntPendientes     = 0;

                        cantidadRevisionesPorTipo(vListaRevisiones, vCntSatisfactorias, vCntIncompletas, vCntPendientes);
                        printf("\nTotal de revisiones satisfactorias: %d", vCntSatisfactorias);
                        printf("\nTotal de revisiones incompletas: %d", vCntIncompletas);
                        printf("\nTotal de revisiones pendientes: %d\n", vCntPendientes);
                  }
                break;
                case 5:
                    vSalirSubMenuConsulta=TRUE;
                    break;
                default:
                    printf("Opcion invalida.\n");
                }
            }
            while(!vSalirSubMenuConsulta);

            break;

        case 6:
            vSalir = TRUE;
            break;

        default:
            printf("Opcion invalida.\n\n");
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
