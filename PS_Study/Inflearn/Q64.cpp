#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, map[21][21], ch[21], cnt = 0;

void DFS(int v)
{
	int i;

	if (v == n)
		cnt++;
	else
	{
		for (i = 1; i <= n; i++)
		{
			if (map[v][i] == 1 && ch[i] == 0)
			{
				ch[i] = 1;
				DFS(i);
				ch[i] = 0;
			}
		}
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i, s, e;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &s, &e);

		map[s][e] = 1;
	}

	ch[1] = 1;
	DFS(1);

	printf("%d\n", cnt);

	return 0;
}