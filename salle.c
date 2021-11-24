#include <stdlib.h>
#include <stdio.h>

#include "salle.h"





void action_salle(salle_t**  pl,Perso* joueur,int tour_perso){
    int x=joueur->x;
    int y=joueur->y;
    int a,b;
    char type;
        switch (pl[y][x].type) {
            case 'S':
              salle_soin(joueur,tour_perso);
            break;
            case 'D':
                salle_poison(joueur,tour_perso);
            break;
    }
}

void modif_visible_et_etat(salle_t** plateau,int x, int y){

    //Si la salle n'est pas visible, on la met en visible
    if (plateau[y][x].visible == 0){
        if(plateau){
                plateau[y][x].state = 1;
                plateau[y][x].pres= 1;
            }

        plateau[y][x].visible = 1; //On rend la salle visible après pour que la boucle ne puisse trouver que l'autre salle tunnel, si elle est visible
    }
}



void salle_soin(Perso* perso,int tour_perso){
    perso[tour_perso].etat=1;
    perso->pv=+10;
    
    
}

void Salle_virus(Perso* perso,int tour_perso){
    perso[tour_perso].etat=0;
    perso->pv--;
}

void Salle_Arme(Perso*,Arme )