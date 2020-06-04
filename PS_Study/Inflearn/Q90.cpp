#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define MAX 2147000000
#define MIN -2147000000

int map[26][26], ch[26][26], res = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct State
{
	int x, y, dist;

	State(int a, int b, int c)
	{
		x = a;
		y = b;
		dist = c;
	}

	bool operator<(const State &s) const
	{
		if (dist != s.dist) 
			return dist > s.dist;
		if (x != s.x)
			return x > s.x;
		else
			return y > s.y;
	}
};

struct Simba
{
	int x, y, size, ate;

	void sizeUp()
	{
		size++;
		ate = 0;
	}
};

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j;
	priority_queue<State> pq;
	Simba simba;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);

			if (map[i][j] == 9)
			{
				simba.x = i;
				simba.y = j;
				map[i][j] = 0;
			}
		}
	} 

	simba.size = 2;
	simba.ate = 0;
	pq.push(State(simba.x, simba.y, 0));
	
	while (!pq.empty())
	{
		State tmp = pq.top();
		pq.pop();

		if (map[tmp.x][tmp.y] != 0 && map[tmp.x][tmp.y] < simba.size)
		{
			map[tmp.x][tmp.y] = 0;
			simba.ate++;

			simba.x = tmp.x;
			simba.y = tmp.y;

			if (simba.ate == simba.size)
				simba.sizeUp();

			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					ch[i][j] = 0;

			while (!pq.empty())
				pq.pop();

			res = tmp.dist;
		}

		for (i = 0; i < 4; i++)
		{
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];

			if (ch[xx][yy] == 0 && xx >= 1 && xx <=n && yy >= 1 && yy <= n 
				&& map[xx][yy] <= simba.size)
			{
				pq.push(State(xx, yy, tmp.dist + 1));
				ch[xx][yy] = 1;
			}
		}
	}

	printf("%d\n", res);

	return 0;
}