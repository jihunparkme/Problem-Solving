#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int W, H, sW, sH;
int map[51][51];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int  i, j, k, h, sum, rst = -21470000;

	scanf("%d %d", &W, &H);
	for (i = 1; i <= W; i++)
	{
		for (j = 1; j <= H; j++)
			scanf("%d", &map[i][j]);
	}
	scanf("%d %d", &sW, &sH);

	for (i = 1; i <= W - sW + 1; i++)
	{
		for (j = 1; j <= H - sH + 1; j++)
		{
			sum = 0;

			for (k = i; k < i + sW; k++)
			{
				for (h = j; h < j + sH; h++)
				{
					sum += map[k][h];
				}
			}

			if (sum > rst)
				rst = sum;
		}
	}

	printf("%d\n", rst);

	return 0;
}