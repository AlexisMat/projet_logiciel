#ifndef hex
#define hex

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
 
#include <SDL.h>
#include <SDL_keysym.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

SDL_Surface* Afficher_Plateau(char** grille, int dimX, int dimY, Uint32 initflags);
void Afficher_Pion(int x, int y, char joueur, SDL_Surface *ecran);
int Placer_Pion(int x, int y, char joueur, int posPlatx, int posPlaty);






















#endif
