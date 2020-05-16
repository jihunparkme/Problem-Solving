#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define MAX 2147000000
#define MIN -2147000000

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	int N, L, K, a, b, i, easy = 0, hard = 0, score = 0;

	scanf("%d %d %d", &N, &L, &K);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);

		if (b <= L)
			hard++;
		else if (a <= L)
			easy++;
	}

	score = min(hard, K) * 140;

	if (hard < K)
		score += min(easy, K - hard) * 100;

	printf("%d\n", score);

	return 0;
}