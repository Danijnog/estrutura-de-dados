#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main.c (em CFLAGS uso a flag -pg para poder gerar o gmon.out)
# Autor		: Daniel Nogueira Junqueira (danijnog@ufmg.br)
#---------------------------------------------------------------------
# Opções	: make run - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/fibonacci.o $(OBJ)/fatorial.o $(OBJ)/tempo.o
HDRS = $(INC)/fatorial.h $(INC)/fibonacci.h $(INC)/tempo.h
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/main 

run:  $(EXE) 
	$(EXE) -a -n 5
	$(EXE) -b -n 5

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/fatorial.o: $(HDRS) $(SRC)/fatorial.c
	$(CC) $(CFLAGS) -o $(OBJ)/fatorial.o $(SRC)/fatorial.c 
	
$(OBJ)/fibonacci.o: $(HDRS) $(SRC)/fibonacci.c
	$(CC) $(CFLAGS) -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.c 

$(OBJ)/tempo.o: $(HDRS) $(SRC)/tempo.c
	$(CC) $(CFLAGS) -o $(OBJ)/tempo.o $(SRC)/tempo.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out