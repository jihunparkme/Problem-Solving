#include <cstdio>
#include <queue>
using namespace std;
#define pos pair<int, int>
#define x first
#define y second

int map[1010][1010];
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

int main(void)
{
	int m, n, i, j, res = 0, cnt = 0;
	// freopen("input.txt", "rt", stdin);
	scanf("%d %d", &m, &n);

	queue<pos> Q;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1) {
				Q.push({ i,j });
				cnt++;
			}
		}
	}

	while (!Q.empty()) {
		int tmp = cnt;
		cnt = 0;

		for (j = 0; j < tmp; j++) {
			pos now = Q.front();
			Q.pop();

			for (i = 0; i < 4; i++) {
				int xx = now.x + dx[i];
				int yy = now.y + dy[i];

				if (map[xx][yy] == 0 && xx > 0 && xx <= n && yy > 0 && yy <= m) {
					Q.push({ xx,yy });
					map[xx][yy] = 1;
					cnt++;
				}
			}
		}

		res++;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", res - 1);

	return 0;
}