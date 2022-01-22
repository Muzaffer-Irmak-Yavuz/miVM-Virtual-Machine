#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

typedef struct {
    char **set;
    int instructionCount;
} PARSE_INFO;


PARSE_INFO parse(const char *filename);

#endif