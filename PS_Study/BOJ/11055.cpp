#include <cstdio>
#include <algorithm>
using namespace std;

int A[1001], DP[1001];

int main(void)
{
	int n, i, j, res = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);

		for (j = 0; j < i; j++) 
			if (A[i] > A[j] && DP[j] + A[i] > DP[i])
				DP[i] = DP[j] + A[i];

		if (DP[i] > res)
			res = DP[i];
	}

	printf("%d\n", res);

	return 0;
}