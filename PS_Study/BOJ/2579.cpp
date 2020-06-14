#include <cstdio>
int max(int p, int q) { return p > q ? p : q; }

int A[301], DP[301];
int main(void)
{
	int n, i, res = 0;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		DP[i] = max(DP[i - 2], DP[i - 3] + A[i - 1]) + A[i];
	}
	
	printf("%d\n", DP[n]);

	return 0;
}