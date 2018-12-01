#include "Menu.h"

void mostrarMenu(int &pOpcion)
{
    printf("\n**Opciones**\n");
    printf("\n1 - Carga de expediente.");
    printf("\n2 - Registrar Revision.");
    printf("\n3 - Borrar expediente.");
    printf("\n4 - Listados.");
    printf("\n5 - Consultas.");
    printf("\n6 - Salir.");
    printf("\nSeleccione una opcion: ");
    fflush(stdin);
    scanf("%d", &pOpcion);


}

void mostrarSubMenuListados(int &pOpcion)
{
        printf("\n1 - Listar todos los expedientes del sistema.");
        printf("\n2 - Listar todas las revisiones del sistema.");
        printf("\n3 - Listar datos del mayor y menos expediente.");
        printf("\n4 - Listar revisiones por codigo de expediente.");
        printf("\n5 - Volver.");
        printf("\nOpcion: ");
        fflush(stdin);
        scanf("%d", &pOpcion);
}


void mostrarSubMenuConsultas(int &pOpcion)
{
        printf("\n1 - Contar expedientes por apellido de escribano.");
        printf("\n2 - Obtener codigo de expediente con mas revisiones.");
        printf("\n3 - Cantidad de expedientes entre dos fechas.");
        printf("\n4 - Contar total de revisiones por tipo.");
        printf("\n5 - Volver.");
        printf("\nOpcion: ");
        fflush(stdin);
        scanf("%d", &pOpcion);
}


boolean validarOpcionMenu(int pOpcion)
{
    boolean vValida = TRUE;

    if(pOpcion<1 && pOpcion>6)
        vValida = FALSE;

    return vValida;
}

boolean validarOpcionSubMenu(int pOpcion)
{
    boolean vValida = TRUE;

    if(pOpcion<1 && pOpcion>5)
        vValida = FALSE;

    return vValida;
}

