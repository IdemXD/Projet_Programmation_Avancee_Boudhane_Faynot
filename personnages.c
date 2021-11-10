/**
  *\file personnages.c
  *\author Nathan FAYNOT
  *\brief Ensemble des fonctions sur les personnages
  */

#include <stdio.h>
#include <stdlib.h>
#include "personnages.h"

Perso* creer_perso()
{
  Perso *p = malloc(sizeof(Perso)*2);
  for(int i = 0;i < 2;i++)
  {
    p[i].x = 0 + i*4;
    p[i].y = 0 + i*4;
    p[i].nb_action = 1;
    p[i].pv = 10;
  }
  return p;
}

void charger_perso(Perso *p)
{
  int i = 0;
  for(int j = 0;j < TAILLE_PL;j++)
  {
    for(int k = 0;k < TAILLE_PL;k++)
    {
      if(j == p[i].x && k == p[i].y)
      {
        printf("J");
        i++;
      }
      else
      {
        printf("0");
      }
    }
    printf("\n");
  }
}

void free_perso(Perso *p)
{
  free(p);
}

void print_pv_action(int act, int pv)
{
  printf("Nombre d'action : %d/%d.\n",act,act);
  printf("Nombre de point de vie : %d.\n",pv);
}
