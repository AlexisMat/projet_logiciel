#ifndef log
#define log



#define TAILLE_MAX 11



/*Cette fonction renvoie un plateau vide*/


void init_plateau(char (*plateau)[TAILLE_MAX]);
void affiche_plateau(char (*plateau)[TAILLE_MAX]);
/*Cette fonction renvoie la couleur du joueur qui va joué en premier */

int init_joueur();

int rand_a_b();/* return 1 ou 2*/

void save(char (*plateau)[TAILLE_MAX]);

#endif