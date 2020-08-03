#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define pos pair<int, int>
#define x first
#define y second

int n, k = 2, ans = 2147000000;
int map[105][105], dist[105][105];
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y)
{
	int i;

	map[x][y] = k;
	for (i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (map[xx][yy] != 1) continue;
		if (xx <= 0 || xx > n || yy <= 0 || yy > n) continue;
		if (map[xx][yy] == 1) {
			dfs(xx, yy);
		}
	}
}

void bfs(int k)
{
	int i, j;
	queue<pos> q;
	memset(dist, -1, sizeof(dist));
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j] == k) {
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		for (i = 0; i < 4; i++) {
			int xx = now.x + dx[i];
			int yy = now.y + dy[i];

			if (xx <= 0 || xx > n || yy <= 0 || yy > n) continue;
			if (map[xx][yy] && map[xx][yy] != k) {
				if (ans > dist[now.x][now.y])
					ans = dist[now.x][now.y];
				return;
			}

			if (!map[xx][yy] && dist[xx][yy] == -1) {
				dist[xx][yy] = dist[now.x][now.y] + 1;
				q.push({ xx, yy });
			}
		}
	}
}

int main(void)
{
	int i, j;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);

	// 대륙 번호 지정, (2번 부터)
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				dfs(i, j);
				k++;
			}
		}
	}

	for (i = 2; i < k; i++)
		bfs(i);

	printf("%d\n", ans);

	return 0;
}