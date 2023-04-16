CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/identificaExp.o $(OBJ)/lerExp.o 
HDRS = $(INC)/identificaExp.h $(INC)/lerExp.h
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/identificaExp.o: $(HDRS) $(SRC)/identificaExp.c
	$(CC) $(CFLAGS) -o $(OBJ)/identificaExp.o $(SRC)/identificaExp.c

$(OBJ)/lerExp.o: $(HDRS) $(SRC)/lerExp.c
	$(CC) $(CFLAGS) -o $(OBJ)/lerExp.o $(SRC)/lerExp.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out