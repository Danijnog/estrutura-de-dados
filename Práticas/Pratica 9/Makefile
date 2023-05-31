CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/arvoreAvl.o
HDRS = $(INC)/arvoreAvl.h
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/arvoreAvl.o: $(HDRS) $(SRC)/arvoreAvl.c
	$(CC) $(CFLAGS) -o $(OBJ)/arvoreAvl.o $(SRC)/arvoreAvl.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out