#include <cstdio>

int main(void)
{
	int n, i;
	int dp[1001] = { 0, 1, 3, };
	scanf("%d", &n);

	for (i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
		if (dp[i] >= 10007) dp[i] = dp[i] % 10007;
	}
	
	printf("%d\n", dp[n]);
	return 0;
}