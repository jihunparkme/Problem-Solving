#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void solve()
{
	int n, i, a, res = 0;
	scanf("%d", &n);
	vector<vector<int> > g(n + 1);
	vector<int> ck(n + 1);
	queue<int> q;

	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		g[i].push_back(a);
	}

	for(i=1;i<=n;i++){
		if (ck[i]) continue;

		q.push(i);
		ck[i] = 1;
		
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			if (!ck[g[now][0]]) {
				ck[g[now][0]] = 1;
				q.push(g[now][0]);
			}
			else {
				res++;
				break;
			}
		}
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