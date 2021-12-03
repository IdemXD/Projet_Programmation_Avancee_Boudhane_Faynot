#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "actions.h"
#include "fonctions_SDL.h"



int main(int argc, char *argv[]){
	SDL_Window* fenetre;
	// Déclaration de la fenêtre
	SDL_Event evenements;
	// Événements liés à la fenêtre
	SDL_Renderer* ecran;

	ressources textures;



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


	return 0;
}
