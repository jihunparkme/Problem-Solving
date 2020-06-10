#include <cstdio>
#include <cstdlib>

int main(void)
{
	int n, i, j;
	scanf("%d", &n);

	for (i = 1; i <= n*2; i++) {
		for (j = 1; j <= n - abs(n - i); j++)
			printf("*");
		for (; j <= n + abs(n - i); j++) 
			printf(" ");
		for (; j <= n * 2; j++) 
			printf("*");
		puts("");
	}

	return 0;
}


/*
1 8 1	n-4 ~ n+4 ~ n*2		
2 6 2	n-3	~ n+3 ~ n*2
3 4 3	n-2
4 2 4	n-1
5 0 5	n-0
4 2 4	n-1
3 4 3
2 6 2
1 8 1
*/