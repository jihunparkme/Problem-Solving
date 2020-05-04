#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ch[10001], mv[3] = { 1, 5, -1 };

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int s, e, i, x, pos, rst = 0;
	bool endFlag;
	queue<int> q;

	scanf("%d %d", &s, &e);

	q.push(s);

	while (!q.empty())
	{
		x = q.front();
		q.pop();
		endFlag = false;

		for (i = 0; i < 3; i++)
		{
			pos = x + mv[i];

			if (pos == e)
			{
				endFlag = true;

				break;
			}

			if (ch[pos] == 0)
			{
				q.push(pos);
				ch[pos] = ch[x] + 1;
			}
		}

		if (endFlag)
		{
			rst = ch[x] + 1;

			break;
		}
	}

	printf("%d\n", rst);

	return 0;
}