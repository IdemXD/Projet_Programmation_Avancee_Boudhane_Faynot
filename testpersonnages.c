#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "personnages.h"

int main()
{
  Perso *p = creer_perso();
  printf("%d, %d\n",p[0].x, p[0].y);
  printf("%d, %d\n",p[1].x, p[1].y);

  charger_perso(p);

  print_pv_action(p[0].nb_action, p[0].pv);
  print_pv_action(p[1].nb_action, p[1].pv);

  free(p);
}
