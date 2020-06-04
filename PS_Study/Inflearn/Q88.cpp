#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 2147000000
#define MIN -2147000000

int n = 7, rst = MAX, map[10][10], cnt[10][10];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {0, 1, 0, -1 };

struct Pos
{
	int x;
	int y;
	Pos(int a, int b)
	{
		x = a;
		y = b;
	}
};

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i, j,  k;
	queue<Pos> q;
	fill(&map[0][0], &map[n - 1][n], 1);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (map[i][j] == 0)
			{
				q.push(Pos(i, j));
				map[i][j] = 1;

				while (!q.empty())
				{
					Pos tmp = q.front();
					q.pop();

					for (k = 0; k < 4; k++)
					{
						int xx = tmp.x + dx[k];
						int yy = tmp.y + dy[k];

						if (map[xx][yy] == 0)
						{
							q.push(Pos(xx, yy));
							map[xx][yy] = 1;
							cnt[xx][yy] = (cnt[tmp.x][tmp.y]) + 1;
						}

						if (xx == 7 && yy == 7)
							if (rst > cnt[xx][yy])
								rst = cnt[xx][yy];
					}
				}
			}
		}
	}

	if (rst == 0)
		printf("-1\n");
	else
		printf("%d\n", rst);

	return 0;
}