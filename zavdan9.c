#include <stdio.h>
#include <math.h>

int min_steps(int x, int y);

int main()
{
    int x, y;

	printf("Введіть два числа через пробіл: ");
    if (scanf("%d %d", &x, &y) != 2) {
		printf("\nНекоректні дані\n");
		return 1;
	}

	int res = min_steps(x, y);

	if (res == -1) {
		printf("\nКількість кроків не має бути від'ємною\n");
		return 1;
	}

    printf("\nКількість кроків: %d\n", res);

    return 0;
}

int min_steps(int x, int y)
{
    int dist = y - x;

	if (dist <= 0)
		return -1;

    if (dist == 0)
		return 0;

    int step = (int)sqrt(dist);

    if (step * step == dist)
        return step * 2 - 1;
    else if (step * step < dist && dist <= step * step + step)
        return step * 2;
    else
        return step * 2 + 1;
}
