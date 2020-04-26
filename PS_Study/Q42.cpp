#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, m, i, start = 1, end, idx;

	scanf("%d %d", &n, &m);
	vector<int> vt(n + 1);
	
	for (i = 1; i <= n; i++)
		scanf("%d", &vt[i]);
	
	sort(vt.begin(), vt.end());

	end = n;

	while (1)
	{
		idx = (start + end) / 2;

		if (vt[idx] == m)
		{
			printf("%d\n", idx);
			break;
		}
		else if (vt[idx] > m)
			end = idx - 1;
		else
			start = idx + 1;
	}

	return 0;
}