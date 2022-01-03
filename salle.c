#include <stdlib.h>
#include <stdio.h>

#include "salle.h"
#include "pile.h"
#include "actions.h"




void action_salle(salle_t**  pl,Perso* joueur,int* tour_perso,int tour){
    int x=joueur->x;
    int y=joueur->y;
    char type;
    int a,b;
    Pile* pile =initialiser();
    creer_pile(pile);
        vie_poison(pl,&pl[y][x],joueur,tour_perso);
        Salle_combat(pl,joueur,tour);
        switch (pl[y][x].type) {
            case 'S':
              Salle_soin(pl,joueur,tour_perso,x,y);
            break;
            case 'P':
                Salle_poison(joueur,tour_perso);
            break;
            case 'E':
               Salle_arme(EPEE,joueur);
            break;
            case 'H':
               Salle_arme(HACHE,joueur);
            break;
            case 'D':
               Salle_arme(DAGUE,joueur);
            break;
            case 'L':
                Salle_arme(LANCE,joueur);
            case 'B':
                Salle_arme(BOUCLIER,joueur);
            break;
            case 'Z':
                type=depiler(pile);
                Salle_surprise(pl,joueur,type,tour_perso,a,b);
            break;
            case 'O':
                Salle_passage(pl,joueur);
            break;
            case 'F':
                combat(joueur);
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



void Salle_soin(salle_t** pl,Perso* perso,int* tour_perso,int x,int y){
    if(perso[*tour_perso].etat=1){
    perso[*tour_perso].etat=1;
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

void Salle_poison(Perso* perso,int* tour_perso){
    perso[*tour_perso].etat=0;
    perso->pv--;
    
}

void vie_poison(salle_t** pl,salle_t* salle,Perso* perso,int* tour_perso){
    if(pl[perso->y][perso->x].type!='S'&& perso[*tour_perso].etat==0){
        Salle_poison(perso,tour_perso);
        if(perso->pv==0){
            perso->state=0;
        }
    }
}

void Salle_arme(Arme a,Perso* joueur){
    joueur->o=init_objet(a);
}

void Cherche_salle_specifique(salle_t** pl ,Perso*  persos,int* tour_perso ,char salle, int* a , int* b) {
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

void Salle_surprise(salle_t **pl,Perso* persos,char salle_Depile,int* tour_perso,int a,int b){
    Cherche_salle_specifique(pl,persos,tour_perso,'Z',&a,&b);
    pl[a][b].type=salle_Depile;
}

void Salle_chaleur(Perso* perso,int* tour_perso){
    perso[*tour_perso].etat=0;
    perso->mouv--;
}

void Salle_passage(salle_t** pl,Perso* perso){  
    for (int i = 0 ; i<5 ; i++){
        for (int j =0 ; j<5 ; j++){
            if (pl[i][j].type == 'O' && perso->x != pl[i][j].x && perso->y != pl[i][j].y && pl[perso->y][perso->x].state){
                perso->x=j;
                perso->y=i;
            }
        }
    }

}


void Salle_combat(salle_t** pl, Perso* joueur,int tour){
    if(tour== 6 || tour==12 || tour==18){
    joueur[0].x=2;
    joueur[0].y=2;
    joueur[1].x=2;
    joueur[1].y=2;
    modif_visible_et_etat(pl,joueur[0].x,joueur[0].y);
    
}
}