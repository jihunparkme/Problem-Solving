#include <cstdio>

//////////////////////////////////
// Botton-Up
/////////////////////////////////

int dp[50] = { 0, 1, 2, };

int main(void)
{
	int n, i;
	scanf("%d", &n);

	for (i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	printf("%d\n", dp[n]);

	return 0;
}


//////////////////////////////////
// Top-Down
//////////////////////////////////

int dp[50];

int DFS(int n) 
{
	if (dp[n]) return dp[n];
	if (n == 1 || n == 2) return n;

	return dp[n] = DFS(n - 2) + DFS(n - 1);
}

int main(void)
{
	int n;

	scanf("%d", &n);

	printf("%d\n", DFS(n));

	return 0;
}