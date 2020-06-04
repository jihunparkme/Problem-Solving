#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int n, cnt = 0, t = 1, p, ln = 1, rn = 1;

	scanf("%d", &n);

	while (n / t * 10)
	{
		ln = n / (t * 10);
		rn = n % t; 
		p = (n % (t * 10)) / t;

		if (p > 3)
			cnt += (ln + 1)*t;
		else if (p == 3)
			cnt += ln*t + rn + 1;
		else
			cnt += ln*t;

		t *= 10;
	}

	printf("%d\n", cnt);

	return 0;
}