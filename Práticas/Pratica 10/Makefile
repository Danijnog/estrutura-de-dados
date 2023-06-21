CC = gcc
SRC = src
LIBS = -lm
INC = include
OBJ = obj
BIN = bin
TARGET = $(BIN)/main
OBJS = $(OBJ)/main.o $(OBJ)/arvexp.o $(OBJ)/timer.o
HDRS = $(INC)/arvexp.h $(INC)/timer.h
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/main

all: $(TARGET)

run:  $(EXE)
	$(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -Dm=2915 -DCARGA=100000 -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/arvexp.o: $(HDRS) $(SRC)/arvexp.c
	$(CC) $(CFLAGS) -o $(OBJ)/arvexp.o $(SRC)/arvexp.c

$(OBJ)/timer.o: $(HDRS) $(SRC)/timer.c
	$(CC) $(CFLAGS) -o $(OBJ)/timer.o $(SRC)/timer.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out