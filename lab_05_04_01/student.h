#ifndef __STUDENT_H__
#define __STUDENT_H__


#define MAX_SURNAME_LEN      (25 + 1)
#define MAX_NAME_LEN         (10 + 1)
#define N                    4

/*
Структура студента
surname - фамилия студента
name - имя студента
marks - массив оценок студента
*/
struct student 
{
    char surname[MAX_SURNAME_LEN];
    char name[MAX_NAME_LEN];
    unsigned int marks[N];
};

/// @brief функция читает информацию об одном студенте из файла
/// @param *f - файл, куда выводим (in)
/// @param *stud - структурная переменная студента (out)
/// @return код ошибки
int stud_read(FILE *f, struct student *stud);

/// @brief функция выводит информацию о студенте в файл
/// @param *f - файл, куда выводим (out)
/// @param *stud - структурная переменная студента (in)
void stud_print(FILE *f, const struct student *stud);

/// @brief функция сравнивает двух студентов сначала по фамилии потом по имени
/// @param *left первый студент (in)
/// @param *right второй студент (in)
/// @return 0 если равны, 1 если лексикографически больше первый -1 если лексикографически больше второй
int cmp_studs(const struct student *left, const struct student *right);


#endif
