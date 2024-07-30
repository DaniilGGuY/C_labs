#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "str_funcs.h"
#include "defines.h"


int read_string(char *str)
{
    char *p;
    printf("Input one string:\n");
    if (!fgets(str, STR_LEN + 1, stdin))
        return ERR_IO;

    p = strchr(str, '\n');
    if (!p)
        return ERR_LEN_STR;

    *p = 0;

    return OK;
}


int parse_string(char *str, char words[][WORD_LEN + 1], size_t *words_n)
{
    char *pcur = strtok(str, DELIMS);
    *words_n = 0;
    while (pcur)
    {
        if (strlen(pcur) > WORD_LEN)
            return ERR_LEN_WORD;

        strcpy(words[*words_n], pcur);
        pcur = strtok(NULL, DELIMS);
        *words_n += 1;
    }

    if (*words_n == 0)
        return ERR_IO;
        
    return OK;
}


void del_symb(char *str)
{
    size_t i = 1;
    do
    {
        *(str + i - 1) = *(str + i);
    } 
    while (*(str + i++));
}


void del_litters(char *str)
{
    bool is;
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        is = false;
        for (size_t j = 0; j < i; ++j)
            if (str[j] == str[i])
                is = true;
                
        if (is)
            del_symb(str + i--);
    }
}


int add_words_in_string(char words[][WORD_LEN + 1], size_t words_n, char *str)
{
    if (words_n == 1)
        return ERR_RES;
        
    size_t col_uniq_words = 0;
    char word_now[WORD_LEN + 1];
    for (size_t i = 0; i < words_n - 1; ++i)
    {
        if (strncmp(words[words_n - 2 - i], words[words_n - 1], WORD_LEN + 1))
        {
            strcpy(word_now, words[words_n - 2 - i]);
            del_litters(word_now);
            strcpy(str, word_now);
            str += strlen(word_now);
            *str = ' ';
            str++;
            col_uniq_words++;
        }
    }
    
    if (col_uniq_words == 0)
        return ERR_RES;
    
    str--;
    *str = 0;
        
    return OK;
}

