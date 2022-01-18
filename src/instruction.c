#include <stdio.h>

#include "../include/instruction.h"
#include "../include/stack.h"


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
        printf("PUSHING %d TO STACK\n",stack[sp]);
        break;
    

    default:
        printf("%d \n",instruction);
        pc++;
        break;
    }
}