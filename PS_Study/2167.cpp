#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int A[301][301], DP[301][301];

int main(void)
{
	int N, M, i, j;
	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	// (1,1)부터 (i,j)까지의 누적합
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP [i - 1][j - 1] + A[i][j];
		}
	}

	int K, x, y;
	scanf("%d", &K);
	while (K--) {
		scanf("%d %d %d %d", &i, &j, &x, &y);
		printf("%d\n", DP[x][y] - DP[x][j - 1] - DP[i - 1][y] + DP[i - 1][j - 1]);
	}

	return 0;
}