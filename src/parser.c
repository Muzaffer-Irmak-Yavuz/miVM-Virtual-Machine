#include "../include/parser.h"


PARSE_INFO parse(const char *filename)
{

    char **set = malloc(sizeof(char *) * 20);
    int index = 0;

    FILE *fp = fopen(filename, "r");
    char *buffer = malloc(sizeof(char) * 100);

    char *token = malloc(sizeof(char) * 10);
    
    while (fgets (buffer, 100, fp)) // read end of column 
    {
        //get the first token
        token = strtok(buffer, " ");


        // clear token from escape seq or space
        for (size_t i = 0; i < strlen(token); i++)
        {
            if(!(isalpha(token[i]) || isalnum(token[i])))
                token[i] = '\0';
        }

        // check if its empty
        if (strcmp(token, "") != 0) {

            
            // when everything is okey put token into instruction set
            set[index] = malloc(sizeof(char) * 10);
            strcpy(set[index], token);
            index++;
        }
            
        

        

        //get new token
        token = strtok(NULL, " ");
        

        while ((token != NULL))
        {
            // clear token from escape seq or space
            for (size_t i = 0; i < strlen(token); i++)
            {
                if(!(isalpha(token[i]) || isalnum(token[i])))
                    token[i] = '\0';
            }

            // check if its empty
            if (strcmp(token, "") == 0)
                break;
            
            

            // when everything is okey put token into instruction set
            set[index] = malloc(sizeof(char) * 10);
            strcpy(set[index], token);
            index++;

            // then get new token
            token = strtok(NULL, " ");
        }

    }

    fclose(fp);
    free(buffer);
    free(token);

    PARSE_INFO info = {
        .set = set,
        .instructionCount = index
    };

    return info;
}


