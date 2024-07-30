#include <stdio.h>
#include <string.h>
#include "str_funcs.h"
#include "defines.h"


int main(void)
{
    size_t fails_count = 0;

    fails_count += strpbrk("abcdefg", "efc") != my_strpbrk("abcdefg", "efc");
    fails_count += strpbrk("abcdefg", " ") != my_strpbrk("abcdefg", " ");
    fails_count += strpbrk("abcdefg", "g") != my_strpbrk("abcdefg", "g");
    fails_count += strpbrk("abc efg", " ") != my_strpbrk("abc efg", " ");

    fails_count += strspn("abbabbac", "ab") != my_strspn("abbabbac", "ab");
    fails_count += strspn("abba bbbbaaaa", "ab") != my_strspn("abba bbbbaaaa", "ab");
    fails_count += strspn(" ", " ") != my_strspn(" ", " ");
    fails_count += strspn(" ", "a") != my_strspn(" ", "a");

    fails_count += strcspn("abbabbac", "c") != my_strcspn("abbabbac", "c");
    fails_count += strcspn("abbabba", "ab") != my_strcspn("abbabba", "ab");
    fails_count += strcspn("      ", " ") != my_strcspn("      ", " ");
    fails_count += strcspn("Hello", "l") != my_strcspn("Hello", "l");

    fails_count += strchr("abcdefg h", ' ') != my_strchr("abcdefg h", ' ');
    fails_count += strchr("abcdefg ha", 'a') != my_strchr("abcdefg ha", 'a');
    fails_count += strchr("abcdefg h", 'i') != my_strchr("abcdefg h", 'i');
    fails_count += strchr("abc", 'o') != my_strchr("abc", 'o');

    fails_count += strrchr("abcdefg h", ' ') != my_strrchr("abcdefg h", ' ');
    fails_count += strrchr("abcdefg ha", 'a') != my_strrchr("abcdefg ha", 'a');
    fails_count += strrchr("abcdefg h", 'i') != my_strrchr("abcdefg h", 'i');

    printf("There is %zu fails\n", fails_count);

    return fails_count;
}
