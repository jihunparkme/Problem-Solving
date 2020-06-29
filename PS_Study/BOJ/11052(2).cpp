#include <cstdio>
using namespace std;
int max(int p, int q) { return p > q ? p : q; }

int DP[1001];

int main(void)
{
	int n, i, j;
	// freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &DP[i]);

	for (i = 1; i <= n; i++) 
 		for (j = 1; j <= i/2; j++) 
			DP[i] = max(DP[i], DP[i-j] + DP[j]);

	printf("%d\n", DP[n]);

	return 0;
}