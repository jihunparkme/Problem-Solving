#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1000001];

int main(void)
{
	int n, i;
	scanf("%d", &n);

	for (i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	printf("%d\n", dp[n]);

	return 0;
}

/*
1 : 0
2 : 1
3 : 1
4 : 2
5 : 3
6 : 2
*/