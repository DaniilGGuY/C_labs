#include <stdio.h>
#include <math.h>

#define OK 0
#define ERROR_IO 1
#define ERROR_VAL 2

//Функция подсчета результата (возвращает код ошибки)
int calc_res(double *res)
{
	double cur = 0.0;
	int i = 1;

	printf("Enter nums: ");
	while (cur >= 0)
	{
		if (scanf("%lf", &cur) != 1)
			return ERROR_IO;

		if (i == 1 && cur < 0)
			return ERROR_VAL;

		if (cur < 0)
		{
			*res = sin(*res);
			return OK;
		}
		*res += sqrt(cur / i);
		i += 1;
	}

	*res = sin(*res);
	return OK;
}


int main(void)
{
	double res = 0.0;
	int code = calc_res(&res);
	if (code == 0)
		printf("Answer: %lf\n", res);
	else if (code == 1)
		printf("Input error\n");
	else
		printf("Value error\n");

	return code;
}
