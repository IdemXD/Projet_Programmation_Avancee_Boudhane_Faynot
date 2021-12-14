/**
  *\file personnages.h
  *\author Nathan FAYNOT
  *\brief Header de personnages.c
  */

#ifndef PERSONNAGES_H
#define PERSONNAGES_H

#include "constantes.h"
#include "objet.h"

typedef struct
{
  int x; //Coordonnée en abscisse du personnage.
  int y; //Coordonnée en ordonnée du personnage.
  int mouv; //Mouvement des personnages.
  int pv; //Point de vie du personnage.
  int etat; //1 quand l'état du personnage est normal, 0 quand le personnage est empoisonné.
  int state;
  Objet o; //Objet récupérer par le personnage.
}Perso;


/**
  *\brief Crée les personnages
  *\return Retourne deux personnages initialisés
  */
Perso* creer_perso();


/**
  *\brief Charge les personnages sur le plateau
  *\param p Le pointeur sur les personnages
  */
void charger_perso(Perso* p);


/**
  *\brief Libère le pointeur
  *\param p Le pointeur sur les personnages
  */
void free_perso(Perso *p);


/**
  *\brief Affiche les points de vie ainsi que les actions d'un des personnages
  *\param p Le pointeur sur les personnages
  *\param i Indice permettant de savoir quel personnage voit ses caractéristiques afficher (0 ou 1)
  */
void print_stats(Perso *p, int i);


/**
  *\brief Regarde les points de vie du personnages et renvoie 1 si il est vivant et 0 si il est mort.
  *\param p Le pointeur sur les personnages
  *\param i Indice permettant de savoir quel personnage est peut-être mort. (0 ou 1)
  */
  int estMort(Perso *p, int i);
#endif
