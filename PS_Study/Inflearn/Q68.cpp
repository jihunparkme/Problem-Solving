#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, rst = 2147000000;
int ch[21];
vector<pair<int, int> > map[21];

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
		for (i = 0; i < map[v].size(); i++)
		{
			if (ch[map[v][i].first] == 0)
			{
				ch[map[v][i].first] = 1;
				DFS(map[v][i].first, sum + map[v][i].second);
				ch[map[v][i].first] = 0;
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

		map[a].push_back({ b, w });
	}

	ch[1] = 1;

	DFS(1, 0);

	printf("%d\n", rst);

	return 0;
}