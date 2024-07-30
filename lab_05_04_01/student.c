#include <stdio.h>
#include <string.h>
#include "student.h"
#include "bin_file_funcs.h"
#include "txt_file_funcs.h"
#include "defines.h"


int stud_read(FILE *f, struct student *stud)
{
    unsigned int marks[N];
    char buf_surname[MAX_SURNAME_LEN], buf_name[MAX_NAME_LEN];
    size_t len;
    
    if (!fgets(buf_surname, sizeof(buf_surname), f))
        return ERR_IO;
    len = strlen(buf_surname);
    if (len && buf_surname[len - 1] == '\n')
    {
        buf_surname[len - 1] = '\0';
        --len;
        if (!len)
            return ERR_IO;
    }
    else
        return ERR_BUF;
    
    if (!fgets(buf_name, sizeof(buf_name), f))
        return ERR_IO;
    len = strlen(buf_name);
    if (len && buf_name[len - 1] == '\n')
    {
        buf_name[len - 1] = '\0';
        --len;
        if (!len)
            return ERR_IO;
    }
    else
        return ERR_BUF;
    
    for (size_t i = 0; i < N; ++i)
    {
        if (fscanf(f, "%u", &marks[i]) != 1)
            return ERR_IO;
    }
    
    fgetc(f);
    
    strcpy(stud->surname, buf_surname);
    strcpy(stud->name, buf_name);
    memcpy(stud->marks, marks, sizeof(marks));
    
    return OK;
}


void stud_print(FILE *f, const struct student *stud)
{
    fprintf(f, "%s\n", stud->surname);
    fprintf(f, "%s\n", stud->name);
    for (size_t i = 0; i < N; ++i)
        fprintf(f, "%u ", stud->marks[i]);
        
    fprintf(f, "\n");
}


int cmp_studs(const struct student *left, const struct student *right)
{
    int comp = strcmp(left->surname, right->surname);
    if (!comp)
        return strcmp(left->name, right->name);
        
    return comp;
}

