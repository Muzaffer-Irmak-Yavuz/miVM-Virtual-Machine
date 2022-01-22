#include "../include/parser.h"

/**
 * @brief Private Macro Section
 * 
 */

#define IS_EQUAL 0


/**
 * @brief Private Function Section
 * 
 */

static void clear_token_from_noise(char  * __restrict__ token)
{
    for (size_t i = 0; i < strlen(token); i++)
    {
        if(!(isalpha(token[i]) || isalnum(token[i])))
            token[i] = '\0';
    }
}


/**
 * @brief parse source code and get instructions. Responsible
 * for opening and closing source code file @param filename
 * 
 * 
 * @return PARSE_INFO contain instruction set and instruction count
 */

PARSE_INFO parse(const char *filename)
{

    FILE *fp = fopen(filename, "r");

    char **set = malloc(sizeof(char *) * 20);
    int index = 0;

    
    char *buffer = malloc(sizeof(char) * 100);
    char *token  = malloc(sizeof(char) * 10);
    
    while (fgets (buffer, 100, fp)) // read end of column 
    {
        //get the first token
        token = strtok(buffer, " ");


        // clear token from escape seq or space
        clear_token_from_noise(token);

        // check if its empty
        if (strcmp(token, "") != IS_EQUAL) {

            
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
            clear_token_from_noise(token);

            // check if its empty
            if (strcmp(token, "") == IS_EQUAL) {
                break;
            }
                

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


