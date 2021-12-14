#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "actions.h"
#include "fonctions_SDL.h"
#include "data.h"


int main(int argc, char *argv[]){
	SDL_Window* fenetre;
	// Déclaration de la fenêtre
	SDL_Event evenements;
	// Événements liés à la fenêtre
	SDL_Renderer* ecran;

	ressources textures;

	data_t* data = NULL;

	int jouer = 0;

	init_sdl();
	// Créer la fenêtre
	fenetre = SDL_CreateWindow("Jeu", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_RESIZABLE);

	if(fenetre == NULL)
		// En cas d’erreur
	{
		printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
		SDL_Quit();
		exit(0);
	}
	// Mettre en place un contexte de rendu de l’écran
	ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

	init_textures(&textures,ecran);
	affichage_menu(&jouer,&evenements,ecran,textures,&data);

	int x_curseur = -1, y_curseur = -1;
	// Boucle principale
	while(jouer && !data->terminer)
	{
		refresh_game(ecran, textures, data);

		while( SDL_PollEvent( &evenements ) )

			switch(evenements.type)
			{
				case SDL_QUIT:
					data->terminer = 1;
					break;
				case SDL_KEYDOWN:
					switch(evenements.key.keysym.sym)
					{
						case SDLK_ESCAPE:
						case SDLK_q:
							data->terminer = 1;
							break;


						case SDLK_DOWN:
									data->active_direction = 'b';
									deplacement(data->joueur,0,0,2);
						break;

						case SDLK_UP:
						
								data->active_direction = 'h';
							break;

						case SDLK_LEFT:		
								data->active_direction = 'g';
							break;

						case SDLK_RIGHT:
								data->active_direction = 'd';
							break;


					}
					break;
				case SDL_MOUSEMOTION:
					break;
				case SDL_MOUSEBUTTONDOWN:
                    if(data->active_direction_salle==2 && data->move==2 ) {
                        int x = -1, y = -1;
                        data->active_direction_salle = 0;
                        data->move=0;
                    }
                    if(data->active_direction_salle==3 && data->move==3 ) {
                        int x = -1, y = -1;
                
                            data->affiche_message = 0;
                            data->active_direction_salle = 0;
                            data->move=0;
                    }
                    if(data->active_direction_salle==4 && data->move==4 ) {
                        int x = -1, y = -1;
                        data->affiche_message = 0;
                        data->active_direction_salle = 0;
                        data->move=0;
                    }


					if (data->etape == 1){

					}


			}

		if (data->trouve){

			//data->joueur[data->tour_perso].actions[data->tour_action] = data->nb_action;//On enregistre le numéro de l'action choisie
            data->affiche_message = 1;

			//change_perso(data->actions,data->joueur,&(data->tour_action),&(data->tour_perso),&(data->etape),&(data->nb_action),&(data->affiche_message),data->nb_personnages,data->type_de_jeu);
			data->trouve = 0;
		}
		verifie_fin_du_jeu(&data->terminer,data->joueur,data->salles,data->type_de_jeu,data->nb_personnages);

		SDL_RenderPresent(ecran);

	}
    if (jouer && data->terminer == 2){
        appliquer_texte(ecran,325, 145, 295, 50, "Bravo!", textures.police);
        SDL_Delay(1000);
    }
	clean_game(fenetre, ecran, &textures, data);
	return 0;
}
