/**
  *\file actions.c
  *\author Nathan FAYNOT
  *\brief Ensemble des fonctions sur les actions des personnages
  */

#include "actions.h"
#include "salle.h"

void deplacement(salle_t** plateau,Perso *p,const char* direction, int i, int x, int y)
{
  if(p[i].mouv != 0)
  {

		//Cas où le joueur choisit droite
	if(p->x+1 < TAILLE_PL && *direction == 'd'){
		p->x = p->x + 1 ;
	}
	//Cas où le joueur choisit gauche
	else if(p->x-1 >= 0 && *direction == 'g'){
		p->x = p->x - 1 ;
	}
	//Cas où le joueur choisit bas
	else if (p->y+1 < TAILLE_PL && *direction == 'b'){
		p->y = p->y + 1 ;
	}
	//Cas où le joueur choisit haut
	else if (p->y-1 >= 0 && *direction == 'h'){
		p->y = p->y - 1 ;
	}
  p[i].mouv--;
 }
  else
  {
    printf("Vous ne pouvez pas vous deplacer, vous n'avez plus de point de mouvement.\n");
  }
	modif_visible_et_etat(plateau,p->x,p->y);
  action_salle(plateau,p,i);

}



void vie(Perso *p, int i, int v)
{
  p[i].pv += v;
}

void mouvement(Perso *p, int i)
{
  p[i].mouv = CONST_MOUV;
}

int randint(int a, int b)
{
    if (a >= b)
    {
      return a;
    }
    else
    {
      return rand()%(b-a)+a;
    }
}

void attaque(Perso *p, int att, int def)
{
  int deg = p[def].o.protection - p[att].o.degat; //Cacul des dégâts infligés
  if(deg > 0)
  {
    deg = 0;
  }
  printf("La vie du défenseur est maintenant à %d.\n",p[def].pv + deg);
  vie(p, def, deg);
}

void combat(Perso *p, int *fin)
{
  srand(time(NULL));  //Pour le randint de combat
  int r1 = 0, r2 = 0; //Initialise deux variables pour le randint à 0 pour rentrer dans la boucle.
  if(p[0].o.poids == p[1].o.poids)
  {
    do
    {
      printf("Un jet aléatoire entre 1 et 50 va être effectué.\nLe premier jet sera pour le joueur 1.\n\n");
      r1 = randint(1,50);  //Premier jet aléatoire.
      r2 = randint(1,50);  //Deuxième jet aléatoire.
      printf("Premier jet : %d.\nDeuxième jet : %d.\n\n",r1, r2);
      if(r1 == r2)  //Si ils sont égaux, on recommence.
      {
        printf("Les deux jets étant égaux, on relance deux nouveaux jets.\n");
      }
    } while(r1 == r2);  //La boucle s'arrête lorsque le tour d'un joueur est "décidé".
  }
  if(p[0].o.poids < p[1].o.poids || r1 > r2)  //On rentre dans la condition si c'est le tour du joueur 1
  {
    printf("Le joueur 1 attaque en premier.\n");
    attaque(p, 0, 1);
    if(estMort(p, 1) == 1)
    {
      printf("Bien joué au joueur %d pour avoir gagné la partie !\n",1);
      *fin = 0;
    }
    else  //Le joueur 1 n'a pas tué le joueur 2.
    {
      printf("Au tour du joueur 2 d'attaquer.\n");
      attaque(p, 1, 0);
      if(estMort(p, 0) == 1)
      {
        printf("Bien joué au joueur %d pour avoir gagné la partie !\n",2);
        *fin = 0;
      }
    }
  }
  else  //On rentre dans la condition si c'est le tour du joueur 2.
  {
    printf("Le joueur 2 attaque en premier.\n");
    attaque(p, 1, 0);
    if(estMort(p, 0) == 1)
    {
      printf("Bien joué au joueur %d pour avoir gagné la partie !\n",2);
      *fin = 0;
    }
    else  //Le joueur 2 n'a pas tué le joueur 1.
    {
      printf("Au tour du joueur 1 d'attaquer.\n");
      attaque(p, 0, 1);
      if(estMort(p, 1) == 1)
      {
        printf("Bien joué au joueur %d pour avoir gagné la partie !\n",1);
        *fin = 0;
      }
    }
  }
}
