#include <stdlib.h>
#include <stdio.h>
#include "salle.h"
#include "personnages.h"
#include "constantes.h"
#include "objet.h"

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


void Salle_épee(Perso* p,Objet ) {
   p->;

}
