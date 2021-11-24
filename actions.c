/**
  *\file actions.c
  *\author Nathan FAYNOT
  *\brief Ensemble des fonctions sur les actions des personnages
  */

#include "actions.h"

void deplacement(Perso *p, int i, int x, int y)
{
  if(p[i].action != 0)
  {
    p[i].x += x;
    p[i].y += y;
    p[i].action--;
  }
  else
  {
    printf("Vous ne pouvez pas vous deplacer, vous n'avez plus d'action.\n");
  }
}

void vie(Perso *p, int i, int v)
{
  p[i].pv += v;
}

void action(Perso *p, int i)
{
  p[i].action = CONST_ACT;
}

int randint(int a, int b)
{
    if (a >= b)
    {
      return a;
    }
    else
    {
      return rand()%(b-a)+a;
    }
}

void attaque(Perso *p, int att, int def)
{
  int deg = p[def].o.protection - p[att].attaque + p[att].o.degat; //Cacul des dégâts infligés
  vie(p, def, deg);
}

void combat(Perso *p)
{
  if(p[0].o.poids == p[1].o.poids)
  {

  }
  else
  {
    if(p[0].o.poids > p[1].o.poids)
    {
      attaque(p, 1, 0);
      if(estMort(p, 0) == 0)
      {

      }
      else
      {
        attaque(p, 0, 1);
        if(estMort(p, 1) == 0)
        {

        }
      }
    }
    else
    {
      attaque(p, 0, 1);
      if(estMort(p, 1) == 0)
      {

      }
      else
      {
        attaque(p, 1, 0);
        if(estMort(p, 0) == 0)
        {

        }
      }
    }
  }
}
