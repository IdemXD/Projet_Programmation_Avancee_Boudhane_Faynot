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
    o.protection = 0;
    o.poids = 3;
  }
  else if(a == EPEE)
  {
    o.a = EPEE;
    o.degat = 2;
    o.protection = 1;
    o.poids = 4;
  }
  else if(a == LANCE)
  {
    o.a = LANCE;
    o.degat = 3;
    o.protection = 0;
    o.poids = 2;
  }
  else if(a == BOUCLIER)
  {
    o.a = BOUCLIER;
    o.degat = 1;
    o.protection = 3;
    o.poids = 5;
  }
  else if(a == DAGUE)
  {
    o.a = DAGUE;
    o.degat = 5;
    o.protection = 0;
    o.poids = 1;
  }
  else
  {
    o.a = RIEN;
    o.degat = 1;
    o.protection = 0;
    o.poids = 0;
  }
  return o;
}

char* nom_objet(Objet o)
{
  switch (o.a)
  {
    case HACHE :
    {
      return "Hache";
    }
    case EPEE :
    {
      return "Epée";
    }
    case LANCE :
    {
      return "Lance";
    }
    case BOUCLIER :
    {
      return "Bouclier";
    }
    case DAGUE :
    {
      return "Dague";
    }
    return "Rien";
  }
}

void print_objet(Objet o)
{
  if(o.a == RIEN)
  {
    printf("Aucune arme n'est tenu.\n");
  }
  else
  {
    printf("Le nom de l'arme tenu est : %s.\n", nom_objet(o));
  }
  printf("L'arme fait  %d de dégât.\n",o.degat);
  printf("L'arme donne %d de protection.\n",o.protection);
  printf("L'arme possède un poids de : %d.\n",o.poids);
}

Objet set_objet(Objet o, int chx)
{
  if(chx == 1)
  {
    o.degat += 1;
    return o;
  }
  if(chx == 2)
  {
    o.protection += 1;
    return o;
  }
  if(chx == 3)
  {
    o.poids -= 1;
    return o;
  }
}
