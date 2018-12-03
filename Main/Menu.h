#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Boolean.h"

void mostrarMenu(int &pOpcion);

void mostrarSubMenuListados(int &pOpcion);

void mostrarSubMenuConsultas(int &pOpcion);

boolean validarOpcionMenu(int pOpcion);

boolean validarOpcionSubMenu(int pOpcion);

#endif // MENU_H_INCLUDED
