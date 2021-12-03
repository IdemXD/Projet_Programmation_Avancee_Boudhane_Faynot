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
    int poids; //Le poids d'une arme défini le tour de jeu, le personnage ayant le poids le plus faible attaque en premier.
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
    *\param o Objet dont l'on souhaite connaître les statistiques
    */
  void print_objet(Objet o);

  /**
    *\brief Améliore une caractéristique de l'objet
    *\param o Objet que l'on veut améliorer.
    *\param chx Paramètre définissant la caractéristique choisie.
    *\return L'objet amélioré est retourné
    */
  Objet set_objet(Objet o, int chx);
  #endif
