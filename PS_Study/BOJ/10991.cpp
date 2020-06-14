#include <cstdio>

int main(void)
{
	int n, i, j;
	scanf("%d", &n);
	
	for (i = n-1; i >= 0; i--) {
		for (j = 1; j <= i; j++) 
			printf(" ");
		
		printf("*");

		for (; j <= n-1; j++)
			printf(" *");

		puts("");
	}

	return 0;
}

/*
3 (1)
2 (1) 0 (1)
1 (1) 1 (1) 1 (1)
0 (1) 1 (1) 1 (1) 1 (1)
*/