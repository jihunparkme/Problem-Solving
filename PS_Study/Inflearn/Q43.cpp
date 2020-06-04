#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, m, i, lt = 0, rt, mid, rst = 0;

	scanf("%d %d", &n, &m);
	vector<int> vt(n+1);
	for (i = 1; i <= n; i++)
		scanf("%d", &vt[i]);

	rt = n;

	while (m > 0)
	{
		mid = (lt + rt) / 2;
		lt = mid + 1;

		m--;
	}

	for (i = lt-1; i <= rt; i++)
		rst += vt[i];
	
	printf("%d\n", rst);

	return 0;
}