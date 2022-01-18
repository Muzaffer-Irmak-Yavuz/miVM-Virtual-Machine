#ifndef REGISTER_H
#define REGISTER_H

typedef enum {
    A, B, C, D,
    PC, SP,
    COUNT_OF_REGISTERS
} Register;


/**
 * @brief Using for printing all registers or access their values
 * 
 */
int registers[COUNT_OF_REGISTERS];

#define pc registers[PC]

#define sp registers[SP]

#endif // REGISTER_H