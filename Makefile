CC = gcc
CFLAGS = -ansi -std=c99 -g
LIBS =
LDFLAGS =
INCLUDES =
EXEC = main
INC = constantes.h personnages.h actions.h objet.h plateau.h salle.h
SRC =
OBJ = $(SRC:.c=.o)

SRCPE = personnages.c actions.c objet.c testpersonnages.c
TPE = $(SRCPE:.c=.o)

SRCPL = plateau.c testplateau.c
TPL = $(SRCPL:.c=.o)


all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf $(EXEC)

testPlateau: $(TPL)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)

testPersonnages: $(TPE)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
