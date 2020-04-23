#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, idx, tmp, rank = 1;

	scanf("%d", &n);
	vector<int> v(n);

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (i = 0; i < n - 1; i++)
	{
		idx = i;

		for (j = i + 1; j < n; j++)
		{
			if (v[j] > v[idx])
				idx = j;
		}

		tmp = v[i];
		v[i] = v[idx];
		v[idx] = tmp;
	}

	for (i = 1; i < n; i++)
	{
		if (v[i] != v[i - 1])
			rank++;

		if (rank == 3)
		{
			printf("%d\n", v[i]);
			break;
		}
	}

	return 0;
}