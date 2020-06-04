#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int N, K, map[100][100];
bool ck[100][100], ck2[100][100];

int DFS(int x, int y)
{
	int cnt = 1;
	ck[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= 10) continue;
		if (ck[xx][yy] || map[xx][yy] != map[x][y]) continue;

		cnt += DFS(xx, yy);
	}

	return cnt;
}

void DFSZ(int x, int y)
{
	ck2[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= 10) continue;
		if (ck2[xx][yy] || map[xx][yy] != map[x][y]) continue;

		DFSZ(xx, yy);
	}

	map[x][y] = 0;
}

void Down()
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		vector<int> vt;

		for (j = 0; j < N; j++)
		{
			if (map[j][i])
				vt.push_back(map[j][i]);
		}

		for (j = 0; j < N - vt.size(); j++)
			map[j][i] = 0;

		for (j = N - vt.size(); j < N; j++)
			map[j][i] = vt[j - (N - vt.size())];
	}
}

int main(void)
{
	int i, j;
	bool changed;
	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
		for (j = 0; j < 10; j++)
			scanf("%1d\n", &map[i][j]);

	while (true)
	{
		changed = false;
		memset(ck, false, sizeof(ck));
		memset(ck2, false, sizeof(ck2));

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (!map[i][j] || ck[i][j]) continue;
				int cnt = DFS(i, j); // Find

				if (cnt >= K)
				{
					changed = true;
					DFSZ(i, j);	// Delete
				}
			}
		}

		if (!changed)
			break;

		Down();	// Down
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 10; j++)
			printf("%d", map[i][j]);

		puts("");
	}

	return 0;
}