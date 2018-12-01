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
Arbol darHijoIzquierdo(Arbol a);
//PRECONDICION: El arbol no puede estar vacio

//Devuelve el hijo derecho del arbol
Arbol darHijoDerecho(Arbol a);
//PRECONDICION: El arbol no puede estar vacio

// Guarda un nuevo Expediente
void GuardarExpediente(Arbol &a, Expediente exp);
//PRECONDICION: verificar que no exista el expediente

//FALTA
//Devuelve la cantidad de expedientes por apellido
int cantidadExpedientesPorEscribano(Arbol a, String apellido);
//FALTA


//Devuelve el valor mínimo
Expediente Minimo(Arbol a);
//PRECONDICION: verificar que el arbol NO este vacío

//Borra el valor mínimo
void borrarMinimo(Arbol &a);
//PRECONDICION: verificar que el arbol NO este vacío

//Borra el exepediente del arbol
void borrarExpediente(Arbol &a, Expediente exp);
//PRECONDICION: El expediente debe existir


//FALTA
//Verifica si existe el expediente
boolean existeExpediente(Arbol a, long codigo);

//Devuelve el mayor expediete y el menor expediente
void mayorMenorExpediente(Arbol a);

//Muestra los expedientes del arbol
void listarExpedientes(Arbol a);
//FALTA

//agrega al archivo los datos del árbol
void agregarArbolAuxArchivo(Arbol a, FILE * f);
//PRECONDICION: El archivo debe estar abierto para escritura

// Abre el archivo para escritura y agrega al archivo los datos del árbol
//llamando al procedimiento agregarArbolAuxArchivo
void agregarArbolAArchivo(Arbol a, String pArchivo);

#endif // ARBOL_H_INCLUDED
