#ifndef affichage
#define affichage

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




typedef struct
{
    int h, w;
}Dimensions;

typedef struct 
{
	int x, y, l, c;
}CoordonneesSurface;

typedef CoordonneesSurface CoordonneesPlateau;

SDL_Surface* Afficher_Plateau(char** grille, int dimX, int dimY, Uint32 initflags);
void Afficher_Pion(CoordonneesSurface p, char joueur, SDL_Surface *ecran);
int Placer_Pion(CoordonneesSurface p, char joueur, SDL_Surface *ecran);
CoordonneesPlateau CoordSurfaceToPlateau(CoordonneesSurface c);
CoordonneesSurface CoordPlateauToSurface(CoordonneesPlateau p);






















#endif
