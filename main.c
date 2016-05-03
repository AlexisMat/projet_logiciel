#include "fonctionnalite_prog.h"



int main (int argc,char *argv[]){
	int joueur;
	char plateau [TAILLE_MAX][TAILLE_MAX];
	init_plateau(plateau);
	joueur = init_joueur();
	affiche_plateau(plateau);
	printf("Joueur : %d\n",joueur);
	plateau[5][6]='R';
	plateau[6][6]='R';
	plateau[7][9]='R';
	plateau[5][6]='R';
	plateau[5][7]='R';
	plateau[5][8]='R';
	plateau[5][9]='R';
	plateau[9][6]='R';
	plateau[9][9]='R';
	affiche_plateau(plateau);
	save(plateau);
	return 0;
}
