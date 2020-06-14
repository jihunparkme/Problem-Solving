#include <cstdio>

int main(void)
{
	int n, i, j;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n-i; j++) 
			printf(" ");
		printf("*");
		if (i == 1) {
			puts("");
			continue;
		}

		if (i == n) {
			for (; j <= n * 2 - 2; j++)
				printf("*");
			puts("");
			break;
		}

		for (; j < n + i - 2; j++)
			printf(" ");
		printf("*");

		puts("");
	}

	return 0;
}

/*
   *
  * *
 *   *
*******

1 (1)

2 (1) 1 (1) 
3 (1) 3 (1) 

4 (1) 0 (6)		
*/