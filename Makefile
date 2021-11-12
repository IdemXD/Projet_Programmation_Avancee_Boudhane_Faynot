CC = gcc
CFLAGS = -ansi -std=c99 -g
LIBS = 
LDFLAGS = 
INCLUDES =  
EXEC = main
SRC = 
OBJ = $(SRC:.c=.o)


SRCPL = plateau.c testplateau.c  
TPL = $(SRCPL:.c=.o)



all: $(EXEC)
main: $(TPL)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf *.o *~
mrproper: clean
	rm -rf $(EXEC)

testPlateau: $(TPL)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)

