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
    FILE * fd;

    crearArbol(vArbolExpedientes);

    crearLista(vListaRevisiones);

    if(existeArchivoExpediente("Expedientes.dat"))
        leerArbolDeArchivo(vArbolExpedientes, "Expedientes.dat");
    else
        fd = fopen("Expedientes.dat", "wb");


    if(existeRevision("Revisiones.dat"))
        leerListaDeArchivo(vListaRevisiones, "Revisiones.dat");
    else
        fd = fopen("Revisiones.dat", "wb");


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
                if(esMayorIgual(vFchRevision, fechaPrimerElementoListado(vListaRevisiones)))
                {
                    cargarRevision(vRevision, vCodigoexpediente, vFchRevision);
                    agregarRevisionFront(vListaRevisiones, vRevision);
                }
                else
                    printf("\nLa fecha ingresada no es mayor a la fecha del ultimo registro.");
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
                     if(!arbolVacio(vArbolExpedientes))
                        mostrarArbol(vArbolExpedientes);
                    else
                        printf("\nNo hay Expedientes ingresados\n");
                    break;
                case 2:
                     if(!listaVacia(vListaRevisiones))
                        listarRevisiones(vListaRevisiones);
                    else
                        printf("\nNo hay Revisiones ingresadas\n");
                    break;
                case 3:
                    if(!arbolVacio(vArbolExpedientes))
                    {
                        printf("\nExpediente con menor codigo:");
                        mostrarExpediente(Minimo(vArbolExpedientes));
                        printf("\nExpediente con mayor codigo:");
                        mostrarExpediente(Maximo(vArbolExpedientes));
                    }
                    else
                        printf("\nNo hay Expedientes ingresados\n");
                    break;
                case 4:
                    printf("\nIngrese el codigo del expediente: ");
                    scanf("%ld", &vCodigoexpediente);
                    if(existeExpediente(vArbolExpedientes, vCodigoexpediente))
                    {
                        listarRevisionesPorExpediente(vListaRevisiones, vCodigoexpediente);

                    }
                    else
                        printf("\No existe Expediente con el codigo ingresado.\n");
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
                    if(!arbolVacio(vArbolExpedientes))
                    {
                        String vApellido;
                        printf("\nIngrese un apellido: ");
                        scan(vApellido);
                        int cntExpedientesPorApellido = cantidadExpedientesPorEscribano(vArbolExpedientes,vApellido);
                        printf("\nCantidad de expedientes : %d \n",cntExpedientesPorApellido);
                    }
                    else
                        printf("\nNo hay Expedientes ingresados\n");
                }
                break;
                case 2:
                   {
                        if(!arbolVacio(vArbolExpedientes))
                        {
                            long vCodigo = -1;
                            int vCantidad = -1;
                            masRevProExp(vArbolExpedientes, vListaRevisiones, vCodigo, vCantidad);
                            printf("\nEl Expediente con mas revisiones es el %ld y tiene una cantidad de %d Revisiones. \n ", vCodigo, vCantidad);
                        }
                    else
                        printf("\nNo hay Expedientes ingresados\n");
                    }
                break;
                case 3:
                    Fecha vFechaDesde,
                          vFechaHasta;


                    printf("\nIngrese la fecha desde (dd mm aaaa): ");
                    cargarFecha(vFechaDesde);

                    printf("\nIngrese la fecha hasta (dd mm aaaa): ");
                    cargarFecha(vFechaHasta);
                    if(esMayorIgual(vFechaHasta, vFechaDesde))
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
            agregarListaAArchivo(vListaRevisiones,"Revisiones.dat");
            agregarArbolAArchivo(vArbolExpedientes,"Expedientes.dat");
            break;

        default:
            printf("Opcion invalida.\n\n");
        }

    }
    while(!vSalir);

}
