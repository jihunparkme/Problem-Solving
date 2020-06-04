#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M, w, v, i, j;
	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &N, &M);
	vector<int> dp(M + 1);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &w, &v);

		for (j = w; j <= M; j++) 
			dp[j] = max(dp[j], dp[j - w] + v);
	}

	printf("%d\n", dp[M]);

	return 0;
}