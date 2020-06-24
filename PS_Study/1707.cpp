#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

bool solve()
{
	int v, e, i, j, a, b;

	scanf("%d %d", &v, &e);

	vector<vector<int> > vt(v + 1);
	vector<int> ck(v + 1);
	queue<int> q;

	for (i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	for (i = 1; i <= v; i++) {
		if (ck[i]) continue;

		q.push(i);
		ck[i] = 1;

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (j = 0; j < vt[x].size(); j++) {
				if (ck[vt[x][j]] == 0) {
					if (ck[x] == 1) ck[vt[x][j]] = -1;
					else ck[vt[x][j]] = 1;

					q.push(vt[x][j]);
				}
				else {
					if (ck[x] + ck[vt[x][j]] != 0) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main(void)
{
	int tc;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);

	while (tc--) {
		if(solve()) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}