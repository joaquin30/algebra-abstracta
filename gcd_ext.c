#include <stdio.h>

typedef struct {
    int x, y, z;
} v3;

v3 gcdExt(int a, int b)
{
    if (b == 0)
        return (v3){a, 1, 0};
    v3 tmp = gcdExt(b, a%b);
    return (v3){tmp.x, tmp.z, tmp.y - tmp.z * (a/b)};
}

int main(void)
{
	int a, b, gcd, x, y;
	printf("Num. 1: ");
	scanf("%d", &a);
	printf("Num. 2: ");
	scanf("%d", &b);
	v3 tmp = gcdExt(a, b);
	gcd = tmp.x;
	x = tmp.y;
	y = tmp.z;
	printf("%d = (%d)*(%d) + (%d)*(%d)", gcd, a, x, b, y);
	return 0;
}