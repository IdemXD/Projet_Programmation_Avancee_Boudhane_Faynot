/**
  *\file personnages.c
  *\author Nathan FAYNOT
  *\brief Ensemble des fonctions sur les personnages
  */

#include "personnages.h"

Perso* creer_perso()
{
  Perso *p = malloc(sizeof(Perso)*2); //Il y a deux personnages.
  for(int i = 0;i < 2;i++)
  {
    p[i].x = 0 + i*4; //Initialise l'abscisse des personnages.
    p[i].y = 0 + i*4; //Initialise l'ordonnée des personnages.
    p[i].nb_action = CONST_ACT; //Initialise le nombre d'action des personnages.
    p[i].pv = 10; //Initialise les points de vie des personnages.
    p[i].attaque = 1;//Initialise l'attaque de base des personnages.
    p[i].etat =1;
    p[i].defense = 1;//Initialise la défense de base des personnages.
    p[i].o = init_objet(RIEN);//Initialise l'Arme RIEN à chaque personnages.
  }
  return p;
}

void charger_perso(Perso *p)
{
  int i = 0;
  for(int j = 0;j < TAILLE_PL;j++) //Parcours l'abscisse.
  {
    for(int k = 0;k < TAILLE_PL;k++) //Parcours l'ordonnée.
    {
      if(j == p[i].x && k == p[i].y) //Affiche P si j et k corresponde à l'abscisse et l'ordonnée.
      {
        printf("P");
        i++; //Change de personnage.
      }
      else
      {
        printf("0");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void free_perso(Perso *p)
{
  free(p);
}

void print_stats(Perso *p, int i)
{
  printf("Nombre d'action : %d/%d.\n",p[i].nb_action, p[i].nb_action);
  printf("Nombre de point de vie : %d.\n",p[i].pv);
  printf("\n");
  printf("Nombre de point d'attaque : %d.\n",p[i].attaque);
  printf("Nombre de point de défense : %d.\n",p[i].defense);
  printf("\n");
  print_objet(p[i].o);
  printf("\n");
}
