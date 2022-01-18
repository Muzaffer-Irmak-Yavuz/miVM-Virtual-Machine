#include <stdio.h>

#include "../include/instruction.h"
#include "../include/stack.h"

int registers[COUNT_OF_REGISTERS] = {
    0,0,0,0,0,-1
};

int fetch(const int program[])
{
    return program[pc];
}

void eval(int instruction , const int program[])
{
    switch (instruction)
    {
    case HLT:
        
        printf("PROGRAM HALTING...\n");
        running = false;
        break;
    case PSH:
        sp++;
        stack[sp] = program[++pc];
        break;
    case ADD:
        registers[A] = stack[sp--];
        registers[B] = stack[sp--];

        stack[++sp] = registers[A] + registers[B];
        pc++;
        break;
    case POP:
        printf("POP :%d\n",stack[sp--]);
        pc++;
        break;
    default:
        printf("%d \n",instruction);
        pc++;
        break;
    }
}