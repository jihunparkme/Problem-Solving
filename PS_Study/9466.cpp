#include <cstdio>
#include <string.h>
const int MAXN = 100001;
int n, res, s[MAXN];
bool visited[MAXN], ck[MAXN];

void dfs(int now)
{
	visited[now] = true;
	int next = s[now];

	if (!visited[next]) dfs(next);
	else if (!ck[next]) {
		for (int i = next; i != now; i = s[i])
			res++;
		res++;
	}

	ck[now] = true;
}

void process()
{
	int i;
	scanf("%d", &n);
	memset(visited, 0, sizeof(visited));
	memset(ck, 0, sizeof(ck));

	for (i = 1; i <= n; i++)
		scanf("%d", &s[i]);

	res = 0;
	for (i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i);
	}

	printf("%d\n", n - res);
}

int main(void)
{
	int tc;
	// freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);

	while (tc--)
		process();

	return 0;
}