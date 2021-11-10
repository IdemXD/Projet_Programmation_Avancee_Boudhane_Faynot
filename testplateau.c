#include <stdio.h>
#include <stdlib.h>

#include "plateau.h"
#include "salle.h"

int main(int argc, char *argv[]){
    /* Mise en place du plateau */

	salle_t** pl = charger_plateau(preparation_chemin());

    /* Fonctions d'exposition detaillées des salles*/
    affichage_plateau_lettre(pl);
    printf("\n");

    affichage_plateau_coordonnees(pl);
    printf("\n");

	free_plateau(pl);
}