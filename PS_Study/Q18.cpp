#include <cstdio>

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, m, i, cnt = 0, val, max = -2147000000;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &val);

		if (val > m)
			cnt++;
		else
			cnt = 0;

		max = max < cnt ? cnt : max;
	}
	
	if (max)
		printf("%d\n", max);
	else
		printf("-1\n");

	return 0;
}