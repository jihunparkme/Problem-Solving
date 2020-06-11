#include <cstdio>

int dp[101][11];

int main(void)
{
	int n, i, j;
	long long res = 0;
	scanf("%d", &n);

	for (i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (i = 2; i <= n; i++) { 
		for (j = 0; j <= 9; j++) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	for (i = 0; i <= 9; i++) 
		res += dp[n][i];

	printf("%lld\n", res % 1000000000);
	return 0;
}