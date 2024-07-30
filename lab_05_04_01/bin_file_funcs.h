#ifndef __BIN__FILE_FUNCS_H__
#define __BIN__FILE_FUNCS_H__

/// @brief функция сортирует студентов в алфавитном порядке (сначала по фамилии, потом по имени)
/// @param *f файловая переменная, в которой мы сортируем (out)
/// @return код ошибки
int file_sort(FILE *f);

/// @brief функция, которая считывает студента по его номеру в файле
/// @param *f - файловая переменная, из которой мы считываем (in)
/// @param pos - позиция, с которой мы считываем (in)
/// @param *stud - переменная, куда записываем результат (out)
/// @return код ошибки
int get_by_pos(FILE *f, long pos, struct student *stud);

/// @brief функция, которая записывает студента по его номеру в файл
/// @param *f - файловая переменная, куда мы записываем (out)
/// @param pos - позиция, в которую мы записываем (in)
/// @param *stud - переменная, откуда читаем результат (in)
int put_by_pos(FILE *f, long pos, const struct student *stud);


#endif
