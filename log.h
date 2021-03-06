#ifndef log
#define log



#define TAILLE_MAX 11

typedef struct 
{
	int c1,l1, c2, l2;
	char joueur1, joueur2;
}PileCoup;

void undo(PileCoup dernierCoup, char (*plateau)[TAILLE_MAX]);




/*Cette fonction renvoie un plateau vide*/


void init_plateau(char (*plateau)[TAILLE_MAX]);
void affiche_plateau(char (*plateau)[TAILLE_MAX]);
/*Cette fonction renvoie la couleur du joueur qui va joué en premier */

void maj_plateau(char (*plateau)[TAILLE_MAX], int x, int y, char joueur);

int init_joueur();

int rand_a_b();/* return 1 ou 2*/

void save(char (*plateau)[TAILLE_MAX],PileCoup p,FILE *sauvegarde);

void load (char (*plateau)[TAILLE_MAX],FILE *sauvegarde);
#endif
