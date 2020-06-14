#include <cstdio>

int main(void)
{
	int i, j, n, m = 1;
	scanf("%d", &n);

	for (i = 1; i > 0; i += m) {
		for (j = 1; j <= i; j++)
			printf("*");

		puts("");
		if (i >= n) m *= -1;
	}
	
	return 0;
}