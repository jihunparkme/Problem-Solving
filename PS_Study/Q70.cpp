#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dst[21];
vector<int> map[21];
queue<int> q;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, m, a, b, i, x;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);

		map[a].push_back(b);
	}

	q.push(1);

	while (!q.empty())
	{
		x = q.front();
		q.pop();

		for (i = 0; i < map[x].size(); i++)
		{
			if (dst[map[x][i]] == 0)
			{
				q.push(map[x][i]);
				dst[map[x][i]] = dst[x] + 1;
			}
		}
	}

	for (i = 2; i <= n; i++)
		printf("%d : %d\n", i, dst[i]);

	return 0;
}