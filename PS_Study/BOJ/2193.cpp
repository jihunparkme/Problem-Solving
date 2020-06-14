#include <cstdio>
#define ll long long
ll dp[91] = { 0, 1, 1, 2, 3, };

int main(void)
{
	int n, i;
	scanf("%d", &n);

	for (i = 5; i <= n; i++) 
		dp[i] = dp[i - 2] + dp[i - 1];
	
	printf("%lld\n", dp[n]);

	return 0;
}