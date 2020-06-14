#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define MAX 2147000000
#define MIN -2147000000

int A[100001], DP[100001];

int main(void)
{
	int n, i;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", A[i]);

		if (DP[i - 1] + A[i] > DP[i - 1])
			DP[i] = DP[i - 1] + A[i];
		else 
			DP[i] = 0;
	}

	printf("");
	return 0;
}