#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa analisamem
# Autor		: Daniel Nogueira Junqueira (danijnog@ufmg.br)
# Histórico	: 2023/05/24 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make run - compila tudo
#		: make clean - remove objetos e executável

# Na pasta tmp conterá o log gerado pelo memlog, denominado arvorelog.out
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
OBJ = obj
SRC = src
INC = include
BIN = bin
TMP = tmp
OBJS = $(OBJ)/main.o $(OBJ)/arvore.o $(OBJ)/memLog.o
HDRS = $(INC)/arvore.h $(INC)/memLog.h $(INC)/msgAssert.h
CFLAGS = -Wall -pg -c -I$(INC)

TMPS = $(TMP)/arvorelog.out
EXE = $(BIN)/main

run: $(EXE)
	$(EXE) -p tmp/arvorelog.out -l -i 2 9 10 5 7 8 3 25 24 63 54 53 65 27 12 13 14 30 31 32 33 4 40 43 42 41 89 82 83 1 15 16 85 84 21 22 19 28 86 72 71 75 73 78 100 29

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/arvore.o: $(HDRS) $(SRC)/arvore.c
	$(CC) $(CFLAGS) -o $(OBJ)/arvore.o $(SRC)/arvore.c

$(OBJ)/memLog.o: $(HDRS) $(SRC)/memLog.c 
	$(CC) $(CFLAGS) -o $(OBJ)/memLog.o $(SRC)/memLog.c

clean:
	rm -f $(EXE) $(OBJS) $(TMPS) gmon.out 