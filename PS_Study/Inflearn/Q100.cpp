#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2147000000
#define MIN -2147000000

int main(void)
{
	int N, M, i, j;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &N);
	vector<int> coin(N);
	for (i = 0; i < N; i++)
		scanf("%d", &coin[i]);
	
	scanf("%d", &M);
	vector<int> dp(M + 1, MAX);
	dp[0] = 0;

	for (i = 0; i < N; i++) {
		for (j = coin[i]; j <= M; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	printf("%d\n", dp[M]);

	return 0;
}