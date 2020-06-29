#include <cstdio>
using namespace std;
#define mod 1000000000

int DP[201][201];

int main(void)
{
	int n, k, i, j;
	scanf("%d %d", &n, &k);

	for (i = 1; i <= k; i++)
		DP[0][i] = 1;

	for (i = 1; i <= n; i++) 
		for (j = 1; j <= k; j++) 
			DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % mod;
		
	printf("%d\n", DP[n][k]);

	return 0;
}