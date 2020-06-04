#include <cstdio>
#include <cmath>

bool isNotPrm[200001];

int main()
{
	freopen("input.txt", "rt", stdin);
	int n, i, j, cnt = 0;

	scanf("%d", &n);

	for (i = 2; i <= n; i++)
	{
		if (isNotPrm[i] == false)
		{
			for (j = i * 2; j <= n; j += i)
				isNotPrm[j] = true;
		}
	}

	for (i = 2; i <= n; i++)
	{
		if (isNotPrm[i] == false)
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}