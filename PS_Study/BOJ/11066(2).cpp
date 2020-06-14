#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 10000

int file[501], sm[501], dp[501][501];

int rec(int i, int j)
{
	int k;

	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int& res = dp[i][j];
	for (k = i; k <= j - 1; k++) {
		int tmp = rec(i, k) + rec(k + 1, j) + sm[j] - sm[i - 1];

		if (res == -1 || res > tmp) res = tmp;
	}

	return res;
}

void solve()
{
	int n, i;
	memset(dp, -1, sizeof(dp));
	memset(sm, 0, sizeof(sm));
	scanf("%d", &n);

	// ДЉРћЧе
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &file[i]);
		sm[i] = sm[i - 1] + file[i];
	}

	printf("%d\n", rec(1, n));
}

int main(void)
{
	int tc;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);

	while (tc--)
		solve();

	return 0;
}