#include <cstdio>
#include <algorithm>
using namespace std;

int A[1005][1005], DP[1005][1005];

int main(void)
{
	int n, m, i, j, mx = 0;
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) 
		for (j = 1; j <= m; j++) 
			scanf("%1d", &A[i][j]);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (A[i][j] == 1) {
				DP[i][j] = min(min(DP[i][j - 1], DP[i - 1][j - 1]), DP[i - 1][j]) + 1;
				mx = max(mx, DP[i][j]);
			}
		}
	}

	printf("%d", mx * mx);

	return 0;
}