/**
  *\file personnages.h
  *\author Nathan FAYNOT
  *\brief Header de personnages.c
  */

#ifndef PERSONNAGES_H
#define PERSONNAGES_H

typedef struct
{
  int x; //Coordonnée en abscisse du personnage
  int y; //Coordonnée en ordonnée du personnage
}Perso;

/**
  *\brief Crée le personnage
  *\param p Variable que l'on va initialiser
  */
void creer_perso(Perso* p, int x, int y);

#endif
