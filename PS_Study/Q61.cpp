#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, a[11], cnt = 0, path[10];

void DFS2(int lv, int sum)
{
	if (sum == m)
	{
		cnt++;
		for (int i = 1; i < lv; i++)
			printf("%d ", path[i]);
		puts("");
		
		return;
	}

	if (lv == n + 1)
		return;
	else
	{
		path[lv] = a[lv];
		DFS2(lv + 1, sum + a[lv]);
		path[lv] = -a[lv];
		DFS2(lv + 1, sum - a[lv]);
		path[lv] = 0;
		DFS2(lv + 1, sum);
	}
}

void DFS(int L, int sum) {
	if (L == n + 1) {
		if (sum == m) {
			cnt++;
			for (int i = 1; i < L; i++) {
				printf("%d ", path[i]);
			}
			puts("");
		}
	}
	else {
		path[L] = a[L];
		DFS(L + 1, sum + a[L]);
		path[L] = -a[L];
		DFS(L + 1, sum - a[L]);
		path[L] = 0;
		DFS(L + 1, sum);
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i;

	scanf("%d %d", &n, &m);

	for (i = 1; i < n + 1; i++)
		scanf("%d", &a[i]);

	DFS2(1, 0);

	if(cnt)
		printf("%d\n", cnt);
	else
		printf("-1\n");

	return 0;
}