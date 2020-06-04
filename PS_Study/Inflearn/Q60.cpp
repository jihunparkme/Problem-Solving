#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, set[11], chk[11];

void DFS(int lv)
{
	int i, sum1 = 0, sum2 = 0;

	if (lv == N + 1)
	{
		for (i = 1; i <= N; i++)
		{
			if (chk[i] == 1)
				sum1 += set[i];
			else
				sum2 += set[i];
		}

		if (sum1 == sum2)
		{
			printf("YES\n");

			exit(0);
		}
	}
	else
	{
		chk[lv] = 1;
		DFS(lv + 1);

		chk[lv] = 0;
		DFS(lv + 1);
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i, sum = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &set[i]);

	DFS(1);

	printf("NO\n");

	return 0;
}