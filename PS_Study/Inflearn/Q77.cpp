#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, parent[1001];

int Find(int v)
{
	if (parent[v] == v)
		return v;
	else
		return parent[v] = Find(parent[v]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y)
		parent[x] = y;
}

void Set()
{
	int i;

	for (i = 1; i <= n; i++)
		parent[i] = i;
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int m, i,a, b;

	scanf("%d %d", &n, &m);

	Set();

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);

		Union(a, b);
	}

	scanf("%d %d", &a, &b);
	if (Find(a) == Find(b))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}