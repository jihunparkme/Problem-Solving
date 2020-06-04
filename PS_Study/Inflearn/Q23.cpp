#include <cstdio>
#include <vector>

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, i, sum = 1, max = 1;

	scanf("%d", &n);
	std::vector<int> v(n);

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (i = 1; i < n; i++)
	{
		if (v[i] >= v[i - 1])
		{
			sum++;

			max = sum > max ? sum : max;
		}
		else
			sum = 1;
	}

	printf("%d\n", max);
		
	return 0;
}