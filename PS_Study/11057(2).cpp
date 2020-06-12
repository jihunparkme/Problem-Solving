#include <cstdio>
#define mod 10007
int dp[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int main(void)
{
	int n, i, j;
	scanf("%d", &n);

	for (i = 2; i <= n; i++) {
		int tmp = 0;

		for (j = 1; j <= 10; j++) {
			tmp = tmp + dp[j];
			dp[j] = tmp % mod;
		}
	}
	printf("%d\n", dp[10]);

	return 0;
}