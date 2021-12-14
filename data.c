#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "data.h"

data_t * init_data()
{
	// Allocation de la structure
	data_t* data = (data_t *) malloc (sizeof(data_t));

    // Preparation des variables d'interactions personnages / actions
	data->etape = 1; //etape 1 : choix de l'action
	data->active_direction = 'n'; // définit quel direction le joueur choisit
    data->active_direction_salle = 0;
    data->move=0;
    data->trouve = 0;
    data->terminer = 0;
	data->tour_perso = 0;
	data->joueur = NULL;
	return data;

}

void refresh_game(SDL_Renderer *ecran, ressources textures, data_t* data)
{
    SDL_RenderClear(ecran);
    SDL_RenderCopy(ecran, textures.fond, NULL, NULL);

    affichage_plateau(ecran,textures,data->salles);

    if (data->etape == 2 && plateau_est_visible(data->salles)){
    //On affiche un message lorsque le joueur a choisi regarder mais le plateau est visible en entier

        SDL_Delay(1000);
        data->affiche_message = 0;
        //change_action(data->actions,&(data->tour_action),&(data->tour_perso),&(data->etape),&(data->affiche_message),data->nb_personnages,data->joueur,data->type_de_jeu);
    }


    for (int i = 0; i<data->nb_personnages; i++){
    	if (data->joueur[i].state)
    		affiche_joueur(ecran,textures.sprites_elements,data->joueur[i],i);
    }

    for (int i = 0; i<CONST_MOUV; i++){


    }

}


void clean_game(SDL_Window *fenetre, SDL_Renderer *ecran, ressources *textures, data_t* data)
{
    if (data != NULL && data->salles != NULL){
        free_plateau(data->salles);
    }
    if (data != NULL && data->joueur != NULL){
        free_perso(data->joueur);
    }

    if (data != NULL){
        free(data);
    }
	liberer_textures(textures);
	TTF_Quit();

	SDL_DestroyRenderer(ecran);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
}

void verifie_fin_du_jeu(int* terminer,Perso* joueurs,salle_t** plateau,char type_de_jeu,int nb_personnage){
    if (type_de_jeu == 's' &&(!joueurs[0].state || !joueurs[1].state)){//Si le joueur joue en mode solo et qu'un des deux persos est mort
        *terminer = 1; //On sort de la boucle de jeu
    } else {
        int i = 0,est_vivant = 0;
        while(i < nb_personnage && !est_vivant){
            if (joueurs[i].state)
                est_vivant = 1;
            i++;
        }

        if (type_de_jeu == 'm' && !est_vivant){//si tous les joueurs ont perdu
            *terminer = 1; //On sort de la boucle de jeu
        }
    }
    int abs,ord;
    int i = 0,fini = 1;
    while(i < nb_personnage && fini){
        if (joueurs[i].x != abs || joueurs[i].y != ord)
            fini = 0;
        i++;
    }
    if (fini){
        *terminer = 2; //On sort de la boucle de jeu
    }

}

data_t* gestion_plateau(int num_plateau){
    data_t* data = init_data();
    char * nom_du_fichier = nom_du_plateau(num_plateau);
    data->salles = charger_plateau(nom_du_fichier);
    free(nom_du_fichier);
    return data;
}

void affichage_menu(int* jouer, SDL_Event* evenements,SDL_Renderer* ecran,ressources textures,data_t** data){
    int rester_dans_menu = 0;
    int numero_menu = 1;
    SDL_Rect Jouer={330,245,255,40};
    SDL_Rect Quitter={330,445,295,40};
    SDL_Rect rectMessage[2]={Jouer,Quitter};
    SDL_Rect Plateau_1={40,145,255,40};
	SDL_Rect rectPlateau[1]={Plateau_1};
    SDL_Rect Player_1={230,245,255,40};
    SDL_Rect rectPlayer[1] = {Player_1};
    SDL_Rect* rectTout[3] = {rectMessage,rectPlateau,rectPlayer};
    while (!rester_dans_menu){
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, textures.sprites_menu, NULL, NULL);
        appliquer_texte(ecran,325, 45, 295, 50, "Jeu", textures.police);
        appliquer_texte_menu(numero_menu,ecran,rectTout,textures);
	    while(SDL_PollEvent( evenements ))
            switch(evenements->type)
            {
                case SDL_QUIT:
                    rester_dans_menu = 1;
                    break;
                case SDL_KEYDOWN:
                    switch(evenements->key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            rester_dans_menu = 1;
                            break;
                    }
                	break;
                case SDL_MOUSEBUTTONDOWN:
                	trouve_selection_menu(evenements->button.x, evenements->button.y,&rester_dans_menu,&numero_menu,data,jouer,rectTout,textures.sprites_elements);
                   	break;
            }
        SDL_RenderPresent(ecran);
    }
}

void appliquer_texte_menu(int numero_menu,SDL_Renderer* ecran,SDL_Rect** rectMessages,ressources textures){

	if (numero_menu == 1){
        appliquer_texte(ecran,rectMessages[numero_menu-1][0].x, rectMessages[numero_menu-1][0].y,rectMessages[numero_menu-1][0].w,rectMessages[numero_menu-1][0].h, "Jouer", textures.police);
        appliquer_texte(ecran,rectMessages[numero_menu-1][1].x, rectMessages[numero_menu-1][1].y, rectMessages[numero_menu-1][1].w, rectMessages[numero_menu-1][1].h, "Quitter", textures.police);
    }
    if(numero_menu==2){

        appliquer_texte(ecran,rectMessages[numero_menu-1][0].x, rectMessages[numero_menu-1][0].y, rectMessages[numero_menu-1][0].w, rectMessages[numero_menu-1][0].h, "Plateau 1", textures.police);

    }
}

void choix_du_menu(int choix,int* rester_dans_menu, int* numero_menu){
    if(choix){ //Si le joueur choisit de quitter le menu
    	*rester_dans_menu = 1;
    } else {//Si il veut jouer
    	*numero_menu = *numero_menu + 1;
    }
}

SDL_Rect* recherche_rect_messages(int numero_menu, int* nb_choix,SDL_Rect** rectMessages){
	if (numero_menu == 1){
		*nb_choix = 2;
	}
	if (numero_menu == 2){
          *nb_choix = 5;
	}
	if (numero_menu == 3){
		*nb_choix = 4;
	}
	return rectMessages[numero_menu-1];
}

void trouve_selection_menu(int x_souris,int y_souris, int* rester_dans_menu,int* numero_menu,data_t** data,int * jouer, SDL_Rect** rectMessages,SDL_Texture* actions){
	int trouve = 0, choix = 0, nb_choix;
	SDL_Rect* rect = recherche_rect_messages(*numero_menu,&nb_choix,rectMessages);
	while (!trouve && choix<nb_choix){
		if (clic_menu(rect[choix],x_souris, y_souris)){//Si le joueur a cliqué sur un choix du menu
                
			
			if (*numero_menu == 2){//Si le joueur est dans le menu 2 (choix du plateau)
				*data = gestion_plateau(choix + 1);
                *numero_menu = *numero_menu + 1;
                (*data)->nb_personnages = 2;

				(*data)->joueur = creer_perso((*data)->nb_personnages);

                *jouer = 1;//On sort du menu et on peut jouer
        		*rester_dans_menu = 1;
			}
			if (*numero_menu == 1){//Si le joueur est dans le menu 1 (jouer/quitter)
				choix_du_menu(choix, rester_dans_menu, numero_menu);
			}
			trouve++;

		} else {
			choix++;
		}
	}
}
