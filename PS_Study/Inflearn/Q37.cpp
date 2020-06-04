#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int s, n, oper, i, j, tmp;

	scanf("%d %d", &s, &n);
	vector<int> cache(s);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &oper);

		for (j = 0; j < s; j++)
		{
			if (cache[j] == oper)
			{
				cache[j] = 0;
				break;
			}
		}

		for (j = 0; j < s; j++)
		{
			tmp = cache[j];
			cache[j] = oper;
			oper = tmp;

			if (!oper)
				break;
		}
	}

	for (j = 0; j < s; j++)
		printf("%d ", cache[j]);

	return 0;
}