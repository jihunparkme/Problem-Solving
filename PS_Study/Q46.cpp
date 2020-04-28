#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i, pos = 0, cnt = 0, total = 0;

	scanf("%d", &N);
	vector<int> vt(N + 1);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &vt[i]);
		total += vt[i];
	}

	scanf("%d", &K);

	if (K >= total)
	{
		printf("-1\n");

		return 0;
	}

	while (cnt < K)
	{
		cnt++;

		while (1)
		{
			pos++;

			if (pos > N)
				pos = 1;

			if (vt[pos] != 0)
			{
				vt[pos]--;
				break;
			}
		}
	}

	while (1)
	{
		pos++;

		if (pos > N)
			pos = 1;

		if (vt[pos] != 0)
		{
			printf("%d\n", pos);
			
			break;
		}
	}

	return 0;
}