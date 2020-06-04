#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3;
int C[N], M[N];

int main(void)
{
	int i, now, nxt;

	for (i = 0; i < N; i++)
		scanf("%d %d", &C[i], &M[i]);
	
	for (i = 0; i < 100; i++)
	{
		now = i % 3;
		nxt = (i + 1) % 3;

		int tmp = max(M[now] - (C[nxt] - M[nxt]), 0);
		M[nxt] = min(C[nxt], M[nxt] + M[now]);
		M[now] = tmp;
	}

	for (i = 0; i < 3; i++)
		printf("%d\n", M[i]);
	
	return 0;
}