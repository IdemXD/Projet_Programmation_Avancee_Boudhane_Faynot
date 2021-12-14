#include <stdlib.h>
#include <stdio.h>

#include "salle.h"
#include "pile.h"





void action_salle(salle_t**  pl,Perso* joueur,int tour_perso){
    int x=joueur->x;
    int y=joueur->y;
    char type;
    int a,b;
    Pile* pile =initialiser();
    creer_pile(pile);
        switch (pl[y][x].type) {
            case 'S':
              salle_soin(pl,joueur,tour_perso,x,y);
            break;
            case 'P':
                salle_poison(joueur,tour_perso);
            break;
            case 'E':
               salle_arme(EPEE,joueur);
            break;
            case 'H':
               salle_arme(HACHE,joueur);
            break;
            case 'D':
               salle_arme(DAGUE,joueur);
            break;
            case 'L':
                salle_arme(LANCE,joueur);
            case 'B':
                salle_arme(BOUCLIER,joueur);
            break;
            case 'Z':
                type=depiler(pile);
                Salle_surprise(pl,joueur,type,tour_perso,a,b);
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



void salle_soin(salle_t** pl,Perso* perso,int tour_perso,int x,int y){
    if(perso[tour_perso].etat=1){
    perso[tour_perso].etat=1;
    perso->pv=+10;
    }
    switch (pl[x][y].cpt_use)
    {
    case '1':
        perso->pv=+10;
        break;
    case '2':
        perso->pv=+7;
        break;
    case '3':
        perso->pv=+4;
        break;
    
    default:
        if(pl[x][y].cpt_use>3){
            perso->pv=+2;
        }
        break;
    }
    
    
}

void salle_poison(Perso* perso,int tour_perso){
    perso[tour_perso].etat=0;
    perso->pv--;
}


void salle_arme(Arme a,Perso* joueur){
    joueur->o=init_objet(a);
}

void Cherche_salle_specifique(salle_t** pl ,Perso*  persos,int tour_perso ,char salle, int* a , int* b) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (pl[i][j].type == salle && persos->x == pl[i][j].x &&
                persos->y == pl[i][j].y) {
                *a = i;
                *b = j;
            }
        }
    }
}

void Salle_surprise(salle_t **pl,Perso* persos,char salle_Depile,int tour_perso,int a,int b){
    Cherche_salle_specifique(pl,persos,tour_perso,'Z',&a,&b);
    pl[a][b].type=salle_Depile;
}