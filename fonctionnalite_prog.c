#include "fonctionnalite_prog.h"

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

void save(char (*plateau)[TAILLE_MAX]){
	FILE *save = NULL;
	char hexa;
	int i,j;
	save = fopen("save.txt","w+");
	if (save == NULL){
		fprintf(stderr,"Error de sauvegard\n");
		exit (1);
	}
	fputs("\\hex\n\\board\n",save);
		for(i=0;i<TAILLE_MAX;i++){
			for(j=0;j<TAILLE_MAX;j++){
				hexa = plateau[i][j];
				fputc(hexa,save);
				fputc('\n',save);
			}	
		}
	fputs("\\endboard\n\\endhex\n",save);
}

