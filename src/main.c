#include "../include/instruction.h"
#include "../include/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

bool running = true;













int main(int argc, char const *argv[])
{

    PARSE_INFO info = parse("source.mi");
    
    for (size_t i = 0; i < info.instructionCount; i++)
    {
        printf("%s ",info.set[i]);
    }
    
    
    /*
    while (running)
    {
        eval(fetch(program),program);
        
    }
    */
    return 0;
}
