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
	
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (v[j] > 0 && v[j+1] < 0)
			{
				tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);

	return 0;
}