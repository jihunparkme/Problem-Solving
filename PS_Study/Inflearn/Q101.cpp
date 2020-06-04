#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M, i, j, s, t;
	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &N, &M);	// 문제 개수, 제한시간
	vector<int> dp(M+1);

	for (i = 1; i <= N; i++) {
		scanf("%d %d", &s, &t);	// 점수, 시간

		for (j = M; j >= t; j--) 
			dp[j] = max(dp[j], dp[j - t] + s);
	}

	printf("%d\n", dp[M]);

	return 0;
}