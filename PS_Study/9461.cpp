#include <cstdio>

int main(void)
{
	int tc, n, i;
	long long DP[101] = { 0, 1, 1, 1, 2, 2, 3, };
	// freopen("input.txt", "rt", stdin);

	for (i = 7; i <= 100; i++) 
		DP[i] = DP[i - 3] + DP[i - 2]; 

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		printf("%lld\n", DP[n]);
	}


	return 0;
}