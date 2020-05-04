#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n;
	priority_queue<int, vector<int>, greater<int> > pQ;

	while (true)
	{
		scanf("%d", &n);

		if (n == -1)
			break;

		if (n == 0)
		{
			if (pQ.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", pQ.top());
				pQ.pop();
			}
		}
		else
			pQ.push(n);
	}

	return 0;
}