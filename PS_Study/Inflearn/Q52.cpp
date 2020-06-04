#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int Ugly[1501];

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int n, i, p2 = 1, p3 = 1, p5 = 1, min, tmp2, tmp3, tmp5;

	scanf("%d", &n);

	Ugly[1] = 1;

	for (i = 2; i <= n; i++)
	{
		tmp2 = Ugly[p2] * 2;
		tmp3 = Ugly[p3] * 3;
		tmp5 = Ugly[p5] * 5;

		if (tmp2 < tmp3)
		{
			if (tmp2 < tmp5)
				min = tmp2;
			else
				min = tmp5;
		}
		else
		{
			if (tmp3 < tmp5)
				min = tmp3;
			else
				min = tmp5;
		}

		Ugly[i] = min;
		
		if (tmp2 == min) p2++;
		if (tmp3 == min) p3++;
		if (tmp5 == min) p5++;
	}

	printf("%d\n", Ugly[n]);

	return 0;
}