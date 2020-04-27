#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, k, i, j;

	scanf("%d %d", &n, &k);
	queue<int> in, rst;
	for (i = 1; i <= n; i++)
		in.push(i);

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < k - 1; j++)
		{
			in.push(in.front());
			in.pop();
		}

		rst.push(in.front());
		in.pop();
	}

	printf("%d\n", in.front());
		
	return 0;
}