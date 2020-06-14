#include <cstdio>
#define mod 10007
int dp[1001][11];

int main(void)
{
	int n, i, j, res = 0;
	scanf("%d", &n);

	for (i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (i = 2; i <= n; i++) {
		dp[i][0] = 1;

		for (j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}

	for (i = 0; i <= 9; i++)
		res += dp[n][i];

	printf("%d\n", res % mod);

	return 0;
}