#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int n, i, num, cnt = 0;

	scanf("%d", &n);

	for (i = 10; i <= n; i++)
	{
		num = i;

		while (num)
		{
			if (num % 10 == 3)
				cnt++;

			num /= 10;
		}
	}

	printf("%d\n", cnt);

	return 0;
}