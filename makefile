CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=`sdl-config --cflags --libs` -lSDL_image -lSDL_ttf
EXEC=projet  #Nom du programme à modifier

all: ${EXEC}

${EXEC}: affichage_hex.o ${LDFLAGS}
	${CPP} $(CFLAGS) -o ${EXEC} affichage_hex.o ${LDFLAGS}

$affichage_hex.o: $affichage_hex.c ${LDFLAGS}
	${CPP} $(CFLAGS) -o $affichage_hex.o -c $affichage_hex.c ${LDFLAGS}


clean:	
	rm -fr *.o

mrproper: clean
	rm -fr ${EXEC}
