#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "personnages.h"
#include "actions.h"

int main()
{
  Perso *p = creer_perso();
  printf("%d, %d\n",p[0].x, p[0].y);
  printf("%d, %d\n",p[1].x, p[1].y);
  printf("\n");

  charger_perso(p);

  printf("    Premier print des statistiques Premier perso :\n");
  print_stats(p, 0);
  printf("    Premier print des statistiques Deuxième perso :\n");
  print_stats(p, 1);
  printf("\n");

  deplacement(p, 0, 0, 1);
  deplacement(p, 1, -1 ,0);
  printf("%d, %d\n",p[0].x, p[0].y);
  printf("%d, %d\n",p[1].x, p[1].y);
  printf("\n");

  printf("    Changement de certaines statistiques.\n");
  vie(p, 0, -5);
  vie(p, 1, 5);
  action(p, 0, 2);
  action(p, 1, 0);
  printf("\n");

  printf("    Deuxième print des statistiques Premier perso :\n");
  print_stats(p, 0);
  printf("    Deuxième print des statistiques Deuxième perso :\n");
  print_stats(p, 1);
  printf("\n");

  free(p);
}
