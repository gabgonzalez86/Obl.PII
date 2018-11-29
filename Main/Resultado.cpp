#include "Resultado.h"


void mostrarResultado(resultado r)
{
    switch(r)
    {
    case Satisfacoria:
        printf("Satisfactoria\n");
        break;
    case Incompleta:
        printf("Incompleta\n");
        break;
    case Pendiente:
        printf("Pendiente\n");
        break;
    }
}
