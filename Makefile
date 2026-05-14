CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c \
      src/affichage.c \
      src/carte.c \
      src/joueur.c \
      src/partie.c \
      src/structcarte.c \
      src/structjoueur.c

EXEC = Flip7

all:
	$(CC) $(SRC) $(CFLAGS) -o $(EXEC)

clean:
	rm -f $(EXEC)