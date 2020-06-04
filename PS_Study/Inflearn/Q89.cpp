#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 2147000000
#define MIN -2147000000

int map[1001][1001], ch[1001][1001];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

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

queue<Pos> ripe;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int m, n, i, j, a, rst = MIN;

	scanf("%d %d", &m, &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a);
			map[i][j] = a;

			if (a == 1)
				ripe.push(Pos(i, j));
		}
	}

	while (!ripe.empty())
	{
		Pos tmp = ripe.front();
		ripe.pop();

		for (i = 0; i < 4; i++)
		{
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			
			if (map[xx][yy] == 0 && xx >= 1 && xx <= n && yy >= 1 && yy <= m)
			{
				ripe.push(Pos(xx, yy));
				map[xx][yy] = 1;
				ch[xx][yy] = ch[tmp.x][tmp.y] + 1;
			}
		}
	}

	bool flag = false;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (map[i][j] == 0)
			{
				flag = true;
				break;
			}
		}

		if (flag)
			break;
	}

	if(flag)
		printf("-1\n");
	else
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (ch[i][j] > rst)
					rst = ch[i][j];
			}
		}

		printf("%d\n", rst);
	}

	return 0;
}