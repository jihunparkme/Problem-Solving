#include <cstdio>

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, i, num, ans, rst;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &num, &ans);

		rst = (num * (num + 1)) / 2;

		if (rst == ans)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}