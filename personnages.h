/**
  *\file personnages.h
  *\author Nathan FAYNOT
  *\brief Header de personnages.c
  */

#ifndef PERSONNAGES_H
#define PERSONNAGES_H

#include "plateau.h"
#include "constantes.h"

typedef struct
{
  int x; //Coordonnée en abscisse du personnage.
  int y; //Coordonnée en ordonnée du personnage.
  int nb_action; //Nombre d'action que le personnage possède.
  int pv; //Point de vie du personnage.
}Perso;

/**
  *\brief Crée le personnage
  *\param p Variable que l'on va initialiser
  */
Perso* creer_perso();

void charger_perso(Perso* p);

void free_perso(Perso *p);

void print_pv_action(int act, int pv);

#endif
