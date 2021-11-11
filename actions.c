/**
  *\file actions.c
  *\author Nathan FAYNOT
  *\brief Ensemble des fonctions sur les actions des personnages
  */

#include "actions.h"

void deplacement(Perso *p, int i, int x, int y)
{
  p[i].x += x;
  p[i].y += y;
}

void vie(Perso *p, int i, int v)
{
  p[i].pv += v;
}

void action(Perso *p, int i, int a)
{
  p[i].nb_action = a;
}
