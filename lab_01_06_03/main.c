#include <stdio.h>
#include <math.h>

#define OK 0
#define ERROR_IO 1
#define ERROR_VAL 2
#define UP 0
#define DOWN 2
#define ON 1

//Функция по координатам прямой и точки определяет положение точки относительно прямой
int point_place(double x1, double y1, double x2, double y2, double x3, double y3, const double eps)
{
	double a = y2 - y1, b = x1 - x2;
	double c = x2 * y1 - y2 * x1;
	double res = a * x3 + b * y3 + c;


	if (fabs(res) < eps)
		return ON;
	else if ((res < 0 && b > 0) || (res > 0 && b < 0))
		return DOWN;
	else
		return UP;
}


int main(void)
{
	const double eps = 0.000001;
	double x1, y1, x2, y2, x3, y3;
	printf("Input x and y of three point (six double value): ");
	if (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != 6)
	{
		printf("Input error\n");
		return ERROR_IO;
	}

	if (fabs(x1 - x2) < eps && fabs(y1 - y2) < eps)
	{
		printf("You input two similar points\n");
		return ERROR_VAL;
	}

	printf("%d\n", point_place(x1, y1, x2, y2, x3, y3, eps));
	return OK;
}
