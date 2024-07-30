/*
Предполагается, что во время работы программы не возникнет ошибок выполнения
*/

#include <stdio.h>
#include <string.h>


struct student 
{
    char surname[100];
    char name[100];
    unsigned int marks[4];
};


int stud_read(FILE *f, struct student *stud)
{
    fgets(stud->surname, sizeof(stud->surname), f);
    stud->surname[strlen(stud->surname) - 1] = 0;
    fgets(stud->name, sizeof(stud->name), f);
    stud->name[strlen(stud->name) - 1] = 0;
    fscanf(f, "%u %u %u %u", &stud->marks[0], &stud->marks[1], &stud->marks[2], &stud->marks[3]); 
    fgetc(f);
    if (feof(f))
        return 1;
    return 0;
}


void stud_print(FILE *f, const struct student *stud)
{
    fprintf(f, "%s\n", stud->surname);
    fprintf(f, "%s\n", stud->name);
    fprintf(f, "%u %u %u %u\n", stud->marks[0], stud->marks[1], stud->marks[2], stud->marks[3]);
}


void text_to_bin(FILE *src, FILE *dst)
{
    struct student cur; 
    while (stud_read(src, &cur) == 0)
        fwrite(&cur, sizeof(cur), 1, dst);
}


void bin_to_text(FILE *src, FILE *dst)
{
    struct student cur; 
    while (fread(&cur, sizeof(cur), 1, src) == 1)
        stud_print(dst, &cur);
}


int main(int argc, char **argv)
{
    FILE *src, *dst;
    if (argc == 4)
    {
        if (strcmp(argv[1], "t") == 0)
        {
            src = fopen(argv[2], "r");
            dst = fopen(argv[3], "wb");
            text_to_bin(src, dst);
            fclose(src);
            fclose(dst);
        }
        else
        {
            src = fopen(argv[2], "rb");
            dst = fopen(argv[3], "w");
            bin_to_text(src, dst);
            fclose(src);
            fclose(dst);
        }
    }
    
    return 0;
}
