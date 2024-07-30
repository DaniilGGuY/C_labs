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


void get_next_word(char *str, char **pbeg, char **pend)
{
    char *pcur = str;
    *pbeg = NULL;
    *pend = NULL;

    while (*pcur && strchr(DELIMS, *pcur))
        ++pcur;

    if (!(*pcur))
        return;

    *pbeg = pcur;
    while (*pcur && !strchr(DELIMS, *pcur))
        ++pcur;
    *pend = pcur;
}


bool check_uniq(char words[][WORD_LEN + 1], size_t words_n, char *pbeg, const char *pend)
{
    for (size_t i = 0; i < words_n; ++i)
        if (strlen(words[i]) == (size_t)(pend - pbeg) && !strncmp(words[i], pbeg, pend - pbeg))
            return false;

    return true;
}


int copy_word(char *pbeg, const char *pend, char *word)
{
    if (pend - pbeg > WORD_LEN)
        return ERR_LEN_WORD;

    size_t ind = 0;
    char *pcur = pbeg;
    while (pcur < pend)
    {
        word[ind] = *pcur;
        ++pcur;
        ++ind;
    }

    word[ind] = 0;
    return OK;
}


int parse_string(char *str, char words[][WORD_LEN + 1], size_t *words_n)
{
    char *pbeg, *pend, *pcur = str;
    int rc = OK;
    *words_n = 0;
    while (!rc && pcur && *pcur)
    {
        get_next_word(pcur, &pbeg, &pend);
        if (pbeg && check_uniq(words, *words_n, pbeg, pend))
        {
            rc = copy_word(pbeg, pend, words[*words_n]);
            if (!rc)
                ++(*words_n);
        }

        pcur = pend;
    }

    if (!rc && *words_n == 0)
        return ERR_IO;

    return rc;
}


void print_words(char words[][WORD_LEN + 1], size_t words_n)
{
    for (size_t i = 0; i < words_n - 1; ++i)
        printf("%s ", words[i]);

    printf("%s\n", words[words_n - 1]);
}


void swap(char arr1[], char arr2[])
{
    char character;
    for (size_t i = 0; i < WORD_LEN; ++i)
    {
        character = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = character;
    }
}


void sort(char words[][WORD_LEN + 1], size_t words_n)
{
    for (size_t i = 0; i < words_n - 1; ++i)
    {
        for (size_t j = 0; j < words_n - i - 1; ++j)
        {
            if (strncmp(words[j], words[j + 1], WORD_LEN) > 0)
                swap(words[j], words[j + 1]);
        }
    }
}

