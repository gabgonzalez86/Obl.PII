#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "ListaRevision.h"

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
void GuardarExpediente(Arbol &a, Expediente pExp);
//PRECONDICION: verificar que no exista el expediente

//Muestra los registros del arbol de expedientes en orden
void mostrarArbol(Arbol pArbolExpedientes);

//Devuelve la cantidad de expedientes por apellido
int cantidadExpedientesPorEscribano(Arbol a, String pApellido);

//Devuelve el valor mínimo
Expediente Minimo(Arbol a);
//PRECONDICION: verificar que el arbol NO este vacío

//Devuelve el valor maximo
Expediente Maximo(Arbol a);
//PRECONDICION: verificar que el arbol NO este vacío

//Borra el valor mínimo
void borrarMinimo(Arbol &a);
//PRECONDICION: verificar que el arbol NO este vacío

void borrarExpedientePorCodigo(Arbol &a, long pCodigo);

//Verifica si existe el expediente
boolean existeExpediente(Arbol a, long pCodigo);

//Se obtiene el expediente que tiene mas revisiones
void masRevProExp(Arbol pArbolExpedientes, Lista pListaRevisiones, long &pCodigo, int &pCantidad);

//agrega al archivo los datos del árbol
void agregarArbolAuxArchivo(Arbol a, FILE * f);
//PRECONDICION: El archivo debe estar abierto para escritura

// Abre el archivo para escritura y agrega al archivo los datos del árbol
//llamando al procedimiento agregarArbolAuxArchivo
void agregarArbolAArchivo(Arbol a, String pArchivo);

//Abre el archivo para lectura y agrega al árbol los Expedientes
//llamando al procedimiento GuardarExpediente
void leerArbolDeArchivo(Arbol &a, String pArchivo);
//PRECONDICION: validar que exista el archivo

#endif // ARBOL_H_INCLUDED
