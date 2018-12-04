#include <iostream>
#include <stdio.h>
#include "Menu.h"
#include "Arbol.h"
#include "Archivo.h"


int main()
{
    //Declaraacion de variables
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

    //Lectura de datos desde archivo
    if(existeArchivo("Expedientes.dat"))
        leerArbolDeArchivo(vArbolExpedientes, "Expedientes.dat");

    if(existeArchivo("Revisiones.dat"))
        leerListaDeArchivo(vListaRevisiones, "Revisiones.dat");

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
                printf("\n-No se puedo efectuar la carga, ya existe un expediente con el mismo codigo.-\n");
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
                //Controlo que la fecha sea mayor o igual a la ingresada en la ultima revision
                if(listaVacia(vListaRevisiones))
                {
                    cargarRevision(vRevision, vCodigoexpediente, vFchRevision);
                    agregarRevisionFront(vListaRevisiones, vRevision);
                }
                else if(esMayorIgual(vFchRevision, fechaPrimerElementoListado(vListaRevisiones)))
                {
                    cargarRevision(vRevision, vCodigoexpediente, vFchRevision);
                    agregarRevisionFront(vListaRevisiones, vRevision);
                }
                else
                    printf("\n-La fecha ingresada es menor a la fecha registrada en la ultima revision.-");
            }
            else
                printf("\n-No existe un expediente al cual asociar la revision ingresada.-\n");
            break;

        case 3:

            printf("\nIngrese el codigo del expediente que desea eliminar: ");
            scanf("%ld", &vCodigoexpediente);
            //Controlo que exista un expediente con el codigo ingresado
            if(existeExpediente(vArbolExpedientes,vCodigoexpediente))
            {
                //Elimino el expediente
                borrarExpedientePorCodigo(vArbolExpedientes,vCodigoexpediente);
                //Elimino todas las revisiones que esten asociadas a ese expediente
                borrarRevision(vListaRevisiones, vCodigoexpediente);
                printf("\n-Se eliminaron los registros del sistema.-\n");
            }
            else
                printf("\n-No existe un expediente con el codigo ingresado.-\n");
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
                    //Controlo previamente que existan registros de expedientes, si existen, muestro los mismos
                    if(!arbolVacio(vArbolExpedientes))
                        mostrarArbol(vArbolExpedientes);
                    else
                        printf("\n-No existen Expedientes ingresados.-\n");
                    break;

                case 2:

                    //Controlo previamente que existan registros de revisiones, si existen, muestro los mismos
                    if(!listaVacia(vListaRevisiones))
                        listarRevisiones(vListaRevisiones);
                    else
                        printf("\n-No existen Revisiones ingresadas.-\n");
                    break;

                case 3:

                    if(!arbolVacio(vArbolExpedientes))
                    {
                        printf("\n-Datos del Expediente con menor codigo:-");
                        mostrarExpediente(Minimo(vArbolExpedientes));
                        printf("\n-Datos del Expediente con mayor codigo:-");
                        mostrarExpediente(Maximo(vArbolExpedientes));
                    }
                    else
                        printf("\n-No existen Expedientes ingresados.-\n");
                    break;

                case 4:

                    printf("\nIngrese el codigo del expediente: ");
                    scanf("%ld", &vCodigoexpediente);
                    if(listaVacia(vListaRevisiones))
                       printf("\-No existen Revisiones asociadas al codigo ingresado.-\n");
                    else
                    {
                            if(existeExpediente(vArbolExpedientes, vCodigoexpediente))
                            {
                                listarRevisionesPorExpediente(vListaRevisiones, vCodigoexpediente);
                            }
                            else
                                 printf("\-No existen Revisiones asociadas al codigo ingresado.-\n");       
                    }
                
                    break;

                case 5:

                    vSalirSubMenuListado=TRUE;
                    break;

                default:
                    printf("-Opcion invalida.-\n");
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
                        printf("\n-Hay un total de %d expedientes registrados con ese apellido-\n",cntExpedientesPorApellido);
                    }
                    else
                        printf("\n-No existen Expedientes ingresados.-\n");
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
                        printf("\n-No existen Expedientes ingresados.-\n");
                }
                break;

                case 3:

                    Fecha vFechaDesde,
                          vFechaHasta;
                    if(!listaVacia(vListaRevisiones))
                    {
                        printf("\nIngrese la fecha desde (dd mm aaaa): ");
                        cargarFecha(vFechaDesde);

                        printf("\nIngrese la fecha hasta (dd mm aaaa): ");
                        cargarFecha(vFechaHasta);

                        if(esMayorIgual(vFechaHasta, vFechaDesde))
                        {
                            printf("-Se realizaron %d revisiones durante ese periodo.-\n", cantidadRevisionesPorFecha(vListaRevisiones, vFechaDesde, vFechaHasta));
                        }
                        else
                            printf("\n-La fecha hasta ingresada debe ser mayor a la fecha desde.-\n") ;
                    }
                    else
                        printf("\n-No existen Revisiones en el sistema, antes de realizar la consulta cargue las mismas.-\n") ;

                    break;

                case 4:
                {
                    int vCntSatisfactorias = 0,
                        vCntIncompletas    = 0,
                        vCntPendientes     = 0;

                    cantidadRevisionesPorTipo(vListaRevisiones, vCntSatisfactorias, vCntIncompletas, vCntPendientes);
                    printf("\n-Total de revisiones satisfactorias: %d -", vCntSatisfactorias);
                    printf("\nTotal de revisiones incompletas: %d -", vCntIncompletas);
                    printf("\nTotal de revisiones pendientes: %d -\n", vCntPendientes);
                }
                break;

                case 5:

                    vSalirSubMenuConsulta=TRUE;
                    break;

                default:
                    printf("-Opcion invalida.-\n");
                }
            }
            while(!vSalirSubMenuConsulta);
            break;

        case 6:

            vSalir = TRUE;

            if(existeArchivo("Expedientes.dat"))
                agregarArbolAArchivo(vArbolExpedientes,"Expedientes.dat");
            else
                crearArchivo("Expedientes.dat", fd);
            agregarArbolAArchivo(vArbolExpedientes,"Expedientes.dat");

            if(existeArchivo("Revisiones.dat"))
                agregarListaAArchivo(vListaRevisiones,"Revisiones.dat");
            else
                crearArchivo("Revisiones.dat", fd);
            agregarListaAArchivo(vListaRevisiones,"Revisiones.dat");

            break;

        default:
            printf("-Opcion invalida.-\n\n");
        }
    }
    while(!vSalir);
}
