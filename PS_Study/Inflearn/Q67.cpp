#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, rst = 2147000000;
int map[21][21], ch[21];

void DFS(int v, int sum)
{
	int i;

	if (v == n)
	{
		if (rst > sum)
			rst = sum;
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			if (map[v][i] > 0 && ch[i] == 0)
			{
				ch[i] = 1;
				DFS(i, sum + map[v][i]);
				ch[i] = 0;
			}
		}
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i, a, b, w;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &w);

		map[a][b] = w;
	}

	ch[1] = 1;

	DFS(1, 0);

	printf("%d\n", rst);

	return 0;
}