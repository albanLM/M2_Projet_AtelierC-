SRC_PATH = src/
OBJ_PATH = bin/
INC_PATH = include/

CC=g++
CFLAGS=-W -Wall -ansi -pedantic

all: $(OBJ_PATH)main.o $(OBJ_PATH)Arrivee.o $(OBJ_PATH)Banque.o $(OBJ_PATH)Caissier.o $(OBJ_PATH)Client.o $(OBJ_PATH)Depart.o $(OBJ_PATH)Evenement.o $(OBJ_PATH)FileAttente.o $(OBJ_PATH)SED.o $(OBJ_PATH)Simulation.o 
	$(CC) -o Banque.out $^

$(OBJ_PATH)main.o:
	$(CC) -o $@ -c main.cpp $(CFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) -o $@ -c $(SRC_PATH)$*.cpp $(CFLAGS)

clean:
	rm -f $(OBJ_PATH)*