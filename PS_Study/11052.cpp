#include <cstdio>
#include <algorithm>
using namespace std;

int DP[1001][1001], P[1001];

int main(void)
{
	int n, i, j;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) 
		scanf("%d", &P[i]);
	
	for (i = 1; i <= n; i++) {
		DP[1][i] = P[1];
		DP[i][1] = DP[i-1][1] + P[1];
	}

	for (i = 2; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			DP[i][j] = max(DP[i][j-1], DP[i - j][j] + P[j]);
		}
		for (; j <= n; j++) {
			DP[i][j] = DP[i][j - 1];
		}
	}

	printf("%d\n", DP[n][n]);

	return 0;
}