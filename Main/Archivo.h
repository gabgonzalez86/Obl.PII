#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "Arbol.h"
#include "ListaRevision.h"

void agregar(String nomArch, int entero);

boolean existe(String nomArch);

boolean Vacio (String nomArch);

boolean Pertenece (String nomArch, int entero);

int Largo (String nomArch);

int Kesimo (String nomArch, int k);


#endif // ARCHIVO_H_INCLUDED
