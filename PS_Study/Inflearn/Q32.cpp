#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, tmp;

	scanf("%d", &n);
	vector<int> v(n);

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (v[i] > v[j])
			{
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);

	puts("");

	return 0;
}