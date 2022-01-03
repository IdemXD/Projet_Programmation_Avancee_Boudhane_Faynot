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
	int tour=1;
	// Boucle principale
	while(!data->terminer)
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
									affichage_plateau_lettre(data->salles);
									deplacement(data->salles,data->joueur,&data->active_direction,&data->tour_perso,tour);
									print_stats(data->joueur,data->tour_perso);
									printf("%d 1er down\n",data->tour_perso);
									tour++;
								
									
						break;

						case SDLK_UP:

								data->active_direction = 'h';
								affichage_plateau_lettre(data->salles);
								deplacement(data->salles,data->joueur,&data->active_direction,&data->tour_perso,tour);
								print_stats(data->joueur,data->tour_perso);
								printf("%d 1er up\n",data->tour_perso);
								tour++;
						
								
							break;

						case SDLK_LEFT:
								data->active_direction = 'g';
								affichage_plateau_lettre(data->salles);
								deplacement(data->salles,data->joueur,&data->active_direction,&data->tour_perso,tour);
								print_stats(data->joueur,data->tour_perso);
								printf("%d 1er left\n",data->tour_perso);
								tour++;
								
							break;

						case SDLK_RIGHT:
								data->active_direction = 'd';
								affichage_plateau_lettre(data->salles);
								deplacement(data->salles,data->joueur,&data->active_direction,&data->tour_perso,tour);
								print_stats(data->joueur,data->tour_perso);
								printf("%d 1er right\n",data->tour_perso);
								tour++;
								
							break;


					}
					break;
				
			}

		
		
		verifie_fin_du_jeu(&data->terminer,data->joueur,data->salles);
		SDL_RenderPresent(ecran);

	}
	clean_game(fenetre, ecran, &textures, data);
	return 0;
}
