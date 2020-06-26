#include <cstdio>
#include <algorithm>
using namespace std;
#define x first
#define y second

int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
int map[30][30], ck[30][30], cnt[625], th = 1;

void dfs(int x, int y)
{
	int i;
	ck[x][y] = th;
	for (i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (map[xx][yy] && !ck[xx][yy]) 
			dfs(xx, yy);
	}
}

int main(void)
{
	int n, i, j;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%1d", &map[i][j]);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j] && !ck[i][j]) {
				dfs(i, j);
				th++;
			}
		}
	}

	for (i = 1; i <= n; i++) 
		for (j = 1; j <= n; j++) 
			cnt[ck[i][j]]++;

	printf("%d\n", th-1);
	sort(cnt+1, cnt+th);
	for (i = 1; i < th; i++)
		printf("%d\n", cnt[i]);

	return 0;
}