#ifndef __TXT_FILE_FUNCS_H__
#define __TXT_FILE_FUNCS_H__

#define STUD_COUNT           30

/// @brief функция считывает студентов из файла в массив
/// @param *src - файл, из которого читаем (in)
/// @param studs - массив студентов (out)
/// @param *stud_col - количество студентов (out)
/// @return код ошибки
int read_studs(FILE *src, struct student studs[], size_t *stud_col);

/// @brief функция, которая переписывает в файл студентов, чьи фамилия начинаются с определенной подстроки
/// @param *dst - файл, куда записываем (out)
/// @param studs массив студентов (in)
/// @param studs_col количество студентов (in)
/// @param *substr - искомая подстрока (in)
/// @return код ошибки
int file_substr_print(FILE *dst, const struct student studs[], size_t studs_col, const char *substr);


#endif
