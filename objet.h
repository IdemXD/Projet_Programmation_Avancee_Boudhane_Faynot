/**
  *\file objet.h
  *\author Nathan FAYNOT
  *\brief Header de objet.c
  */

  #ifndef OBJET_H
  #define OBJET_H

  #include "personnages.h"
  #include "actions.h"

  typedef enum
  {
    RIEN, HACHE, EPEE, LANCE, BOUCLIER, DAGUE
  }Arme;

  typedef struct
  {
    Arme a; //Nom de l'arme.
    int degat; //Dégât de l'arme.
    int protection; //Protection donné par l'arme.
    int resistance; //Nombre de fois où le joueur peut utiliser l'arme.
  }Objet;

  #endif
