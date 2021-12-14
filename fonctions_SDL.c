
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>



#include "fonctions_SDL.h"

void init_sdl(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	// Initialisation de la SDL
	{
		printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
		SDL_Quit();
		exit(0);
	}

	if(TTF_Init()==-1) {
    	printf("TTF_Init: %s\n", TTF_GetError());
	}
}


SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer){

	// Chargement d' une image
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	surface = SDL_LoadBMP(nomfichier) ;
	if (surface == NULL){
		printf ("Erreur de chargement de l'image BMP : %s",SDL_GetError());
		return NULL;
	}
	// Conversion de la surface de l’image au format texture avant de l’appliquer
	texture = SDL_CreateTextureFromSurface(renderer,surface) ;
	SDL_FreeSurface(surface);

	if (texture == NULL){
		printf ("Erreur lors de la creation de la texture à partir d'une surface : %s",SDL_GetError());
		return NULL;
	}
	return texture;
}

TTF_Font* charger_police (const char* chemin_police){
	TTF_Font* police = NULL;

	police = TTF_OpenFont(chemin_police,20);

	if(police == NULL){
        printf("Erreur pendant le chargement de la police: %s\n", SDL_GetError());
    }

	return police;
}

SDL_Texture * charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b){
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;

	surface = SDL_LoadBMP(nomfichier) ;

	if (surface == NULL){
		printf ("Erreur de chargement de l'image BMP : %s\n",SDL_GetError());
		return NULL;
	}

	// Définition de la couleur transparente d'une surface
	if (0!=SDL_SetColorKey(surface,SDL_TRUE,SDL_MapRGB(surface->format,r,g,b))){
		printf("Erreur de la transparence : %s\n",SDL_GetError());
		return NULL;
	}

	texture = SDL_CreateTextureFromSurface(renderer,surface) ;
	SDL_FreeSurface(surface);

	if (texture == NULL){
		printf ("Erreur lors de la creation de la texture à partir d'une surface : %s\n",SDL_GetError());
		return NULL;
	}
	return texture;


}

void affiche_message (SDL_Renderer* renderer,TTF_Font *police,const char *message){
	appliquer_texte(renderer,600,100,300,30,message,police);
}

void affiche_tours(SDL_Renderer* renderer,TTF_Font *police, int tour_perso, int tour_action, char action){
	char texte [21];
	sprintf(texte,"Tour du personnage %d",tour_perso+1);
	appliquer_texte(renderer,601,10,295,32,texte,police);

	sprintf(texte,"Action numero %d %c",tour_action+1,action);
	appliquer_texte(renderer,640,50,230,30,texte,police);
}

void appliquer_texte(SDL_Renderer *renderer,int x, int y, int w, int h, const char * message, TTF_Font *police){
    SDL_Color color = { 0, 0, 0 };

    SDL_Surface* surface = TTF_RenderText_Solid(police, message, color);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dstrect2 = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect2);
    liberer_texture(texture);

}

void init_textures(ressources * textures,SDL_Renderer* renderer){

	textures->sprites_menu=charger_image("Ressources/sprites_menu.bmp", renderer);

	textures->fond = charger_image("Ressources/background.bmp", renderer );

 	textures->sprites_salles = charger_image_transparente("Ressources/sprites_salles.bmp", renderer,255,0,255);

 	textures->sprites_elements = charger_image_transparente("Ressources/sprites_elements.bmp", renderer,255,0,255);

 	textures->police = charger_police("Ressources/KeepCalm.ttf");
}

void liberer_textures(ressources * textures){
    liberer_texture(textures->sprites_menu);
	liberer_texture(textures->fond);
	liberer_texture(textures->sprites_salles);
	liberer_texture(textures->sprites_elements);
	TTF_CloseFont(textures->police);
}

void liberer_texture(SDL_Texture * texture){
	if (texture != NULL){
		SDL_DestroyTexture(texture);
	}
}

void affiche_joueur(SDL_Renderer* renderer,SDL_Texture * perso, Perso donnees_perso, int i){

	int persoW;
	int persoH;

	//On demande la largeur et hauteur de l'image
	SDL_QueryTexture(perso, NULL, NULL, &persoW,&persoH);

	persoW = persoW/5;
	persoH = persoH/2;

	SDL_Rect SrcR = {i*persoW,0,persoW,persoH};
	int lig = i/2, col = i%2;
	SDL_Rect DestR = {persoW*donnees_perso.x - persoW/4 + col*60 + 30, persoH*donnees_perso.y - persoH/4 + lig*60 +30,persoW/2,persoH/2};
	SDL_RenderCopy(renderer,perso, &SrcR, &DestR);
}




int * texture_salle (salle_t salle){


	int num_s = 0; //numéro du sprite de la salle sur le fichier des sprites
	if (salle.visible == 1) {
        // Selon le char definissant le type de la salle, on associe la texture correspondante

    	while (salle.type != LETTRES_SALLES[num_s]){
    		num_s++;
    	}

    } else {
        // La salle est cachée, on ne sait pas ce qu'il se trouve à cet endroit.
        num_s = 17;
   	}
   	int* coord = malloc(2* sizeof(int));
   	coord[0] = num_s%5;
   	coord[1] = num_s/5;
   	return coord;

}

void affiche_salle(SDL_Renderer* renderer, SDL_Texture * image_salles, salle_t salle){

	int salleW;
	int salleH;


	//On demande la largeur et hauteur de l'image
	SDL_QueryTexture(image_salles, NULL, NULL, &salleW, &salleH);

	salleW = salleW/5;
	salleH = salleH/4;

	int * coord = texture_salle(salle);
	SDL_Rect SrcR = {coord[0]*salleW, coord[1]*salleH, salleW, salleH};
	SDL_Rect DestR = {salle.x*salleW, salle.y*salleH, salleW, salleH};
	free(coord);
	SDL_RenderCopy(renderer, image_salles, &SrcR, &DestR);

}

void affichage_plateau(SDL_Renderer* renderer, ressources texture_salles, salle_t** pl)
{
    // On parcourt le plateau case par case
    for(int i = 0; i < TAILLE_PL; i++)
    {
        for (int j = 0; j < TAILLE_PL; j++)
        {
            affiche_salle(renderer, texture_salles.sprites_salles, pl[i][j]);
        }
    }
}



int clic_menu(SDL_Rect mot,int x_souris, int y_souris){
	return mot.x<x_souris && (mot.x + mot.w)>x_souris && mot.y<y_souris && (mot.y + mot.h)>y_souris;
}