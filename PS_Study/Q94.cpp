#include <cstdio>

int dp[50] = { 0, 1, 2, };

int main(void)
{
	int n, i;
	scanf("%d", &n);

	for (i = 3; i <= n+1; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	printf("%d\n", dp[n+1]);

	return 0;
}