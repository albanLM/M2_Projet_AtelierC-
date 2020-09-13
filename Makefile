SRC_PATH = src/
OBJ_PATH = bin/
INC_PATH = include/
DOC_PATH = doc/

CC=g++
CXXFLAGS=
CFLAGS=-W -Wall -pedantic

TARGET=Banque.out

all: $(TARGET)

$(TARGET): $(OBJ_PATH)main.o $(OBJ_PATH)Arrivee.o $(OBJ_PATH)Banque.o $(OBJ_PATH)Caissier.o $(OBJ_PATH)Client.o $(OBJ_PATH)Depart.o $(OBJ_PATH)Evenement.o $(OBJ_PATH)FileAttente.o $(OBJ_PATH)SED.o $(OBJ_PATH)Simulation.o 
	$(CC) $(CXXFLAGS) -o $(TARGET) $^ $(CFLAGS)

$(OBJ_PATH)main.o: main.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $< $(CFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $(SRC_PATH)$*.cpp $(CFLAGS)

clean:
	rm -f $(OBJ_PATH)* && rm -fR $(DOC_PATH)

doxy:
	doxygen Doxyfile

run:
	./$(TARGET)