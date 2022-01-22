#include "../include/parser.h"

char **parse(const char *filename)
{

    char **set = malloc(sizeof(char *) * 20);
    int index = 0;

    FILE *fp = fopen(filename, "r");
    char *buffer = malloc(sizeof(char) * 100);

    char *token = malloc(sizeof(char) * 10);
    while (fgets (buffer, 100, fp)) // read end of column 
    {
        token = strtok(buffer, " ");
        set[index] = malloc(sizeof(char) * 10);
        strcpy(set[index], token);
        index++;


        printf("1 - %s\n",token);
        
        token = strtok(NULL, " ");
        if (token != NULL) {
            printf("2 - %s\n",token);
            set[index] = malloc(sizeof(char) * 10);
            strcpy(set[index], token);
            index++;
        }
            

        token = strtok(NULL, " ");
        if (token != NULL) {
            printf("3 - %s\n",token);
            set[index] = malloc(sizeof(char) * 10);
            strcpy(set[index], token);
            index++;
        }
        
    }
}

