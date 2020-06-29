#include <cstdio>
#include <string.h>
using namespace std;

void solve()
{
	int n, i, j, res = 0;
	int g[1001], ck[1001];
	memset(ck, 0, sizeof(ck));
	scanf("%d", &n);

	for (i = 1; i <= n; i++) 
		scanf("%d", g+i);

	for (i = 1; i <= n; i++) {
		if (ck[i]) continue;

		for (j = i; !ck[j]; j = g[j])
			ck[j] = 1;

		res++;
	}

	printf("%d\n", res);
}

int main(void)
{
	int tc;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);

	while (tc--)
		solve();


	return 0;
}