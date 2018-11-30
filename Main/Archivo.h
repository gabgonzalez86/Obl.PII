#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "Arbol.h"
#include "ListaRevision.h"

void agregarExpediente(String pNomArch, Expediente pExpediente);

boolean existeExpediente(String pNomArch);

boolean expedienteVacio (String pNomArch);

boolean expedientePertenece (String pNomArch, Expediente pExpediente);


void agregarRevision(String pNomArch, Revision pRevision);

boolean existeRevision(String pNomArch);

boolean revisionVacio (String pNomArch);

boolean revisionPertenece (String pNomArch, Revision pRevision);





#endif // ARCHIVO_H_INCLUDED
