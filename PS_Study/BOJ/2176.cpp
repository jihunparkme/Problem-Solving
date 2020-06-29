#include <cstdio>
#include <queue>
using namespace std;
#define pos pair<int, int>
#define x first
#define y second

int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
int Map[105][105], DP[105][105];

int main(void)
{
	int n, m, i, j;
	// freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) 
		for (j = 1; j <= m; j++) 
			scanf("%1d", &Map[i][j]);
		
	queue<pos> Q;
	Q.push({ 1, 1 });
	Map[1][1] = 0; DP[1][1] = 1;

	while (!Q.empty()) {
		pos now = Q.front();
		Q.pop();

		for (i = 0; i < 4; i++) {
			int xx = now.x + dx[i];
			int yy = now.y + dy[i];

			if (Map[xx][yy]) {
				Q.push({ xx, yy });
				Map[xx][yy] = 0;
				DP[xx][yy] = DP[now.x][now.y] + 1;
			}
		}
	}

	printf("%d\n", DP[n][m]);

	return 0;
}