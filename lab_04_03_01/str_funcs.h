#ifndef __STR_FUNCS_H__
#define __STR_FUNCS_H__

#define STR_LEN        256
#define WORD_LEN       16
#define N              (STR_LEN / 2)
#define DELIMS         " ,;:-.!?"

/// @brief функция считывает единственную строку
/// @param *str - строка, которую считываем (out)
/// @return код ошибки
int read_string(char *str);

/// @brief функция разбиения строки на слова
/// @param *str - строка (in)
/// @param words - массив слов (out)
/// @param *words_n - размер массива слов (out)
/// @return код ошибки
int parse_string(char *str, char words[][WORD_LEN + 1], size_t *words_n);

/// @brief функция удаляет первый символ из строки
/// @param *str - исходная строка (out)
void del_symb(char *str);

/// @brief функция удаляет повторяющиеся символы из строки
/// @param *str - исходная строка (out)
void del_litters(char *str);

/// @brief функция добавления слов в выходную строку
/// @param words - массив слов (in)
/// @param words_n - размер массива слов (in)
/// @param *str - выходная строка (out)
int add_words_in_string(char words[][WORD_LEN + 1], size_t words_n, char *str);


#endif
