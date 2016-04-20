#include "affichage_hex.h"

 
#define WINHI 600 // window height
#define WINWI 800 // window width
#define PLATHI 300 // hauteur du plateau
#define PLATWI 340 //largement du plateau

typedef struct
{
    int h, w;
}Dimensions;



SDL_Surface* Afficher_Plateau(char** grille, int dimX, int dimY, Uint32 initflags)
{
    
    SDL_Surface *ecran, *rectangle, *board, *texte1; // quelques surfaces

    Dimensions fenetre; // main window
   
    fenetre.h = dimX;  // en pixels
    fenetre.w = dimY;   

    Uint8  video_bpp = 32; // 32 bits de couleur

    Uint32 videoflags = SDL_HWSURFACE; // utiliser la mémoire vidéo

    Uint32 vert, rouge; // des variables pour des couleurs   
 
    /* Set video mode */
    ecran = SDL_SetVideoMode(fenetre.w, fenetre.h, video_bpp, videoflags); // surface principale

    if (ecran == NULL)
    {
        fprintf(stderr, "N'arrive pas a` etablir mode video%dx%dx%d : %s\n", fenetre.w, fenetre.h, video_bpp, SDL_GetError());
        SDL_Quit();
        exit(2);
    }

    vert = SDL_MapRGB(ecran->format,0,128,0); // c'est du vert
    rouge = SDL_MapRGB(ecran->format,255,0,0); // c'est du rouge

    SDL_FillRect(ecran,NULL,vert); // de la couleur dans le fond de la fenêtre principale
    SDL_WM_SetCaption("Jeu de Hex", NULL); // legende de la fenêtre

    // Une autre surface avec du texte

    
    TTF_Font *fontMenu = TTF_OpenFont("CAC-Champagne/cac_champagne.ttf",60); // charger une fonte (un peu moche)
    SDL_Color fontBlack = {0,0,0};
    texte1 = TTF_RenderText_Blended(fontMenu,"Hello guys !",fontBlack);

    // encore une surface
    rectangle = SDL_CreateRGBSurface(initflags,225,80,video_bpp,0,0,0,0); // une autre surface pour inclure dans l'autre
    SDL_FillRect(rectangle,NULL,rouge); // un fond rouge

    // position des surfaces
    SDL_Rect posRect, posTexte1;
    posRect.x = 20;
    posRect.y = 80;

    posTexte1.x = 25;
    posTexte1.y = 85;

    SDL_BlitSurface(rectangle,NULL,ecran,&posRect); // on associe avec la fenêtre principale
    SDL_BlitSurface(texte1,NULL,ecran,&posTexte1); // idem pour superposer avec la précédente

    // Affichage du plateau de jeu
    board = IMG_Load("Images/hex.png");    // plateau de jeu la taille en pixels est celle de l'image
    SDL_Rect posBoard;                     // sa position
    posBoard.x = 280;
    posBoard.y = 100;
    SDL_BlitSurface(board,NULL,ecran,&posBoard); // on l'associe avec la surface principale

    /* Clean up the SDL library */
    SDL_FreeSurface(rectangle);
    SDL_FreeSurface(board);
    TTF_CloseFont(fontMenu);
    SDL_FreeSurface(texte1);

    return ecran;
}

void Afficher_Pion(int x, int y, char joueur, SDL_Surface *ecran)
{
    // affichage du pion bleu
    SDL_Surface *pion;
    if(joueur=='R') pion = IMG_Load("Images/button-red22.png");
    else pion = IMG_Load("Images/button-blue22.png");
    SDL_Rect posPion;               
    posPion.x = x;
    posPion.y = y;
    SDL_BlitSurface(pion,NULL,ecran,&posPion);
    SDL_FreeSurface(pion);
    SDL_Flip(ecran);
}

int Placer_Pion(int x, int y, char joueur, int posPlatx, int posPlaty)
{
    // Verifier si les coordonnées se situe bien dans le plateau
    int i, j;

    for(i=0; i<11;i++)
    {
        for(j=0; j<11;i++)
        {
            
        }
    }
}
 
int main(int argc, char *argv[])
{
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
    // Affichege du pion rouge
    Afficher_Pion(543, 273, 'R', ecran);
    // affichage du pion bleu
    Afficher_Pion(377, 149, 'B', ecran);

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
                        Afficher_Pion(clicX, clicY, 'B', ecran);
                        printf("X=%d Y=%d\n",clicX,clicY); // on récupère les coordonnées du clic
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
