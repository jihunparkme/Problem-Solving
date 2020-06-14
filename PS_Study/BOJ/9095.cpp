#include <cstdio>

int dp[12] = { 0, 1, 2, 4, };

int main(void)
{
	int tc, n, i;
	scanf("%d", &tc);

	for (i = 4; i <= 12; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	while (tc--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}