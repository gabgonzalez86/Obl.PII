#include "Menu.h"

void mostrarMenu()
{
    printf("**Opciones**");
    printf("\n1 - Carga de expediente.");
    printf("\n2 - Registrar Revision.");
    printf("\n3 - Borrar expediente.");
    printf("\n4 - Listados.");
    printf("\n5 - Consultas.");
    printf("\n6 - Salir.");


}

void mostrarSubMenuListados(int opcion)
{
        printf("\n1 - Listar todos los expedientes del sistema.");
        printf("\n2 - Listar todas las revisiones del sistema.");
        printf("\n3 - Listar datos del mayor y menos expediente.");
        printf("\n4 - Lisar revisiones por codigo de expediente.");
}


void mostrarSubMenuConsultas(int opcion)
{
        printf("\n1 - Contar expedientes por apellido de escribano.");
        printf("\n2 - Obtener codigo de expediente con mas revisiones.");
        printf("\n3 - Cantidad de expedientes entre dos fechas.");
        printf("\n4 - Contar total de revisiones por tipo.");
}

