#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, k, i, pos = 0, cnt = 0;

	scanf("%d %d", &n, &k);
	vector<int> vt(n+1);

	while (cnt < n - 1)
	{
		for (i = 1; i <= k; i++)
		{
			pos++;

			if (pos > n)
				pos = 1;

			if (vt[pos] == 0)
			{
				if (i == k)
				{
					vt[pos] = 1;
					cnt++;
				}
			}
			else
				i--;
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (vt[i] == 0)
		{
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}