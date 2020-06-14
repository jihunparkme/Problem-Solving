#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
	int prev = 0, res = 0, dp = 0;
	int n, i, a;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (i == 1) res = a;

		if (prev + a > a) {
			dp = prev + a;
			prev = dp;
		}
		else {
			dp = a;
			prev = a;
		}
		
		if (dp > res)
			res = dp;
	}

	printf("%d\n", res);
	return 0;
}