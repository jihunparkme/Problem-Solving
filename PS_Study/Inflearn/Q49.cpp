#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int block[10][10];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, tmp, sum = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);

		for (j = 0; j < n; j++)
			block[j][i] = tmp;
	}

	for (i = n - 1; i >= 0; i--)
	{
		scanf("%d", &tmp);
		
		for (j = n - 1; j >= 0; j--)
		{
			if (block[i][j] > tmp)
				block[i][j] = tmp;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			sum += block[i][j];
	}

	printf("%d\n", sum);

	return 0;
}