#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int n, k, i;

	scanf("%d %d", &n, &k);
	queue<int> q;

	for (i = 1; i <= n; i++)
		q.push(i);

	while (q.size() != 1)
	{
		for (i = 1; i < k; i++)
		{
			q.push(q.front());
			q.pop();
		}

		q.pop();
	}

	printf("%d\n", q.back());

	return 0;
}