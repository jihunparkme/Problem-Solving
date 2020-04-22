#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int n, i, p, num, cnt;

	scanf("%d", &n);
	vector<int> v(n + 1);

	for (i = 2; i <= n; i++)
	{
		num = i;
		p = 2;

		while (num != 1)
		{
			if (num % p == 0)
			{
				v[p]++;
				num /= p;
			}
			else
				p++;
		}
	}

	cnt = v[2] > v[5] ? v[5] : v[2];

	printf("%d\n", cnt);

	return 0;
}