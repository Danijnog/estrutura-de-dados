CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/fila.o $(OBJ)/pilha.o
HDRS = $(INC)/fila.h $(INC)/pilha.h
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/fila.o: $(HDRS) $(SRC)/fila.c
	$(CC) $(CFLAGS) -o $(OBJ)/fila.o $(SRC)/fila.c

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.c
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out
