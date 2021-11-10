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

  free(p);
}
