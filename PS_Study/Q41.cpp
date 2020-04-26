#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int n, p, i, j, cnt = 0, sum;

	scanf("%d", &n);

	p = n / 2;

	while (p > 0)
	{
		sum = 0;

		for (i = p; i <= n; i++)
		{
			sum += i;

			if (sum >= n)
				break;
		}

		if (sum == n)
		{
			cnt++;

			printf("%d ", p);

			for (j = p + 1; j <= i; j++)
				printf("+ %d ", j);

			printf(" = %d\n", n);
		}

		p--;
	}

	printf("%d\n", cnt);

	return 0;
}