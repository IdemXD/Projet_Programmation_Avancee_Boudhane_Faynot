
#ifndef FONCTIONSSDL_H
#define FONCTIONSSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "constantes.h"
#include "actions.h"
#include "plateau.h"

struct textures_s{

	SDL_Texture * fond;/*!<Texture du fond de l'écran */
};

typedef struct textures_s ressources;

/**
	* \brief Initialise les bibliothèques SDL utilisées
*/
void init_sdl();

/**
	* \brief Charge les textures
	* \param textures l'ensemble des textures
	* \param renderer Surface de l'écran de jeu
*/
void init_textures(ressources * textures, SDL_Renderer* renderer);

/**
	* \brief Libère l'ensemble des textures utilisées
	* \param textures l'ensemble des textures
*/
void liberer_textures(ressources * textures);


/**
	* \brief Libère une texture
	* \param texture la texture a libéré
*/
void liberer_texture(SDL_Texture * texture);


/**
	* \brief Crée une texture à partir d'une image
	* \param nomFichier Chemin vers l'image qu'on veut importer
	* \param renderer Surface de l'écran de jeu
	* \return la texture de l'image
*/
SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer);

/**
	* \brief Crée une texture à partir d'une image en appliquant une transparence
	* \param nomFichier Chemin vers l'image qu'on veut importer
	* \param renderer Surface de l'écran de jeu
	* \param r Valeur de rouge de la couleur de transparence (entre 0 et 255)
	* \param g Valeur de vert de la couleur de transparence (entre 0 et 255)
	* \param b Valeur de bleu de la couleur de transparence (entre 0 et 255)
	* \return la texture de l'image
*/
SDL_Texture * charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b) ;


/**
	* \brief Affiche le sprite d'un personnage
	* \param renderer Surface de l'écran de jeu
	* \param perso Sprite du personnage
	* \param donnees_perso Informations sur le personnage
	* \param i numéro du personnage
*/
void affiche_joueur(SDL_Renderer* renderer,SDL_Texture * perso,Perso donnees_perso,int i);

/**
	* \brief Affiche l'image correspondante à une salle
	* \param renderer Surface de l'écran du joueur
	* \param image_salle Texture de l'image que l'on veut afficher
	* \param salle Salle que l'on veut afficher
*/
void affiche_salle(SDL_Renderer* renderer, SDL_Texture* image_salle, salle_t salle);

/**
	* \brief Renvoie les coordonnées du sprite d'une salle
	* \param salle Salle dont on veut le sprite
	* \return la position (les coordonnées) de la texture de la salle dans l'image de départ
*/

int * texture_salle (salle_t salle);

/**
    * \brief Affiche le plateau sur l'ecran de jeu
    * \param renderer Surface de l'écran de joueur
    * \param texture_salles Ensemble des images correspondants aux salles
    * \param pl Tableau 2D representant le plateau
*/
void affichage_plateau(SDL_Renderer* renderer, ressources texture_salles, salle_t** pl);

#endif
