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

	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (v[j] < v[j - 1])
			{
				tmp = v[j];
				v[j] = v[j - 1];
				v[j - 1] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);

	puts("");

	return 0;
}