#include <cstdio>
#include <cstring>
using namespace std;

int w, h;
int map[55][55];
bool ck[55][55];
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void dfs(int x, int y)
{
	ck[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (map[xx][yy] && !ck[xx][yy])
			dfs(xx, yy);
	}
}

void process()
{
	int i, j, res = 0;
	memset(map, 0, sizeof(map));
	memset(ck, 0, sizeof(ck));

	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			if (map[i][j] && !ck[i][j]) {
				dfs(i, j);
				res++;
			}
		}
	}

	printf("%d\n", res);
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	while (scanf("%d %d", &w, &h), w && h)
		process();

	return 0;
}