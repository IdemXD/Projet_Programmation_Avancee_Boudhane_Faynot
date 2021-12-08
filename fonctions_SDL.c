#include <SDL2/SDL.h>



#include "fonctions_SDL.h"

void init_sdl(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	// Initialisation de la SDL
	{
		printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
		SDL_Quit();
		exit(0);
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

void init_textures(ressources * textures,SDL_Renderer* renderer){

	textures->fond = charger_image("ressources/background.bmp", renderer );
}


void liberer_textures(ressources * textures){
	liberer_texture(textures->fond);
}

void liberer_texture(SDL_Texture * texture){
	if (texture != NULL){
		SDL_DestroyTexture(texture);
	}
}

/*
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
*/


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

void affiche_message_actions(int peut_afficher,int num_action,SDL_Renderer* ecran,TTF_Font* police, salle_t** salles){
	if (peut_afficher == 0) {
        if (num_action == 0) {
        	if (plateau_est_visible(salles)){
    			appliquer_texte(ecran,600,200,300,30,"Action regarder impossible",police);
        	} else {
        		affiche_message(ecran, police, "Cliquez sur la case que vous voulez voir");
        	}

        } else {
            if (num_action > 0 && num_action < 4)
                affiche_message(ecran, police, "Choisissez une direction avec les fleches du clavier");
        }
    }
}

void affiche_texte_salle(SDL_Renderer* renderer,TTF_Font *police,salle_t salle){

	char texte[70] = "";
	char texte2[50] = "";
	char texte3[30] = "";

	switch (salle.type){
        case 'S':
            sprintf(texte,"Salle centrale");
            break;
        case 'R':
            sprintf(texte,"Regagnez votre liberte");
			sprintf(texte2,"en m'atteignant !");
            break;
        case 'E':
            sprintf(texte,"...");
            break;
        case 'V':
            sprintf(texte,"Une action Regarder gratuite");
            break;
        case 'D':
            sprintf(texte,"Ca va faire... boom !");
            break;
        case 'X':
            sprintf(texte,"Retour a la case depart");
            break;
		case 'T':
	        sprintf(texte,"Vous envoie a sa ");
			sprintf(texte2,"salle jumelle");
	        break;
        case 'C':
            sprintf(texte,"Trainer sur cette salle ");
			sprintf(texte2,"peut s'averer... mortel");
            break;
        case 'F':
            sprintf(texte,"On progresse moins vite ");
			sprintf(texte2,"quand il fait -35C");
            break;
        case 'M':
            sprintf(texte,"Vous envoie sur une ");
			sprintf(texte2,"salle non visible");
            break;
		case 'O':
			sprintf(texte,"Une action Controler gratuite");
			break;
		case 'N':
	        sprintf(texte,"Et si on eteignait ");
			sprintf(texte2,"les lumieres ?");
	        break;
		case 'P':
		    sprintf(texte,"Cette salle vous ");
			sprintf(texte2,"retiendera un bon moment.");
			sprintf(texte3,"Criminel.");
		    break;
		case 'Z':
			sprintf(texte,"Comme aux partiels, on ne ");
			sprintf(texte2,"sait jamais a quoi s'attendre");
			break;
		case 'Y':
			sprintf(texte,"Ce mirroir permet de copier");
			sprintf(texte2,"l'effet de votre salle preferee");
			break;
		case 'U':
			sprintf(texte,"Cette salle n'a pas bien ete");
			sprintf(texte2,"desinfectee... qui quelle ");
			sprintf(texte3,"maladie il s'y trouve.");
			break;
		case 'H':
			sprintf(texte,"Oh une infirmerie !");
			break;
    }

	appliquer_texte(renderer,601,160,295,40,texte,police);
	appliquer_texte(renderer,601,200,295,40,texte2,police);
	appliquer_texte(renderer,601,240,295,40,texte3,police);
}

int clic_menu(SDL_Rect mot,int x_souris, int y_souris){
	return mot.x<x_souris && (mot.x + mot.w)>x_souris && mot.y<y_souris && (mot.y + mot.h)>y_souris;
}