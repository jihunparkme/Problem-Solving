#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cost = 0, ch[101];

struct Info
{
	int v;
	int wt;

	Info(int a, int b)
	{
		v = a;
		wt = b;
	}

	bool operator<(const Info& d) const
	{
		return wt > d.wt;
	}
};

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int v, e, i, a, b, c, tmpV, tmpCost;
	vector<Info> road[101];
	priority_queue<Info> pQ;

	scanf("%d %d", &v, &e);
	for (i = 0; i < e; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		road[a].push_back(Info(b, c));
		road[b].push_back(Info(a, c));
	}

	pQ.push(Info(1, 0));

	while(!pQ.empty())
	{
		Info tmpInfo = pQ.top();
		pQ.pop();

		tmpV = tmpInfo.v;
		tmpCost = tmpInfo.wt;

		if (ch[tmpV] == 0)
		{
			cost += tmpCost;
			ch[tmpV] = 1;
			
			for (i = 0; i < road[tmpV].size(); i++)
				if (ch[road[tmpV][i].v] == 0)
					pQ.push(Info(road[tmpV][i].v, road[tmpV][i].wt));
		}
	}

	printf("%d\n", cost);

	return 0;
}