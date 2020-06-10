#include <cstdio>
#include <cstdlib>

int main(void)
{
	int n, i, j;
	scanf("%d", &n);

	for (i = 1; i < n * 2; i++) {
		for (j = 1; j <= n - abs(abs(n - i) + 1); j++) 
			printf(" ");
		for (; j <= n + abs(n - i); j++) 
			printf("*");
		puts("");
	}

	return 0;
}


/*
0 9 0	n - |n-i+1|	~ n + |n-i|
1 7 1	n - |n-i+1|	~ n + |n-i|
2 5 2
3 3 3
5 1 5	n - |n-i+1|	~ n + |n-i|

3 3 3   n - |n-i+1|	~ n + |n-i|
2 5 2
1 7 1
0 9 0
*/