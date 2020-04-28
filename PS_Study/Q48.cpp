#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 9;
int grid[N][N];
int avg[N];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i, j, rst, diff, total, min;

	for (i = 0; i < N; i++)
	{
		total = 0;

		for (j = 0; j < N; j++)
		{
			scanf("%d", &grid[i][j]);

			total += grid[i][j];
		}

		avg[i] = float(total) / N + .5;
	}

	for (i = 0; i < N; i++)
	{
		rst = -21470000;
		min = 21470000;

		for (j = 0; j < N; j++)
		{
			diff = abs(avg[i] - grid[i][j]);

			if (diff < min)
			{
				rst = grid[i][j];
				min = diff;
			}
			else if (diff == min)
				rst = rst > grid[i][j] ? rst : grid[i][j];
		}

		printf("%d %d\n", avg[i], rst);
	}

	return 0;
}