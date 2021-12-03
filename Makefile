CC = gcc
CFLAGS = -ansi -std=c99 -g
LIBS = -L./SDL2_ttf/.libs  -L./SDL2_image/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_image -lm
INCLUDES =  -I./SDL2_ttf  -I./SDL2_image
EXEC = main
INC = constantes.h personnages.h actions.h objet.h plateau.h salle.h
SRC = main.c personnages.c actions.c objet.c salle.c 
OBJ = $(SRC:.c=.o)

SRCPE = personnages.c actions.c objet.c testpersonnages.c
TPE = $(SRCPE:.c=.o)

SRCPL = plateau.c objet.c salle.c testplateau.c
TPL = $(SRCPL:.c=.o)


all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o *~
	rm -rf $(EXEC)
	rm -rf testPersonnages
	rm -rf testPlateau

testPlateau: $(TPL)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)

testPersonnages: $(TPE)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
