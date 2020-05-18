#include <cstdio>

int child[10], tmp[10];
int tc, n;

void teacher()
{
	int i;
	for (i = 0; i < n; i++)
	{
		child[i] /= 2;
		tmp[(i + 1) % n] = child[i];
	}

	for (i = 0; i < n; i++)
	{
		child[i] += tmp[i];

		if (child[i] & 1)
			child[i]++;
	}
}

bool check()
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		if (child[i] != child[i + 1])
			return false;
	}

	return true;
}

int main(void)
{
	int i, j, cnt;

	scanf("%d", &tc);
	while(tc--)
	{
		cnt = 0;

		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &child[j]);
			if (child[j] & 1)
				child[j]++;
		}

		while (true)
		{
			if (check())
			{
				printf("%d\n", cnt);
				break;
			}

			teacher();

			cnt++;
		}
	}

	return 0;
}