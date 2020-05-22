#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 2147000000
#define MIN -2147000000
int n, map[10][10], ch[10][10];
int dx[5] = { 0, -1, 1, 0, 0 }, dy[5] = { 0, 0, 0, -1, 1 };
int Solve(const int lst[])
{
	int i, j, sum = 0;
	for (i = 0; i < 3; i++)
	{
		int x = lst[i] / n;
		int y = lst[i] % n;
		if (x == 0 || x == n - 1 || y == 0 || y == n - 1)
			return MAX;
		for (j = 0; j < 5; j++)
		{
			int xx = x + dx[j];
			int yy = y + dy[j];
			if (ch[xx][yy] == 1)
				return MAX;
			else
				ch[xx][yy] = 1;
			sum += map[xx][yy];
		}
	}
	return sum;
}
int main(void)
{
	int i, j, k, a, b, res = MAX;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	}
	for (i = 0; i < n * n; i++)
	{
		for (j = i + 1; j < n * n; j++)
		{
			for (k = j + 1; k < n * n; k++)
			{
				int lst[3] = { i, j, k };
				res = min(res, Solve(lst));
				for (a = 0; a < n; a++)
				{
					for (b = 0; b < n; b++)
						ch[a][b] = 0;
				}
			}
		}
	}
	printf("%d\n", res);
	return 0;
}