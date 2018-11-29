#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "Boolean.h"

const int MAX = 80;
typedef char * String;


//crea un string vac�o
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

#endif // STRING_H_INCLUDED
