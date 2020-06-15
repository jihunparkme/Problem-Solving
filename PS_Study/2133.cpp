#include <cstdio>
#define ll long long
ll DP[31] = { 0, 0, 3, };

int main(void)
{
	int n, i;
	scanf("%d", &n);
	if (n % 2 != 0) {
		printf("0\n");
		return 0;
	}

	for (i = 4; i <= n; i+=2) {
		DP[i] = DP[i - 2] * DP[2];
	}

	printf("%lld\n", DP[n]);

	return 0;
}