#ifndef hex
#define hex

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define TAILLE_MAX 11


/*Cette fonction renvoie un plateau vide*/


void init_plateau(char (*plateau)[TAILLE_MAX]);
void affiche_plateau(char (*plateau)[TAILLE_MAX]);
/*Cette fonction renvoie la couleur du joueur qui va joué en premier */

int init_joueur();

int rand_a_b();/* return 1 ou 2*/

/*Cette fonction vérifie la validité d'un coup*/

bool coup_valide();

/*Cette fonction retourne la couleur du gagnant*/

int est_gagnant();









#endif
