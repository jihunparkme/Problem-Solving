#include <cstdio>
#include <algorithm>
using namespace std;

int dp[501];

int main(void)
{
	int n, val, i, j;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = i; j >= 1; j--) {
			scanf("%d", &val);
			dp[j] = max(dp[j] + val, dp[j - 1] + val);
		}
	}

	printf("%d\n", *max_element(dp+1, dp+1+n ));

	return 0;
}