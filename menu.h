#ifndef menu
#define menu

#include "log.h"

/*Structure qui sert a stocker les deux derniers coup. Elle sera utilisee si on utilise la fonction Undo. Nous n'avons pas besoin de stocker plus de coup,
 *etant donne qu'on ne peut faire undo que sur le dernier coup joue.
 *   -Le coup le plus ancien se trouve dans c1/l1, pour récupérer le dernier coup, il faut récupérer les coordonnees qui sont dans c2/l2 ou dans c1/l1 si c2=-1
 *	 -Si c1 ET c2 sont egaux a -1, cela veut dire que la plateau est vide, et qu'aucun coup n'a encore ete joue
 */
typedef struct 
{
	int c1,l1, c2, l2;
	char joueur1, joueur2;
}PileCoup;

void undo(PileCoup dernierCoup, char (*plateau)[TAILLE_MAX]);




#endif