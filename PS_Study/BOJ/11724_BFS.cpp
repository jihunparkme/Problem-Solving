#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int n, m, i, j, a, b, res = 0;
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);

	vector<vector<int> > vt(n + 1);
	vector<int> ck(n + 1);
	queue<int> q;

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	for (i = 1; i <= n; i++) {
		if (ck[i]) continue;

		q.push(i);
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (j = 0; j < vt[x].size(); j++) {
				if (!ck[vt[x][j]]) {
					ck[vt[x][j]] = 1;
					q.push(vt[x][j]);
				}
			}
		}

		res++;
	}

	printf("%d\n", res);

	return 0;
}