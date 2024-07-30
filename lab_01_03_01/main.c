#include <stdio.h>

int main(void)
{
    double v1, t1;
    double v2, t2;
    double v, t;
    scanf("%lf %lf", &v1, &t1);
    scanf("%lf %lf", &v2, &t2);

    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / v;

    printf("%.6lf %.6lf\n", v, t);
}
