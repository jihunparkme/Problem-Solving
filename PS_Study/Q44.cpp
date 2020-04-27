#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, c, i, lt = 1, rt, mid, cnt, pos, rst;

	scanf("%d %d", &n, &c);
	vector<int> vt(n + 1);
	for (i = 1; i <= n; i++)
		scanf("%d", &vt[i]);
	
	sort(vt.begin(), vt.end());
	rt = *(vt.end()-1);

	while (lt <= rt)
	{
		cnt = 1;
		pos = 1;

		mid = (lt + rt) / 2;
		
		/*while (pos < n)
		{
			for (i = pos; i < n; i++)
			{
				if (vt[i + 1] - vt[pos] >= mid)
				{
					cnt++;
					pos = i + 1;
					break;
				}
			}

			if (i == n)
				break;
		}*/

		for (i = 2; i <= n; i++)
		{
			if (vt[i] - vt[pos] >= mid)
			{
				cnt++;
				pos = i;
			}
		}

		if (cnt >= c)
		{
			rst = mid;
			lt = mid + 1;
		}
		else
			rt = mid - 1;
	}

	printf("%d\n", rst);

	return 0;
}