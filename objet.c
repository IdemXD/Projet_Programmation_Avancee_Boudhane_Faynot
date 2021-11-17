/**
  *\file objet.c
  *\author Nathan FAYNOT
  *\brief Ensemble des fonctions sur les objets.
  */

#include "objet.h"

Objet init_objet(Arme a)
{
  Objet o;
  if(a == HACHE)
  {
    o.a = HACHE;
    o.degat = 2;
    o.protection = 1;
    o.resistance = 3;
  }
  else if(a == EPEE)
  {
    o.a = EPEE;
    o.degat = 2;
    o.protection = 2;
    o.resistance = 2;
  }
  else if(a == LANCE)
  {
    o.a = LANCE;
    o.degat = 3;
    o.protection = 0;
    o.resistance = 2;
  }
  else if(a == BOUCLIER)
  {
    o.a = BOUCLIER;
    o.degat = 1;
    o.protection = 4;
    o.resistance = 4;
  }
  else if(a == DAGUE)
  {
    o.a = DAGUE;
    o.degat = 5;
    o.protection = 0;
    o.resistance = 1;
  }
  else
  {
    o.a = RIEN;
    o.degat = 0;
    o.protection = 0;
    o.resistance = 10;
  }
  return o;
}

char* nom_objet(Objet o)
{
  if(o.a == HACHE)
  {
    return "Hache";
  }
  if(o.a == EPEE)
  {
    return "Epée";
  }
  if(o.a == LANCE)
  {
    return "Lance";
  }
  if(o.a == BOUCLIER)
  {
    return "Bouclier";
  }
  if(o.a == DAGUE)
  {
    return "Dague";
  }
  return "Rien";
}

void print_objet(Objet o)
{
  if(o.a == HACHE)
  {
    printf("Le nom de l'arme tenu est : Hache.\n");
  }
  else if(o.a == EPEE)
  {
    printf("Le nom de l'arme tenu est : Epée.\n");
  }
  else if(o.a == LANCE)
  {
    printf("Le nom de l'arme tenu est : Lance.\n");
  }
  else if(o.a == BOUCLIER)
  {
    printf("Le nom de l'arme tenu est : Bouclier.\n");
  }
  else if(o.a == DAGUE)
  {
    printf("Le nom de l'arme tenu est : Dague.\n");
  }
  else
  {
    printf("Aucune arme n'est tenu.\n");
  }
  printf("L'arme donne %d de dégât en plus.\n",o.degat);
  printf("L'arme donne %d de protection en plus.\n",o.protection);
  printf("L'arme possède %d de resistance.\n",o.resistance);
}
