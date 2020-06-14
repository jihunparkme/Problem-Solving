#include <cstdio>

int min(int p, int q) { return p > q ? q : p; }

int DP[100001];

int main(void)
{
	int n, i, j;
	// freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		DP[i] = i;

	for (i = 1; i*i <= n; i++) {
		for (j = i*i; j <= n; j++) {
			DP[j] = min(DP[j], DP[j - i * i] + 1);
		}
	}

	printf("%d\n", DP[n]);

	return 0;
}