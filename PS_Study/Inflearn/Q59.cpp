#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, a[11];

void DFS(int x)
{
	if (x == N + 1)
	{
		int i;

		for (i = 1; i <= N; i++)
		{
			if (a[i] == 1)
				printf("%d ", i);
		}

		puts("");
	}
	else
	{
		a[x] = 1;
		DFS(x+1);

		a[x] = 0;
		DFS(x+1);
	}
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &N);

	DFS(1);

	return 0;
}