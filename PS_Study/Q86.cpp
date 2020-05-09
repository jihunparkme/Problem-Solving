#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define x first
#define y second
#define MAX 2147000000
#define MIN -2147000000

int n, m, sum = 0, ch[13];
int rst = MAX;
vector<pair<int, int> > house, pizza;

void DFS(int s, int L)
{
	int i, j, htp, htpMin, htpTotalMin = 0;

	if (L == m)
	{
		for (i = 0; i < house.size(); i++)
		{
			htpMin = MAX;

			for (j = 0; j < m; j++)
			{
				htp = abs(house[i].x - pizza[ch[j]].x) + abs(house[i].y - pizza[ch[j]].y);

				if (htpMin > htp)
					htpMin = htp;
			}

			htpTotalMin += htpMin;
		}

		if (rst > htpTotalMin)
			rst = htpTotalMin;
	}
	else
	{
		for (i = s; i < pizza.size(); i++)
		{
			ch[L] = i;
			DFS(i + 1,  L + 1);
		}
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i, j, a; 

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &a);

			if (a == 1)
				house.push_back({ i, j });
			else if (a == 2)
				pizza.push_back({ i, j });
		}
	}

	DFS(0, 0);

	printf("%d\n", rst);

	return 0;
}