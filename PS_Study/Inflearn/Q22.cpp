#include <cstdio>

int temp[100000];

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, k, i, max = -2147000000, sum = 0;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
		scanf("%d", &temp[i]);
	
	for (i = 0; i < k; i++)
		sum += temp[i];

	for (i = k; i < n; i++)
	{
		sum = sum + temp[i] - temp[i - k];

		max = sum > max ? sum : max;
	}

	printf("%d\n", max);

	return 0;
}