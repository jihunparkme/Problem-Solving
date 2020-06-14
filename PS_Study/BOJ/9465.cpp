#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[3][100001], DP[3][100001];

void solve()
{
	int n, i, j, mxup = 0, mxdw = 0, res = 0;
	scanf("%d", &n);

	for (i = 1; i <= 2; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &A[i][j]);

	for (j = 1; j <= n; j++) {
		for (i = 1; i <= 2; i++) {
			if (i == 1) // down
				DP[i][j] = max(max(mxdw, mxup), DP[2][j - 1]) + A[i][j];
			else if (i == 2) // up
				DP[i][j] = max(max(mxdw, mxup), DP[1][j - 1]) + A[i][j];
		}

		mxdw = max(mxdw, DP[2][j - 1]);
		mxup = max(mxdw, DP[1][j - 1]);
	}

	printf("%d\n", max(DP[1][n], DP[2][n]));
}

int main(void)
{
	int tc;
	scanf("%d", &tc);

	while (tc--)
		solve();

	return 0;
}