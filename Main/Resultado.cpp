#include "Resultado.h"


void mostrarResultado(resultado r)
{
    switch(r)
    {
    case satisfacoria:
        printf("Satisfactoria\n");
        break;
    case incompleta:
        printf("Incompleta\n");
        break;
    case pendiente:
        printf("Pendiente\n");
        break;
    }
}
