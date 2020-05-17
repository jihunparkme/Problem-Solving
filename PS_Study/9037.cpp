#include <cstdio>

int child[11], tmp[11];

int main(void)
{
	int tc, n, i, j, cnt;

	scanf("%d", &tc);
	for (i = 0; i < tc; i++)
	{
		cnt = 0;

		scanf("%d", &n);
		for (j = 0; j < n; j++)
			scanf("%d", &child[j]);

		while (true)
		{
			for (j = 0; j < n; j++)
			{
				if (child[j] % 2)
					child[j]++;
			}

			bool flag = true;
			for (j = 0; j < n-1; j++)
			{
				if (child[j] != child[j + 1])
					flag = false;
			}

			if (flag)
				break;

			for (j = 0; j < n; j++)
			{
				child[j] /= 2;
				tmp[(j + 1) % n] = child[j];
			}
			
			for (j = 0; j < n; j++)
			{
				child[j] += tmp[j];
			}

			cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}