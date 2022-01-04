/**
  *\file personnages.c
  *\author Nathan FAYNOT
  *\brief Ensemble des fonctions sur les personnages
  */

#include "personnages.h"

Perso* creer_perso()
{
  Perso *p = malloc(sizeof(Perso)*NB_PERSO); //Il y a deux personnages.
  for(int i = 0;i < NB_PERSO;i++)
  {
    p[i].x = 0 + i*4; //Initialise l'abscisse des personnages.
    p[i].y = 0 + i*4; //Initialise l'ordonnée des personnages.
    p[i].mouv = CONST_MOUV; //Initialise l'action des personnages (1 action == 1 déplacement).
    p[i].pv = 10; //Initialise les points de vie des personnages.
    p[i].state = 1 ; //les personnages sont vivants
    p[i].etat = 1; //Initialise l'état du personnage.
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
  printf("Point de mouvement du joueur %d : %d/%d.\n",i + 1,p[i].mouv, p[i].mouv + 1);
  printf("Nombre de point de vie : %d.\n",p[i].pv);
  print_objet(p[i].o);
  printf("\n");
}

int estMort(Perso *p, int i)
{
  return p[i].pv < 0;
}
