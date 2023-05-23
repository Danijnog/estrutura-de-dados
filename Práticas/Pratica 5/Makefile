CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/caminha.o $(OBJ)/geraarvbin.o
HDRS = $(INC)/caminha.h $(INC)/geraarvbin.h
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) -s 5 -n 10 -o arquivo.txt

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/geraarvbin.o: $(HDRS) $(SRC)/geraarvbin.c
	$(CC) $(CFLAGS) -o $(OBJ)/geraarvbin.o $(SRC)/geraarvbin.c

$(OBJ)/caminha.o: $(HDRS) $(SRC)/caminha.c
	$(CC) $(CFLAGS) -o $(OBJ)/caminha.o $(SRC)/caminha.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out