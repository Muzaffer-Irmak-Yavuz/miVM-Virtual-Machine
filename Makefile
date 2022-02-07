SRC_FILES = src\main.c src\instruction.c
CC_FLAGS = -Wall -Wextra -g -std=c11
CC = gcc

all:
    ${CC} ${SRC_FILES} ${CC_FLAGS} -o miVm