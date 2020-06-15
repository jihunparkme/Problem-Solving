#include <cstdio>
int min(int p, int q) { return p > q ? q : p; }
int DP[100001];
int main(void)
{
	int n, i, j;
	// freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		DP[i] = i;
		for (j = 1; j * j <= i; j++) {
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}

	printf("%d\n", DP[n]);
	return 0;
}