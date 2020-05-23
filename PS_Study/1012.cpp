#include <cstdio>

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int map[52][52];

void DFS(int x, int y)
{
	int p, xx, yy;

	map[x][y] = 0;
	for (p = 0; p < 4; p++)
	{
		xx = x + dx[p];
		yy = y + dy[p];

		if (map[xx][yy])
			DFS(xx, yy);
	}
}

void process()
{
	int M, N, K, i, j, a, b, cnt = 0;
	scanf("%d %d %d", &M, &N, &K);

	while(K--)
	{
		scanf("%d %d", &a, &b);
		map[++a][++b] = 1;
	}

	for (i = 1; i <= M; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (map[i][j])
			{
				DFS(i, j);
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
}

int main(void)
{
	int tc;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);
	while(tc--)
		process();

	return 0;
}