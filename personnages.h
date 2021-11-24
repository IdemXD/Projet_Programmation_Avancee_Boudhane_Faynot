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
  int nb_action; //Nombre d'action que le personnage possède.
  int pv; //Point de vie du personnage.
  int attaque; //Point d'attaque de base du personnage.
  int defense; //Défense de base du personnage.
  int etat; //
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
  *\param i Indice permettant de savoir quel personnage voit ses caractéristiques affihcer
  */
void print_stats(Perso *p, int i);


#endif
