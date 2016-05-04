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




int main(int argc, char *argv[])
{
	int joueur;
	char plateau [TAILLE_MAX][TAILLE_MAX];
	init_plateau(plateau);
    char couleurJoueur;
    PileCoup dernierCoup;
    dernierCoup.c2=-1;
    dernierCoup.c1=-1;
    Uint32 background;
	joueur = init_joueur();
    
    CoordonneesPlateau cp;
    if(joueur==1)couleurJoueur='B';
    else couleurJoueur='R';



    Uint32 initflags = SDL_INIT_VIDEO; //| SDL_DOUBLEBUF;  /* See documentation for details */
    /* Initialize the SDL library */
    if ( SDL_Init(initflags) < 0 )
    {
        fprintf(stderr, "N'arrive pas a` initialiser la SDL : %s\n", SDL_GetError());
        exit(1);
    }

    TTF_Init();

    //Initialisation et affichage du plateau
    SDL_Surface *ecran=Afficher_Plateau(plateau, WINHI, WINWI, initflags);
    background = SDL_MapRGB(ecran->format,51,51,102);
    Afficher_joueur(couleurJoueur, background, initflags, ecran);
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
                        c.x=clicX;
                        c.y=clicY;
                        switch(position_Clique(c))
                        {
                            case NOUVEAU_JEU:
                                init_plateau(plateau);
                                joueur = init_joueur();
    
                                CoordonneesPlateau cp;
                                if(joueur==1)couleurJoueur='B';
                                else couleurJoueur='R';
                                ecran=Afficher_Plateau(plateau, WINHI, WINWI, initflags);
                                Afficher_joueur(couleurJoueur, background, initflags, ecran);
                                dernierCoup.c1=-1;
                                dernierCoup.c2=-1;
                                
                                break;

                            case SAUVEGARDER:
                                /*FONCTION POUR SAUVEGARDER ICI : */

                                /*FIN*/
                                break;

                            case CHARGER:
                                /*FONCTION POUR CHARGER ICI : */

                                /*FIN*/
                                break;

                            case QUITTER:
                                /*EST-CE QU'ON SAUVEGARDE ? OUI ? NON ? */
                                continuer = false;
                                break;

                            case UNDO:
                                /*FONCTION POUR ANNULER LE DERNIER COUP ICI : */
                                if(dernierCoup.c2!=-1)
                                {
                                    undo(dernierCoup, plateau);
                                    Afficher_Plateau(plateau, WINHI, WINWI, initflags);
                                    Afficher_joueur(couleurJoueur, background, initflags, ecran);
                                    dernierCoup.c2=-1;
                                }
                                /*FIN*/
                                break;

                            case JOUER:
                                /*VERIFICATION DE LA VALIDITE DU COUP */

                                /*PION VALIDE, ON LE PLACE */
                                if(!Placer_Pion(c, couleurJoueur, ecran))
                                {
                                    /*AFFECTION DANS LE TABLEAU REPRESENTATIF DE LA GRILLE */
                                    cp=CoordSurfaceToPlateau(c);
                                    maj_plateau(plateau, cp.l , cp.c, couleurJoueur);
                                    /*ON STOCK LE DERNIER COUP DANS LA VARIABLE DERNIER COUP */
                                    if(dernierCoup.c2=-1)
                                    {
                                        dernierCoup.c2=cp.c;
                                        dernierCoup.l2=cp.l;
                                        dernierCoup.joueur2=couleurJoueur;
                                    }
                                    else
                                    {
                                        dernierCoup.c1=dernierCoup.c2;
                                        dernierCoup.l1=dernierCoup.l2;
                                        dernierCoup.joueur1=dernierCoup.joueur2;
                                        dernierCoup.c2=cp.c;
                                        dernierCoup.l2=cp.l;
                                        dernierCoup.joueur2=couleurJoueur;
                                    }
                                    /*TABLEAU UP*/
                                    /*ON CHANGE DE TOUR */
                                    if(couleurJoueur!='B')couleurJoueur='B';
                                    else couleurJoueur='R';
                                    Afficher_joueur(couleurJoueur, background, initflags, ecran);
                                }
                                



                        }
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
                    /*UTILISER LA FONCTION SAUVEGARDER AVANT*/
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