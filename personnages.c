/**
  *\file personnages.c
  *\author Nathan FAYNOT
  *\brief Ensemble des fonctions sur les personnages
  */

#include <stdio.h>
#include <stdlib.h>
#include "personnages.h"

void creer_perso(Perso* p, int x, int y)
{
  (*p).x = x;
  (*p).y = y;
}
