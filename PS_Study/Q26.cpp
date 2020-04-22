#include <cstdio>
#include <vector>

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, rank = 1;

	scanf("%d", &n);
	std::vector<int> v(n);

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	printf("1 ");

	for (i = 1; i < n; i++)
	{
		rank = 1;

		for (j = 0; j < i; j++)
		{
			if (v[i] <= v[j])
				rank++;
		}

		printf("%d ", rank);
	}

	puts("");

	return 0;
}