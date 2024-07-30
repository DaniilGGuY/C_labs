#include <stdio.h>
#include "str_funcs.h"


char *my_strpbrk(const char *str, const char *sym)
{
    size_t i = 0;
    char *now, *min = NULL;
    while (sym[i])
    {
        now = my_strchr(str, sym[i]);
        if ((now && !min) || (now && min && now < min))
            min = now;

        ++i;
    }

    return min;
}


size_t my_strspn(const char *str, const char *sym)
{
    size_t i = 0;
    char *pos;
    while (str[i])
    {
        pos = my_strpbrk(str + i, sym);
        if (pos == str + i)
            ++i;
        else
            return i;
    }

    return i;
}


size_t my_strcspn(const char *str, const char *sym)
{
    size_t i = 0;
    char *pos = my_strpbrk(str, sym);
    if (pos)
        return pos - str;
    else
        while (str[i])
            ++i;

    return i;
}


char *my_strchr(const char *str, int ch)
{
    size_t i = 0;
    while (str[i])
    {
        if (str[i] == ch)
            return (char*)(str + i);

        ++i;
    }

    if (!ch)
        return (char*)(str + i);
    else
        return NULL;
}


char *my_strrchr(const char *str, int ch)
{
    size_t i = 0, pos = 0;
    while (str[i])
    {
        if (str[i] == ch)
            pos = i;

        ++i;
    }

    if (!ch)
        return (char*)(str + i);

    if (str[pos] == ch)
        return (char*)(str + pos);
    else
        return NULL;
}
