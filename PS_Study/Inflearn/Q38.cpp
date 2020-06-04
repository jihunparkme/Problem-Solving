#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, i, j, pos, tmp;

	scanf("%d", &n);
	vector<int> v(n + 1);
	vector<int> rst(n + 1);

	for (i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	for (i = 1; i <= n; i++)
	{
		pos = 0;

		for (j = 1; j < n; j++)
		{
			if (rst[j] == 0 || rst[j] > i)
			{
				if (pos == v[i])
					break;

				pos++;
			}	
		}

		for (; j <= n; j++)
		{
			if (!rst[j])
			{
				rst[j] = i;
				break;
			}
		}
	}


	for (i = 1; i <= n; i++)
		printf("%d ", rst[i]);
	
	return 0;
}