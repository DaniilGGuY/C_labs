#ifndef __STR_FUNCS_H__
#define __STR_FUNCS_H__

#define STR_LEN        256

/// @brief функция считывает единственную строку
/// @param *str - строка, которую считываем (out)
/// @return код ошибки
int read_string(char *str);

/// @brief функция, проверяющая, что строка является корректным числом в экспоненциальной форме
/// @param *str - исходная строка
/// @return true - если строка является корректной записью экспоненциального числа и false иначе
bool is_correct_exp_val(const char *str);


#endif
