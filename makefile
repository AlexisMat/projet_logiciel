CPP=gcc    #Commande du compilateur

CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=`sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lm

CFLAGS=`sdl-config --cflags` #Option d'optimisation du programme
LDFLAGS=`sdl-config --libs` -lSDL_image -lSDL_ttf

EXEC=projet  #Nom du programme à modifier

all: ${EXEC}

$log.o: $log.c
	${CPP} $(CFLAGS) -o log.o -c $log.c ${LDFLAGS}

$menu.o: $menu.c
	${CPP} $(CFLAGS) -o menu.o -c $menu.c ${LDFLAGS}

$regle.o: $regle.c
	${CPP} $(CFLAGS) -o regle.o -c $regle.c ${LDFLAGS}

$affichage_hex.o: $affichage_hex.c
	${CPP} $(CFLAGS) -o $affichage_hex.o -c $affichage_hex.c ${LDFLAGS}

$IA.o: $IA.c
	${CPP} $(CFLAGS) -o IA.o -c $IA.c ${LDFLAGS}

$action.o: $action.c
	${CPP} $(CFLAGS) -o action.o -c $action.c ${LDFLAGS}

${EXEC}: log.o menu.o regle.o affichage_hex.o IA.o action.o 
	${CPP} $(CFLAGS) -o ${EXEC} log.o menu.o regle.o affichage_hex.o IA.o action.o ${LDFLAGS}


clean:	
	rm -fr *.o

mrproper: clean
	rm -fr ${EXEC}
