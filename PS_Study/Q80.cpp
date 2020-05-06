#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 2147000000
#define MIN -2147000000

int ch[21];

struct Info
{
	int v;
	int w;
	Info(int a, int b)
	{
		v = a;
		w = b;
	}
	bool operator<(const Info& b) const
	{
		return w > b.w;
	}
};

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, m, i, j, a, b, c;

	scanf("%d %d", &n, &m);
	vector<int> dist(n + 1, MAX);
	vector<pair<int, int> > gl[21];
	priority_queue<Info> pQ;

	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		gl[a].push_back({ b, c });
	}

	dist[1] = 0;
	for (i = 1; i <= n; i++)
		pQ.push(Info(i, dist[i]));

	for (i = 1; i <= n; i++)
	{
		Info tmp = pQ.top();
		pQ.pop();

		int tmpx = tmp.v;
		int tmpw = tmp.w;

		for (j = 0; j < gl[tmpx].size(); j++)
		{
			int f = gl[tmpx][j].first;
			int s = gl[tmpx][j].second;

			if (dist[f] > dist[tmpx] + s)
			{
				dist[f] = dist[tmpx] + s;

				pQ.push(Info(f, dist[f]));
			}
		}

		ch[tmpx] = 1;
	}


	for (i = 2; i <= n; i++)
	{
		if (dist[i] != MAX)
			printf("%d : %d\n", i, dist[i]);
		else
			printf("%d : impossible\n", i);
	}

	return 0;
}