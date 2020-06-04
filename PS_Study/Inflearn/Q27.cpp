#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j;

	scanf("%d", &n);
	vector<int> v(n+1);

	for (i = n; i >= 2; i--)
	{
		int num = i;

		for (j = 2; j <= n; j++)
		{
			while(num % j == 0)
			{
				v[j]++;
				num /= j;
			}

			if (num == 1)
				break;
		}
	}

	printf("%d! = ", n);

	bool isPrime;

	for (i = 2; i <= n; i++)
	{
		isPrime = true;

		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;

				break;
			}
		}

		if(isPrime)
			printf("%d ", v[i]);
	}

	puts("");

	return 0;
}