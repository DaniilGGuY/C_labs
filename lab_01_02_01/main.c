#include <stdio.h>
#include <math.h>

#define OK 0

int main(void)
{
    const double pi = 3.1415926535;
    const int half_circ_deg = 180;
    double up, down;
    double fi, fi_rad;
    double height, square;

    printf("Input up and down base and down corner:\n");
    scanf("%lf %lf", &up, &down);
    scanf("%lf", &fi);

    fi_rad = fi * pi / half_circ_deg;
    height = fabs(down - up) / 2 * tan(fi_rad);
    square = (down + up) / 2 * height;

    printf("Square of trapezoid: %.6lf\n", square);
    return OK;
}
