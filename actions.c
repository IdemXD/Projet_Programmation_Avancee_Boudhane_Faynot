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
  int deg = p[def].o.protection - p[att].o.degat; //Cacul des dégâts infligés
  if(deg > 0)
  {
    deg = 0;
  }
  printf("La vie du défenseur est maintenant à %d.\n",p[def].pv + deg);
  vie(p, def, deg);
}

void combat(Perso *p, int *fin)
{
  int r1 = 1, r2 = 0;
  if(p[0].o.poids == p[1].o.poids)
  {
    r1 = 0;
    do
    {
      printf("Un jet aléatoire entre 0 et 100 va être effectué.\nLe premier jet sera pour le premier joueur.\n");
      r1 = randint(0,100);
      r2 = randint(0,100);
      printf("Premier jet : %d.\nDeuxième jet : %d.",r1, r2);
      if(r1 == r2)
      {
        printf("Les deux jets étant égaux, on relance deux nouveaux jets.");
      }
    } while(r1 == r2);
  }
  if(p[0].o.poids > p[1].o.poids || r1 < r2)
  {
    printf("Le joueur 2 attaque en premier.\n");
    attaque(p, 1, 0);
    if(estMort(p, 0) == 1)
    {
      printf("Bien joué au joueur %d pour avoir gagné la partie !\n",2);
      *fin = 0;
    }
    else
    {
      printf("Au tour du joueur 1 d'attaquer.\n");
      attaque(p, 0, 1);
      if(estMort(p, 1) == 1)
      {
        printf("Bien joué au joueur %d pour avoir gagné la partie !\n",1);
        *fin = 0;
      }
    }
  }
  else
  {
    printf("Le joueur 1 attaque en premier.\n");
    attaque(p, 0, 1);
    if(estMort(p, 1) == 1)
    {
      printf("Bien joué au joueur %d pour avoir gagné la partie !\n",1);
      *fin = 0;
    }
    else
    {
      printf("Au tour du joueur 2 d'attaquer.\n");
      attaque(p, 1, 0);
      if(estMort(p, 0) == 1)
      {
        printf("Bien joué au joueur %d pour avoir gagné la partie !\n",2);
        *fin = 0;
      }
    }
  }
}
