/**
  * \file plateau
  * \author Boudhane Medi
  * \brief Création d'un tableau pl à deux dimensions de structures
*/

#ifndef PLATEAU_H
#define PLATEAU_H

#include "salle.h"
#include "constantes.h"


int is_in(int element,const char *tab, int tab_length);

void init_salles(char salle[5], salle_t** pl, int n);


char* preparation_chemin();


int chars_valide(char paquet[5]);

salle_t** creer_plateau();


salle_t** charger_plateau(char* niveau);

void proposition_sauvegarde(salle_t** pl);

void sauvegarder_plateau(salle_t** pl, char* niveau);


void free_plateau(salle_t** pl);


void affichage_plateau_lettre(salle_t** pl);


void affichage_plateau_coordonnees(salle_t** pl);


void affichage_plateau_caracteristique(salle_t** pl);

int plateau_est_visible(salle_t** pl);
#endif