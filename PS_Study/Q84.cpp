#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define t first
#define p second
#define MAX 2147000000
#define MIN -2147000000

int n, cost = 0, income = MIN;
vector<pair<int, int> > vt(16);

void DFS(int day, int cost)
{
	int i;

	if (day > n)
	{
		if (cost > income)
			income = cost;
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			if (day <= i)
			{
				if (i + vt[i].t > n + 1)
				{
					DFS(i + vt[i].t, cost);
					return;
				}

				DFS(i + vt[i].t, cost + vt[i].p);
			}
		}
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i, a, b;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		vt[i] = { a, b };
	}

	DFS(0, 0);

	printf("%d\n", income);

	return 0;
}