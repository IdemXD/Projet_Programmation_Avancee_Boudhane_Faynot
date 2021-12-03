#include <stdio.h>
#include <stdlib.h>
#include "personnages.h"
#include "actions.h"


int main()
{

  Perso *p = creer_perso();
  // printf("%d, %d\n",p[0].x, p[0].y);
  // printf("%d, %d\n",p[1].x, p[1].y);
  // printf("\n");
  //
  // charger_perso(p);
  //
  // deplacement(p, 0, 0, 1);
  // deplacement(p, 1, -1 ,0);
  // printf("%d, %d\n",p[0].x, p[0].y);
  // printf("%d, %d\n",p[1].x, p[1].y);
  // printf("\n");
  // deplacement(p, 1, -1 ,0);
  //
  // printf("    Premier print des statistiques Premier joueur :\n\n");
  // print_stats(p, 0);
  // printf("    Premier print des statistiques Deuxième joueur :\n\n");
  // print_stats(p, 1);
  // printf("\n");

  printf("    Changement de certaines statistiques.\n");
  vie(p, 0, -4);
  vie(p, 1, 5);
  mouvement(p, 0);
  mouvement(p, 1);
  p[0].o = init_objet(HACHE);
  p[1].o = init_objet(DAGUE);
  printf("\n");

  printf("    Deuxième print des statistiques Premier joueur :\n\n");
  printf("Mort du permier joueur : %d.\n",estMort(p,0));
  print_stats(p, 0);
  printf("    Deuxième print des statistiques Deuxième joueur :\n\n");
  printf("Mort du deuxième joueur : %d.\n",estMort(p,1));
  print_stats(p, 1);
  printf("\n");

  printf("    Test de combat 1 :\n\n");
  int f = 1;
  combat(p, &f);
  printf("\nFin == %d\n\n",f);

  printf("    Changement de certaines statistiques.\n");
  vie(p, 0, 4);
  vie(p, 1, -8);
  p[0].o = init_objet(DAGUE);
  print_objet(p[1].o);
  p[1].o = set_objet(p[1].o, 2);
  p[1].o = set_objet(p[1].o, 1);
  p[1].o = set_objet(p[1].o, 3);
  p[0].o = set_objet(p[0].o, 3);
  printf("\n");
  print_objet(p[1].o);
  printf("\n");

  printf("    Test de combat 2 :\n\n");
  printf("La vie des deux joueur vient d'être initalisée à 5.\nLeurs armes respective possèdent le même poids désormais.\n\n");
  combat(p, &f);
  printf("\nFin == %d\n",f);


  free_perso(p);
}
