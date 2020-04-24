#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, cnt;

	scanf("%d", &n);
	vector<int> is(n + 1);
	vector<int> os(n + 1);

	for (i = 1; i <= n; i++)
		scanf("%d", &is[i]);

	for (i = n; i >= 0; i--)
	{
		cnt = 0;
		os[i] = i;
		
		for (j = i; i < n; j++)
		{
			if (cnt == is[i])
			{
				os[j] = i;
				break;
			}

			os[j] = os[j + 1];

			cnt++;
		}
	}

	for (i = 1; i <= n; i++)
		printf("%d ", os[i]);

	return 0;
}