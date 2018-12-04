#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "Arbol.h"

//Crea archivo
void crearArchivo(String pNombAch, FILE * fd);

//Devuelve si existe el archivo
boolean existeArchivo(String pNomArch);

#endif // ARCHIVO_H_INCLUDED
