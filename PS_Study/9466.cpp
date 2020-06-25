#include <cstdio>
#include <string.h>
const int MAXN = 100001;
int n, res, s[MAXN], ck[MAXN], ckin[MAXN];

void dfs(int now)
{
	ck[now] = 1;
	int next = s[now];

	if (!ck[next]) dfs(next);
	else if (!ckin[next]) {
		for (int i = next; i != now; i = s[i]) 
			res++;
		res++;
	}

	ckin[now] = 1;
}

void process()
{
	int i;
	scanf("%d", &n);
	memset(ck, 0, sizeof(ck));
	memset(ckin, 0, sizeof(ckin));

	for (i = 1; i <= n; i++) 
		scanf("%d", &s[i]);
	
	res = 0;
	for (i = 1; i <= n; i++) {
		if (!ck[i]) 
			dfs(i);
	}

	printf("%d\n", n - res);
}

int main(void)
{
	int tc;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);

	while (tc--)
		process();

	return 0;
}