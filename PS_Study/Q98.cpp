#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, i, j;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	vector<vector<int> > map(n, vector<int>(n));
	vector<vector<int> > dp(n, vector<int>(n));
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			scanf("%d", &map[i][j]);
	
	dp[0][0] = map[0][0];
	// 가장자리인 0행, 0열 선 처리
	for (i = 1; i < n; i++) {
		dp[0][i] = dp[0][i - 1] + map[0][i];
		dp[i][0] = dp[i - 1][0] + map[i][0];
	}

	for(i = 1; i < n; i++) {
		for (j = 1; j < n; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
		}
	}

	printf("%d\n", dp[n-1][n-1]);

	return 0;
}