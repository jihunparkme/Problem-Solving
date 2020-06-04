#include <cstdio>

int stu[100];

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, i, cnt = 0, max;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &stu[i]);

	max = stu[n - 1];

	for (i = n - 2; i >= 0; i--)
	{
		if (stu[i] > max)
		{
			cnt++;
			max = stu[i];
		}
	}

	printf("%d\n", cnt);

	return 0;
}