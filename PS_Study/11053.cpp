#include <cstdio>
#include <algorithm>
using namespace std;

int A[1001], DP[1001];

int main(void)
{
	int n, i, j, res = 1;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		int tmp = 0;

		for (j = 1; j <= i; j++)
			if (A[i] > A[j] && DP[j] > tmp) 
				tmp = DP[j];

		DP[i] = tmp + 1;
		if (DP[i] > res)
			res = DP[i];
	}

	printf("%d\n", res);
	return 0;
}