#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ch[21], cnt = 0;
vector<int> map[21];

void DFS(int v)
{
	int i;

	if (v == n)
		cnt++;
	else
	{
		for (i = 0; i < map[v].size(); i++)
		{
			if (ch[map[v][i]] == 0)
			{
				ch[map[v][i]] = 1;
				DFS(map[v][i]);
				ch[map[v][i]] = 0;
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

		map[s].push_back(e);
	}

	ch[1] = 1;
	DFS(1);

	printf("%d\n", cnt);

	return 0;
}