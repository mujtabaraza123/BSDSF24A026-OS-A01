#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/myfilefunctions.h"

int wordCount(FILE* file, int* lines, int* words, int* chars)
{
    int c;
    int inWord = 0;

    if (file == NULL || lines == NULL || words == NULL || chars == NULL)
    {
        return -1;
    }

    *lines = 0;
    *words = 0;
    *chars = 0;

    while ((c = fgetc(file)) != EOF)
    {
        (*chars)++;

        if (c == '\n')
        {
            (*lines)++;
        }

        if (isspace(c))
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            (*words)++;
            inWord = 1;
        }
    }

    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches)
{
    char buffer[1024];
    char** result = NULL;
    int count = 0;

    if (fp == NULL || search_str == NULL || matches == NULL)
    {
        return -1;
    }

    *matches = NULL;

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if (strstr(buffer, search_str) != NULL)
        {
            char** temp;
            size_t length = strlen(buffer);

            temp = realloc(result, (count + 1) * sizeof(char*));

            if (temp == NULL)
            {
                return -1;
            }

            result = temp;

            result[count] = malloc(length + 1);

            if (result[count] == NULL)
            {
                return -1;
            }

            strcpy(result[count], buffer);
            count++;
        }
    }

    *matches = result;

    return count;
}
