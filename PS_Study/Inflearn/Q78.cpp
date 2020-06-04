#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int v, cost = 0, parent[101];

struct info
{
	int s;
	int e;
	int w;
	info(int a, int b, int c)
	{
		s = a;
		e = b;
		w = c;
	}
	bool operator<(const info& d) const
	{
		return w < d.w;
	}
};

int Find(int v)
{
	if (parent[v] == v)
		return v;
	else
		return parent[v] = Find(parent[v]);
}

void Union(info& info)
{
	info.s = Find(info.s);
	info.e = Find(info.e);

	if (info.s != info.e)
	{
		parent[info.s] = info.e;

		cost += info.w;
	}
}

void Set()
{
	int i = 0;
	for (i = 1; i <= v; i++)
		parent[i] = i;
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int e, i, a, b, c;
	vector<info> vt;

	scanf("%d %d", &v, &e);
	Set();
	for (i = 0; i < e; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		vt.push_back(info(a, b, c));
	}

	sort(vt.begin(), vt.end());

	for (i = 0; i < e; i++)
		Union(vt[i]);

	printf("%d\n", cost);

	return 0;
}