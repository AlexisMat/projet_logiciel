#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "IA.h"
#include "log.h"




int main(int argc, char *argv[])
{
	int joueur;
	char plateau [TAILLE_MAX][TAILLE_MAX];
	init_plateau(plateau);
	joueur = init_joueur();
	printf("Joueur : %d\n",joueur);



    Uint32 initflags = SDL_INIT_VIDEO; //| SDL_DOUBLEBUF;  /* See documentation for details */
    /* Initialize the SDL library */
    if ( SDL_Init(initflags) < 0 )
    {
        fprintf(stderr, "N'arrive pas a` initialiser la SDL : %s\n", SDL_GetError());
        exit(1);
    }

    TTF_Init();

    //Initialisation et affichage du plateau
    SDL_Surface *ecran=Afficher_Plateau(NULL, WINHI, WINWI, initflags);
    SDL_Flip(ecran);
 
 // boucle des évènements
   
    bool continuer; // pour la boucle principale des évènements
    continuer = true; // un furieux du c ferait plutôt une boucle infinie. Je préfère rester correct.
    SDLKey key_pressed ;
    SDL_Event event; // aussi
    while (continuer)
    {
        while ( SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                // case SDL_MOUSEMOTION:
                //     printf("Ça bouge\n"); // sans intérêt, c'est juste pour montrer
                //     break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {   
                        int clicX = event.motion.x;
                        int clicY = event.motion.y;
                        CoordonneesSurface c;
                        CoordonneesPlateau p;
                        c.x=clicX;
                        c.y=clicY;
                        Placer_Pion(c, 'B', ecran);
                    }
                    break;
                case SDL_KEYDOWN:
                    key_pressed = event.key.keysym.sym; // on récupère la touche
                    switch (key_pressed)
                    {
                    case SDLK_ESCAPE: /* Esc keypress quits the app... */
                        continuer = false;
                        break;
                    case SDLK_LEFT:
                        printf("left +1\n"); // par exemple
                        break;
                    case SDLK_RIGHT:
                        printf("right +1\n"); 
                        break;
                    case SDLK_UP:
                        printf("up +1\n");
                        break;
                    case SDLK_DOWN:
                        printf("down +1\n");
                        break;
                    }
                    break;
                case SDL_QUIT:
                    continuer = false;
                    break;
                default:
                    break;
            }
        }
        // refresh screen
        // mettre ici tous les blit utiles s'il y a des changements dans les surfaces, board, nouveaux pions
        SDL_Flip(ecran); //maj des surfaces pour affichage
    }
    //
    SDL_FreeSurface(ecran);
    TTF_Quit();
    SDL_Quit();
    return(0);
}