#include <cstdio>
#include <algorithm>
using namespace std;

int A[10001], DP[10001];

int main(void)
{
	int n, i;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &A[i]);

	DP[1] = A[1], DP[2] = A[1] + A[2];
	for (i = 3; i <= n; i++) 
		DP[i] = max(max(DP[i - 1], DP[i - 2] + A[i]), DP[i - 3] + A[i - 1] + A[i]);
	
	printf("%d\n", DP[n]);

	return 0;
}