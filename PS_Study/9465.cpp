#include <cstdio>
#include <vector>
using namespace std;

void solve()
{
	int n, i, j;
	scanf("%d", &n);
	
	vector<vector<int> > A(3, vector<int>(n + 1));
	vector<vector<int> > DP(3, vector<int>(n + 1));
	for (i = 1; i <= 2; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
}

int main(void)
{
	int tc;
	scanf("%d", &tc);

	while (tc--)
		solve();

	return 0;
}