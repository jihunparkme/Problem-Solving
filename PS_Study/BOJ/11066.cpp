#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10000

int file[501], sm[501], dp[501][501];

void solve()
{
	int n, i, d, x, k;
	scanf("%d", &n);

	// 누적합
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &file[i]);
		sm[i] = sm[i - 1] + file[i];
	}

	for (d = 1; d < n; d++) {	// 부분 파일의 길이	
		for (x = 1; x + d <= n; x++) {	// 시작점
			int y = x + d;
			dp[x][y] = MAX;
			for (k = x; k < y; k++) {
				dp[x][y] = min(dp[x][y], dp[x][k] + dp[k + 1][y] + sm[y] - sm[x - 1]);
			}
		}
	}

	printf("%d\n", dp[1][n]);
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