#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


#include "affichage_hex.h"



void Afficher_Bouton(int posx, int posy, char* bouton,  Uint32 initflags, SDL_Surface *ecran)
{
    SDL_Surface *surface_bouton, *texte1;
    SDL_Rect posTexte1, position;
    position.x=posx;
    posTexte1.x=position.x+5;
    posTexte1.y=position.y+5;


    Uint8  video_bpp = 32; // 32 bits de couleur
    Uint32 rouge;
    rouge = SDL_MapRGB(ecran->format,255,0,0); // c'est du rouge
    
    TTF_Font *fontsurface_bouton = TTF_OpenFont("CAC-Champagne/cac_champagne.ttf",40); 
    SDL_Color fontBlack = {0,0,0};
    texte1 = TTF_RenderText_Blended(fontsurface_bouton,bouton,fontBlack);

    surface_bouton = SDL_CreateRGBSurface(initflags,150,50,video_bpp,0,0,0,0); 
    SDL_FillRect(surface_bouton,NULL,rouge);

    SDL_BlitSurface(surface_bouton, NULL, ecran, &position);
    SDL_BlitSurface(texte1, NULL, ecran, &posTexte1);
    SDL_FreeSurface(texte1);
    SDL_FreeSurface(surface_bouton);
    TTF_CloseFont(fontsurface_bouton);

}



SDL_Surface* Afficher_Plateau(char** grille, int dimX, int dimY, Uint32 initflags)
{
    
    SDL_Surface *ecran, *board; // quelques surfaces

    Dimensions fenetre; // main window
   
    fenetre.h = dimX;  // en pixels
    fenetre.w = dimY;   

    Uint8  video_bpp = 32; // 32 bits de couleur

    Uint32 videoflags = SDL_HWSURFACE; // utiliser la mémoire vidéo

    Uint32 vert; // des variables pour des couleurs   
 
    /* Set video mode */
    ecran = SDL_SetVideoMode(fenetre.w, fenetre.h, video_bpp, videoflags); // surface principale

    if (ecran == NULL)
    {
        fprintf(stderr, "N'arrive pas a` etablir mode video%dx%dx%d : %s\n", fenetre.w, fenetre.h, video_bpp, SDL_GetError());
        SDL_Quit();
        exit(2);
    }

    vert = SDL_MapRGB(ecran->format,0,128,0); // c'est du vert
    

    SDL_FillRect(ecran,NULL,vert); // de la couleur dans le fond de la fenêtre principale
    SDL_WM_SetCaption("Jeu de Hex", NULL); // legende de la fenêtre

    Afficher_Bouton(20, 80, "NEW", initflags, ecran);

    // Affichage du plateau de jeu
    board = IMG_Load("Images/hex.png");    // plateau de jeu la taille en pixels est celle de l'image
    SDL_Rect posBoard;                     // sa position
    posBoard.x = 280;
    posBoard.y = 100;
    SDL_BlitSurface(board,NULL,ecran,&posBoard); // on l'associe avec la surface principale

    /* Clean up the SDL library */
    SDL_FreeSurface(board);

    return ecran;
}






void Afficher_Pion(CoordonneesSurface p, char joueur, SDL_Surface *ecran)
{
    // affichage du pion bleu
    SDL_Surface *pion;
    if(joueur=='R') pion = IMG_Load("Images/button-red22.png");
    else pion = IMG_Load("Images/button-blue22.png");
    SDL_Rect posPion;               
    posPion.x = p.x;
    posPion.y = p.y;
    SDL_BlitSurface(pion,NULL,ecran,&posPion);
    SDL_FreeSurface(pion);
    SDL_Flip(ecran);
}

int Placer_Pion(CoordonneesSurface p, char joueur, SDL_Surface *ecran)
{
    // Verifier si les coordonnées se situe bien dans le plateau
    CoordonneesPlateau c;
    c=CoordSurfaceToPlateau(p);
    if(c.c<0 || c.c>10 || c.l>10 || c.l<0) return 1;
    // FAIRE LA VERIF GRACE AUX REGLES
        //APPEL DES FONCTIONS
    //########
    p=CoordPlateauToSurface(c);
    p.x-=13;
    p.y-=13-0.25*c.l;
    Afficher_Pion(p, joueur, ecran);
    return 0;
}

CoordonneesSurface CoordPlateauToSurface(CoordonneesPlateau p)
{
    CoordonneesSurface cp;
    int a=WIHEX;
    int b=HIHEX;
    float r=a/2;
    float s=r/cos(30* PI / 180);
    float h=(b-s)/2;
    int x=r+p.c*2*r+r*p.l;
    int y=p.l*(h+s)+h+s/2+(p.l+0.25*p.l);

    cp.x=x+300;
    cp.y=y+120;
    return cp;
}

CoordonneesPlateau CoordSurfaceToPlateau(CoordonneesSurface p)
{
	CoordonneesPlateau cp;
	int x=p.x-300;
	int y=p.y-120;
	int a=WIHEX;
	int b=HIHEX;
	float r=a/2;
	float s=r/cos(30* PI / 180);
	float h=(b-s)/2;
    // printf("%f", y/(h+s));
	int l=(int)((y/(h+s))-(0.06*(int)(y/(h+s))));
    int c=(int)(x/(2*r));
    if(l%2==0)c-=0.5*l;
    else c-=0.5*l-0.5;

	float x2;
    if(l%2!=0)x2=(x-(0.5*(l-1))*(a))-(a*c);
    else x2=(x-(0.5*l)*(a))-(a*c);
	float y2=(y-l*(h+s));

	if(l%2==0)
	{

		if(y2<x2*(h/r)-h)
		{

			c++;
			l--;
		}
		else if(y2<-x2*(h/r)+h){
			l--;

		}

	}
	else
	{

		if(x2>r)
		{
			if(y2<2*h-x2*(h/r))	l--;
		}
		else
		{
			if(y2<x2*(h/r))l--;
			else c--;
		}
	}

	cp.c=c;
	cp.l=l;
	return cp;
}
 

