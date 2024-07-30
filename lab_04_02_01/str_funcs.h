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

/// @brief функция поиска очередного слова
/// @param *str - строка, в которой ищем слово (in)
/// @param **pbeg - начало слова (out)
/// @param **pend - конец слова (out)
void get_next_word(char *str, char **pbeg, char **pend);

/// @brief функция проверяет есть ли слово в массиве
/// @param words - массив слов (in)
/// @param *words_n - размер массива слов (in)
/// @param *pbeg - указатель на первый элемент искомого слова (in)
/// @param *pend - указатель на последний элемент искомого слова (in)
/// @return false - если слово уже есть в массиве и true в обратном случае
bool check_uniq(char words[][WORD_LEN + 1], size_t words_n, char *pbeg, const char *pend);

/// @brief функция копирования слова в массив слов
/// @param *pbeg - начало слова (in)
/// @param *pend - конец слова (in)
/// @param *word - слово в массиве слов (out)
/// @return код ошибки
int copy_word(char *pbeg, const char *pend, char *word);

/// @brief функция разбиения строки на уникальные слова
/// @param *str - строка (in)
/// @param words - массив слов (out)
/// @param *words_n - размер массива слов (out)
/// @return код ошибки
int parse_string(char *str, char words[][WORD_LEN + 1], size_t *words_n);

/// @brief функция вывода массива слов
/// @param words массив слов (in)
/// @param words_n размер массива слов (in)
void print_words(char words[][WORD_LEN + 1], size_t words_n);

/// @brief функция меняет местами два слова в массиве слов
/// @param arr1 - первое слово
/// @param arr2 - второе слово
void swap(char arr1[], char arr2[]);

/// @brief функция сортировки массива слов
/// @param words массив слов (out)
/// @param words_n размер массива слов (in)
void sort(char words[][WORD_LEN + 1], size_t words_n);


#endif
