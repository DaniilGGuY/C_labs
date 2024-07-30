/*
Предполагается, что во время работы программы не возникнет ошибок выполнения
*/

#include <stdio.h>
#include <string.h>


void text_to_bin(FILE *src, FILE *dst)
{
    int val;
    while (fscanf(src, "%d", &val) == 1)
        fwrite(&val, sizeof(val), 1, dst); 
}


void bin_to_text(FILE *src, FILE *dst)
{
    int val;
    while (fread(&val, sizeof(val), 1, src) == 1)
        fprintf(dst, "%d\n", val);
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
