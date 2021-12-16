/**
  *\file actions.h
  *\author Nathan FAYNOT
  *\brief Header de actions.c
  */

  #ifndef ACTIONS_H
  #define ACTIONS_H

  #include "personnages.h"
  #include "constantes.h"
  #include "salle.h"
  #include <time.h> //Pour le srand(time(NULL)) dans le main.

  /**
    *\brief Déplace le personnage
    *\param plateau Le pplateau
    *\param p Le pointeur sur les personnages
    *\param direction Caractère précisant la direction du personnage
    *\param i Pointeur sur l'indice permettant de savoir quel personnage se déplace (0 ou 1)
    */
void deplacement(salle_t** plateau,Perso *p,const char* direction, int *i);


/**
  *\brief Règle la vie du personnage
  *\param p Le pointeur sur les personnages
  *\param i Indice permettant de savoir quel personnage voit sa vie changer (0 ou 1)
  *\param v Vie à ajouter ou enlever
  */
void vie(Perso *p, int i, int v);


/**
  *\brief Remet à un le nombre de mouvement du personnage
  *\param p Le pointeur sur les personnages
  *\param i Indice permettant de savoir quel personnage voit son point de mouvement réinitialiser (0 ou 1)
  */
void mouvement(Perso *p, int i);


/**
  *\brief Génère un chiffre/nombre aléatoire entre a et b inclues.
 * \param a Valeur la plus basse qui peut être retournée.
 * \param b Valeur la plus haute qui peut être retournée.
  */
int randint(int a, int b);


/**
*\brief Fait s'attaquer les personnages
*\param p Le pointeur sur les personnages
*\param att Indice permettant de savoir quel personnage attaque (0 ou 1)
*\param def Indice permettant de savoir quel personnage se défend (0 ou 1)
*/
void attaque(Perso *p, int att, int def);


/**
  *\brief Fais se combattre les personnages et défini qui attaque en premier
  *\param p Le pointeur sur les personnages
  */
void combat(Perso *p);


  #endif
