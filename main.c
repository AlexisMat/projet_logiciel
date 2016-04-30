#include "fonctionnalite_prog.h"



int main (int argc,char *argv[]){
	int joueur;
	char plateau [TAILLE_MAX][TAILLE_MAX];
	init_plateau(plateau);
	joueur = init_joueur();
	affiche_plateau(plateau);
	printf("Joueur : %d\n",joueur);
	return 0;
}
