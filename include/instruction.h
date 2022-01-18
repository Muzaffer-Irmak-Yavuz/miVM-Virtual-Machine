#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdbool.h>

#include "register.h"

typedef enum {
    PSH,
    ADD,
    POP,
    HLT
} InstructionSet;

extern bool running;


int fetch(const int program[]);

void eval(int instruction, const int program[]);


#endif