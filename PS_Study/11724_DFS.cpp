#include <cstdio>
#include <vector>
using namespace std;

int ck[1001];
vector<int> vt[1001];

void dfs(int x) 
{
	ck[x] = 1;
	for (int i = 0; i < vt[x].size(); i++) {
		if (!ck[vt[x][i]]) 
			dfs(vt[x][i]);
	}

}

int main(void)
{
	int n, m, i, a, b, res = 0;
	// freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	for (i = 1; i <= n; i++) {
		if (ck[i]) continue;
		dfs(i);
		res++;
	}

	printf("%d\n", res);

	return 0;
}