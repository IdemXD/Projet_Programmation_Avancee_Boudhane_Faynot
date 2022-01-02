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


void Salle_arme(Arme a,Perso* joueur);

void Salle_soin(salle_t** pl,Perso* perso,int* tour_perso,int x,int y);

void Salle_poison(Perso* perso,int* tour_perso);

void vie_poison(Perso* perso,int* tour_perso);


void Cherche_salle_specifique(salle_t** pl ,Perso*  persos,int* tour_perso ,char salle, int* a , int* b);

void Salle_combat(salle_t** pl,Perso* joueur,int tour);

void Salle_surprise(salle_t **pl,Perso* persos,char salle_Depile,int* tour_perso,int a,int b);

void Salle_chaleur(Perso* perso,int* tour_perso);

void Salle_passage(salle_t** pl,Perso* perso);

void action_salle(salle_t**  pl,Perso* joueur,int* tour_perso, int tour);

void modif_visible_et_etat(salle_t** plateau,int x, int y);

#endif

