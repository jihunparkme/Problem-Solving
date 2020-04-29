#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, k, mod;

	scanf("%d %d", &n, &k);
	vector<int> vt;

	while (1)
	{
		mod = n % k;
		n /= k;

		vt.push_back(mod);

		if (n/k == 0)
		{
			vt.push_back(n);

			break;
		}
	}

	if (k == 16)
	{
		while (!vt.empty())
		{
			int tmp = *(vt.end() - 1);

			if(tmp >= 10)
				printf("%c", tmp + 55);
			else
				printf("%d", tmp);
			vt.pop_back();
		}
	}
	else
	{
		while (!vt.empty())
		{
			printf("%d", *(vt.end() - 1));
			vt.pop_back();
		}
	}

	return 0;
}