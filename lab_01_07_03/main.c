#include <stdio.h>
#include <math.h>

#define OK 0
#define ERROR_IO 1
#define ERROR_VAL 2

//Функция по координатам прямой и точки определяет положение точки относительно прямой
double calc_res(double x, double eps)
{
	double res = 0.0;
	double now = x;
	int i = 1;
	while (fabs(now) >= eps)
	{
		res += now;
		i += 2;
		now = (-1) * now * x * x / i * (i - 2);
	}

	return res;
}


int main(void)
{
	double x, eps;
	printf("Input x and eps: ");
	if (scanf("%lf %lf", &x, &eps) != 2)
	{
		printf("Input error\n");
		return ERROR_IO;
	}

	if (eps <= 0 || eps > 1 || fabs(x) > 1)
	{
		printf("Error valuen");
		return ERROR_VAL;
	}

	double val = calc_res(x, eps);
	printf("%.6lf ", val);
	double ex_val = atan(x);
	printf("%.6lf ", ex_val);
	double abs_er = fabs(val - ex_val);
	printf("%.6lf ", abs_er);
	double rel_er = fabs(abs_er / ex_val);
	printf("%.6lf\n", rel_er);
	return OK;
}
