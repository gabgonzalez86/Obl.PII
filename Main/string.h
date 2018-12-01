#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "Boolean.h"

const int MAX = 80;
typedef char * String;


//crea un string vacío
void strcrear (String &s);

//libera la memoria usada por el string
void strdestruir (String &s);

//lee el string s desde teclado
void scan (String &s);

//imprime el string s por pantalla
void print (String s);

//determina si los strings s1 y s2 son iguales
boolean streq (String s1, String s2);

void strcop (String &s1,String s2);

int strlar (String s);

//agrega los caracteres del string en el archivo
void agregarStringAArchivo(String s, FILE * f);
//PRECONDICION: El archivo debe estar abierto para escritura.

//lee desde el archivo los caracteres del string
void leerStringDeArchivo (String &s, FILE * f);
//PRECONDICION: El archivo debe estar abierto para lectura

#endif // STRING_H_INCLUDED
