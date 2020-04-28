#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int grid[52][52];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, cnt = 0;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i][j + 1] &&
				grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i + 1][j])
				cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}