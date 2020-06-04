#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2147000000
#define MIN -2147000000

int n;
vector<vector<int> > map, dp;

int DFS(int idx)
{
	int x = idx / n;
	int y = idx % n;

	if (x == 0 && y == 0) return map[0][0];
	if (dp[x][y]) return dp[x][y];

	if (!y) return dp[x][y] = DFS(idx - n) + map[x][y];
	else if (!x)  return dp[x][y] = DFS(idx - 1) + map[x][y];
	else return dp[x][y] = min(DFS(idx - 1), DFS(idx - n)) + map[x][y];
}

int main(void)
{
	int i, j;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	map.resize(n, vector<int>(n));
	dp.resize(n, vector<int>(n));

	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			scanf("%d", &map[i][j]);	

	printf("%d\n", DFS(n * n - 1));

	return 0;
}
