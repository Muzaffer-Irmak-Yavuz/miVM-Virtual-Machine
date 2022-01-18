#include "../include/instruction.h"

bool running = true;




const int program[] = {
    PSH, 5,
    PSH, 10,
    ADD,
    POP,
    HLT
};








int main(int argc, char const *argv[])
{
    while (running)
    {
        eval(fetch(program),program);
        
    }
    
    return 0;
}
