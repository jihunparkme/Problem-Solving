#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define x first
#define y second

int cnt = 0;
int dx[9] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[9] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int map[22][22];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, k;
	pair<int, int> popTmp;
	queue<pair<int, int> > q;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (map[i][j] == 1)
			{
				q.push({ i, j });
				map[i][j] = 0;
			}
			else
				continue;

			while (!q.empty())
			{
				popTmp = q.front();
				q.pop();

				for (k = 0; k < 9; k++)
				{
					int tx = popTmp.x + dx[k];
					int ty = popTmp.y + dy[k];

					if (map[tx][ty] == 1)
					{
						q.push({ tx, ty });
						map[tx][ty] = 0;
					}
				}
			}

			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}