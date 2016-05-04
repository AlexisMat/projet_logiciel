#ifndef affichagehex
#define affichagehex

#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "regle.h"



#define PI 3.14159265
 
#define WINHI 600 // window height
#define WINWI 800 // window width
#define PLATHI 300 // hauteur du plateau
#define PLATWI 340 //largement du plateau
#define HIHEX 30 //hauteur d'un hexagone
#define WIHEX 30 //largeur d'un hexagone

#define NOUVEAU_JEU 1
#define SAUVEGARDER 2
#define CHARGER 3
#define QUITTER 4
#define UNDO 5
#define JOUER 6


typedef struct
{
    int h, w;
}Dimensions;

typedef struct 
{
	int x, y, l, c;
	char joueur;
}CoordonneesSurface;

typedef CoordonneesSurface CoordonneesPlateau;

void Afficher_joueur(char joueur, Uint32 couleur, Uint32 initflags, SDL_Surface *ecran);

/*permet de retourner en fonction des coordonnees dans l'ecran la fonctionnalite du jeu a utiliser*/
int position_Clique(CoordonneesSurface c);

/*permet d'afficher le texte choisi dans char* texte*/
void Afficher_Texte(int posx, int posy, int taille, char* texte, SDL_Surface *ecran);


/* Permet d'afficher le bouton UNDO en jeu */
void Afficher_Bouton(int posx, int posy, char* bouton, Uint32 couleur, Uint32 initflags, SDL_Surface *ecran);

SDL_Surface* Afficher_Plateau(char (*grille)[TAILLE_MAX], int dimX, int dimY, Uint32 initflags);
void Afficher_Pion(CoordonneesSurface p, char joueur, SDL_Surface *ecran);
int Placer_Pion(CoordonneesSurface p, char joueur, SDL_Surface *ecran);
CoordonneesPlateau CoordSurfaceToPlateau(CoordonneesSurface c);
CoordonneesSurface CoordPlateauToSurface(CoordonneesPlateau p);



#endif
