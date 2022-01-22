CC = gcc
CFLAGS = -Wall -g --std=c99
SRC = src/main.c src/instruction.c

all :
	${CC} ${CFLAGS} ${SRC} -o miVM