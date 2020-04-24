#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, key;

	scanf("%d", &n);
	vector<int> v(n);

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (i = 1; i < n; i++)
	{
		j = i - 1;
		key = v[i];
		
		while (j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			j--;
		}

		v[j + 1] = key;
	}

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);

	return 0;
}