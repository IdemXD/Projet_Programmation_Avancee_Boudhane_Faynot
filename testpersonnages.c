#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "personnages.h"

int main()
{
  Perso p;
  creer_perso(&p,5,4);
  printf("%d, %d\n",p.x, p.y);
}
