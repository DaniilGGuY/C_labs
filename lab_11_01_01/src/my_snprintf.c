#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "my_snprintf.h"

int read_string(char *src, char *dst, size_t *len_dst, size_t max_size)
{
    size_t read = 0;
    while (*src)
    {
        ++read;
        if (dst && *len_dst < max_size)
            dst[(*len_dst)++] = *src;
        ++src;
    }

    return read;
}

int read_long_octo(unsigned long src, char *dst, size_t *len_dst, size_t max_size)
{
    size_t i = 0, read = 0;
    // Создаем массив символов, чтобы поразрядно поместить в него число
    size_t count_digits = sizeof(src) * 8 / 3 + 1;
    char tmp[count_digits + 1];

    // Если передается ноль, то последующий алгоритм не выполнится, соответственно необходимо поместить в буфер само число
    if (src == 0)
        tmp[i++] = '0';

    // В этом цикле мы "отклеиваем" от числа последний разряд и помещаем его в буфер в начало 
    while (src != 0)
    {
        tmp[i++] = '0' + src % BASE;  // отклеивание
        src /= BASE; 
    }

    // Поскольку в предыдущем цикле мы помещали последний разряд в начало, то в этом цикле мы идем с конца буфера и добавляем
    // разряды числа в конец буфера dst
    while (i > 0)
    {
        ++read;  // Увеличиваем количество прочитанных символов
        // Если есть место в буфере, то помещаем в него очередной разряд
        if (dst && *len_dst < max_size)
            dst[(*len_dst)++] = tmp[i - 1];
        --i;
    }

    return read;
}

int my_snprintf(char *restrict buffer, size_t bufsz, const char *restrict format, ...)
{
    size_t index = 0, performed = 0;
    bool is_error = false;
    va_list vl;

    va_start(vl, format);

    while (*format && !is_error)
    {
        if (*format == '%')
        {
            ++format;
            if (*format == 's')
                performed += read_string(va_arg(vl, char*), buffer, &index, bufsz);
            else if (*format == 'l' && *(format + 1) == 'o')
            {
                performed += read_long_octo(va_arg(vl, unsigned long), buffer, &index, bufsz);
                ++format;
            }
            else 
                is_error = true;
        }
        else
        {
            if (buffer && index < bufsz)
                buffer[index++] = *format;
            ++performed;
        }

        ++format;
    }
    
    va_end(vl);

    if (buffer)
    {
        if (index < bufsz)
            buffer[index++] = 0;
        else
            buffer[bufsz - 1] = 0;
    }


    if (is_error)
        return -1;

    return performed;
}
