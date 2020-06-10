#include <cstdio>
#include <cstdlib>

int main(void)
{
	int n, i, j;
	scanf("%d", &n);

	for (i = 1; i <= n * 2 - 1; i++) {
		for (j = 1; j <= abs(n - i); j++) 
			printf(" ");
		for (; j <= n; j++) 
			printf("*");
		puts("");
	}

	return 0;
}

/*
2 1		|n - i| ~ n
1 2		
0 3		
1 2		|n - i| ~ n
2 1
*/