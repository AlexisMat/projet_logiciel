#include "menu.h"


void undo(PileCoup dernierCoup, char (*plateau)[TAILLE_MAX])
{
	plateau[dernierCoup.l2][dernierCoup.c2]='.';
}