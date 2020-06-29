#include <cstdio>
#include <string.h>
using namespace std;

int g[1001], ck[1001];

void dfs(int x)
{
	int i;
	if (ck[x]) return;

	ck[x] = 1;
	dfs(g[x]);
}

void solve()
{
	int n, i, j, res = 0;
	memset(g, 0, sizeof(ck));
	memset(ck, 0, sizeof(ck));
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%d", g + i);

	for (i = 1; i <= n; i++) {
		if (ck[i]) continue;

		dfs(i);
		res++;
	}

	printf("%d\n", res);
}

int main(void)
{
	int tc;
	// freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);

	while (tc--)
		solve();

	return 0;
}