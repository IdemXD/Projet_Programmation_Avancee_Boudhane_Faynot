#ifndef SALLE_H
#define SALLE_H

/**
	*\file salle.h
	*\author Boudhane Medi
	*\version 1.0
*/


#include "constantes.h"
#include "personnages.h"
#include "objet.h"



struct salle_s{
    int x;       /*!< Tableau contenant la coordonnée x de la salle */
    int y;       /*!< Tableau contenant la coordonnée y de la salle */
    int pres;    /*!< Présence de la salle(1 si la salle est utilisable )*/
    int state;   /*!< Etat de la salle(1 si la salle est utilisable )*/
    int visible; /*!< Etat de la salle (1 si la salle est visible)*/
    int cpt_use;  /*!< Compteur de présence sur salle */
    char type;   /*!< Char représentant la salle*/
};
typedef struct salle_s salle_t;

void Salle_arme(Perso* p,Arme a);

void salle_soin(Perso* perso,int tour_perso);

void salle_poison(Perso* perso,int tour_perso);


#endif
