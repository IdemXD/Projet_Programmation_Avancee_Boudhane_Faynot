/**
  *\file objet.h
  *\author Nathan FAYNOT
  *\brief Header de objet.c
  */

  #ifndef OBJET_H
  #define OBJET_H

  #include <stdio.h>
  #include <stdlib.h>

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

  /**
    *\brief Initialise un objet en fonction du nom provenant de l'enum Arme
    *\param a Nom de l'arme qui va être initialiser dans un Objet
    *\return L'objet créé est retourné
    */
  Objet init_objet(Arme a);

  /**
    *\brief Retourne le nom d'une arme
    *\param o Objet dont l'on souhaite le nom
    *\return Le nom de l'arme sous la forme d'un string
    */
  char* nom_objet(Objet o);

  /**
    *\brief Affiche les statistiques d'un objet
    *\param o Objet dont l'on souhaite connaîtreles statistiques
    */
  void print_objet(Objet o);
  #endif
