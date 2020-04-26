#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int n, i, num = 2, sum, tmp = 1, base, cnt = 0;

	scanf("%d", &n);

	while (tmp > 0)
	{
		sum = 0;

		for (i = 1; i <= num; i++)
			sum += i;

		tmp = n - sum;

		if (tmp % num == 0)
		{
			base = tmp / num;

			printf("%d ", base + 1);

			for (i = base + 2; i <= base + num; i++)
				printf("+ %d ", i);
			
			printf("= %d\n", n);

			cnt++;
		}

		num++;
	}

	printf("%d\n", cnt);

	return 0;
}