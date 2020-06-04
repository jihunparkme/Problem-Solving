#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, m, i, lt = 1, rt = 0, mid, sum = 0, rst, cnt, max = -2147000000;

	scanf("%d %d", &n, &m);
	vector<int> vt(n + 1);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &vt[i]);
		sum += vt[i];
		max = vt[i] > max ? vt[i] : max;
	}

	rt = sum;
	rst = sum;

	while (lt <= rt)
	{
		mid = (lt + rt) / 2;
		sum = 0;
		cnt = 1;

		for (i = 1; i <= n; i++)
		{
			sum += vt[i];

			if (sum > mid)
			{
				sum = vt[i];
				cnt++;
			}
		}

		if (mid >= max && cnt <= m)
		{
			rt = mid - 1;
			rst = mid;
		}
		else 
			lt = mid + 1;
	}

	printf("%d\n", rst);

	return 0;
}