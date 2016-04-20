CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL -lSDL_mixer #Linker
EXEC=affichage_hex  #Nom du programme à modifier

all: ${EXEC}

${EXEC}: ${EXEC}.o
	${CPP} $(CFLAGS) -o ${EXEC} ${EXEC}.o ${LDFLAGS}

${EXEC}.o: ${EXEC}.c
	${CPP} $(CFLAGS) -o ${EXEC}.o -c ${EXEC}.c


clean:	
	rm -fr *.o

mrproper: clean
	rm -fr ${EXEC}


En gros il faut que la compilation fasse gcc -o monprogramme monprogramme.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf 
mais j'sais pas du tout comment faire et perso comme c'es tlà, ça marche pas pour moi