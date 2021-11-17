/**
  *\file actions.h
  *\author Nathan FAYNOT
  *\brief Header de actions.c
  */

  #ifndef ACTIONS_H
  #define ACTIONS_H

  #include "personnages.h"
  #include "constantes.h"

  /**
    *\brief Déplace le personnage
    *\param p Le pointeur sur les personnages
    *\param i Indice permettant de savoir quel personnage voit ses caractéristiques changer
    *\param x Déplacement sur l'abscisse
    *\param y Déplacement sur l'ordonnée
    */
void deplacement(Perso *p, int i, int x, int y);


/**
  *\brief Règle la vie du personnage
  *\param p Le pointeur sur les personnages
  *\param i Indice permettant de savoir quel personnage voit ses caractéristiques changer
  *\param v Vie à ajouter ou enlever
  */
void vie(Perso *p, int i, int v);


/**
  *\brief Règle les actions du personnage
  *\param p Le pointeur sur les personnages
  *\param i Indice permettant de savoir quel personnage voit ses caractéristiques changer
  *\param a Nombre d'action qu'aura le personnage au prochain tour
  */
void action(Perso *p, int i, int a);

  #endif
