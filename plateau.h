/**
  * \file plateau
  * \author Boudhane Medi
  * \brief Création d'un tableau pl à deux dimensions de structures
*/

#ifndef PLATEAU_H
#define PLATEAU_H

#include "salle.h"

/**
  * \brief Création du tableau de structures 2D
  * \return Pointeur du tableau créé
*/
salle_t** creer_plateau();

int is_in(int element,const char *tab, int tab_length);

void init_salles(char salle[5], salle_t** pl, int n);

salle_t** charger_plateau(char* niveau);

void affichage_plateau_lettre(salle_t** pl);

void affichage_plateau_coordonnees(salle_t** pl);

void free_plateau(salle_t** pl);


#endif