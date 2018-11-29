#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "Expediente.h"


typedef struct nodoA {Expediente expedientes;
                      nodoA * hizq;
                      nodoA * hder;
                     }nodo;

typedef nodo * Arbol;


//Crea un arbol
void crearArbol(Arbol &a);

//Devuelve si el arbol es vacio
boolean arbolVacio(Arbol a);

//Devuelve la raiz del arbol
Expediente darRaiz(Arbol a);
//PRECONDICION: El arbol no puede estar vacio

//Devuelve el hijo izquierdo del arbol
Expediente darHijoIzquierdo(Arbol a);
//PRECONDICION: El arbol no puede estar vacio

//Devuelve el hijo derecho del arbol
Expediente darHijoDerecho(Arbol a);
//PRECONDICION: El arbol no puede estar vacio

//Devuelve la cantidad de expedientes por apellido
int cantidadExpedientesPorEscribano(Arbol a, String apellido);

//Borra el exepediente del arbol
void borrarExpediente(Arbol &a, Expediente exp);
//PRECONDICION: El expediente debe existir

//Verifica si existe el expediente
boolean existeExpediente(Arbol a, long codigo);

//Devuelve el mayor expediete y el menor expediente
void mayorMenorExpediente(Arbol a);

//Muestra los expedientes del arbol
void listarExpedientes(Arbol a);

#endif // ARBOL_H_INCLUDED
