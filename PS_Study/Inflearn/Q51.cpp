#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int W, H, sW, sH;
int dp[701][701];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int  i, j, tmp, sum, rst = -2147000000;

	scanf("%d %d", &H, &W);

	for (i = 1; i <= H; i++)
	{
		for (j = 1; j <= W; j++)
		{
			scanf("%d", &tmp);

			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + tmp;
		}
	}

	scanf("%d %d", &sH, &sW);

	for (i = sH; i <= H; i++)
	{
		for (j = sW; j <= W; j++)
		{
			sum = dp[i][j] - dp[i - sH][j] - dp[i][j - sW] + dp[i - sH][j - sW];

			if (sum > rst)
				rst = sum;
		}
	}

	printf("%d\n", rst);

	return 0;
}