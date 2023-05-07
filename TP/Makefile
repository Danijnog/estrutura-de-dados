CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
TARGET = $(BIN)/main
OBJS = $(OBJ)/main.o $(OBJ)/identificaExp.o $(OBJ)/armazenaExp.o $(OBJ)/converteExp.o $(OBJ)/resolveExp.o
HDRS = $(INC)/identificaExp.h $(INC)/armazenaExp.h $(INC)/converteExp.h $(INC)/resolveExp.h
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/main

all: $(TARGET)

run:  $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/identificaExp.o: $(HDRS) $(SRC)/identificaExp.c
	$(CC) $(CFLAGS) -o $(OBJ)/identificaExp.o $(SRC)/identificaExp.c

$(OBJ)/armazenaExp.o: $(HDRS) $(SRC)/armazenaExp.c
	$(CC) $(CFLAGS) -o $(OBJ)/armazenaExp.o $(SRC)/armazenaExp.c

$(OBJ)/converteExp.o: $(HDRS) $(SRC)/converteExp.c
	$(CC) $(CFLAGS) -o $(OBJ)/converteExp.o $(SRC)/converteExp.c

$(OBJ)/resolveExp.o: $(HDRS) $(SRC)/resolveExp.c
	$(CC) $(CFLAGS) -o $(OBJ)/resolveExp.o $(SRC)/resolveExp.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out