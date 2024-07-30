#include <stdio.h>

int main(void)
{
    int flat;
    int floor, ent;
    const int flat_on_ent = 36, flat_on_floor = 4, num_of_floor = 9;

    scanf("%d", &flat);

    ent = flat / flat_on_ent + (flat % flat_on_ent != 0);
    floor = (flat % flat_on_ent) / flat_on_floor + ((flat % flat_on_ent) % flat_on_floor != 0);
    floor = floor == 0 ? num_of_floor : floor;

    printf("%d %d\n", ent, floor);
}
