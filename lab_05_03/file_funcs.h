#ifndef __FILE_FUNCS_H__
#define __FILE_FUNCS_H__


/// @brief функция создает бинарный файл, заполненный случайными числами
/// @param *f - файловая переменная (out)
/// @param number - количество чисел в файле (in)
/// @return код ошибки
int create_bin_file(FILE *f, size_t number);

/// @brief функция печати файла
/// @param *f - файловая переменная (in)
/// @return код ошибки
int print_file(FILE *f);

/// @brief функция позволяет получить элемент в позиции pos
/// @param *f - файловая переменная (in)
/// @param pos - позиция элемента, который хотим прочитать (in)
/// @param *val - элемент, который читаем (out)
/// @return код ошибки
int get_number_by_pos(FILE *f, long pos, int *val);

/// @brief функция позволяет вставить элемент в позицию pos
/// @param *f - файловая переменная (out)
/// @param pos - позиция элемента, куда хотим записать (in)
/// @param *val - элемент, который читаем (in)
/// @return код ошибки
int put_number_by_pos(FILE *f, long pos, const int *val);

/// @brief функция сортирует файл по возрастанию
/// @param *f - файловая переменная (out)
/// @return код ошибки
int sort_file(FILE *f);


#endif
