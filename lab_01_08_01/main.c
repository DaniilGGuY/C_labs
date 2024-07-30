#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define OK 0
#define ERROR_IO 1
#define ERROR_VAL 2


// Функция запаковки. Принимает байты, возвращает беззнаковое целое
void pack(uint32_t *u, int a, int b, int c, int d)
{
	*u = (a << 3 * CHAR_BIT) + (b << 2 * CHAR_BIT) + (c << CHAR_BIT) + d;
}


//Функция печати довичного представления беззнакового числа
void bin_print(uint32_t u)
{
	size_t nbits = sizeof(u) * CHAR_BIT;
	uint32_t mask = 1u << (nbits - 1);
	for (size_t i = 0; i < nbits; ++i)
	{
		if (u & mask)
			printf("1");
		else
			printf("0");
		mask >>= 1;
	}
}

//Функция печати байтов беззнакового числа u
void byte_print(uint32_t u, uint8_t *a, uint8_t *b, uint8_t *c, uint8_t *d)
{
	uint32_t mask = 255u << 3 * CHAR_BIT;
	*a = (u & mask) >> (3 * CHAR_BIT);
	mask >>= CHAR_BIT;
	*b = (u & mask) >> (2 * CHAR_BIT);
	mask >>= CHAR_BIT;
	*c = (u & mask) >> CHAR_BIT;
	mask >>= CHAR_BIT;
	*d = (u & mask);
	mask >>= CHAR_BIT;
}


int main()
{
	int a, b, c, d;
	uint32_t u;
	uint8_t first, second, third, forth;
	printf("Input four nums: ");
	if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4)
	{
		printf("Error: Input error\n");
		return ERROR_IO;
	}
	if (a < 0 || b < 0 || c < 0 || d < 0 || a > 255 || b > 255 || c > 255 || d > 255)
	{
		printf("Error: Value error\n");
		return ERROR_VAL;
	}

	printf("Result: ");
	pack(&u, a, b, c, d);
	bin_print(u);
	printf("\n");
	byte_print(u, &first, &second, &third, &forth);
	printf("%u %u %u %u\n", first, second, third, forth);
	return OK;
}
