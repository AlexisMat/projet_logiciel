#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#include "log.h"

void init_plateau(char (*plateau)[TAILLE_MAX]){
	int i,j;
	for(i=0;i<TAILLE_MAX;i++){
		for(j=0;j<TAILLE_MAX;j++){
			plateau [i][j] = '.';
		}
	}
}

void affiche_plateau(char (*plateau)[TAILLE_MAX]){
	int i,j;
	for(i=0;i<TAILLE_MAX;i++){
		for(j=0;j<TAILLE_MAX;j++){
			printf("%c",plateau [i][j]);
		}
		printf("\n");
	}
}
int rand_a_b(){
	int j;
	srand(time(NULL));
	j= rand() %2 +1;
	return (j);
}

int init_joueur(){
	int j;
	return (j=rand_a_b());
}
