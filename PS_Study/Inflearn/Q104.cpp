#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int N, M, i, a, b, now;
	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &N, &M);
	vector<vector<int> > graph(N+1);
	vector<int> degree(N + 1);
	queue<int> q;

	for (i = 1; i <= N; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		degree[b]++;
	}

	for (i = 1; i <= N; i++) {
		if (!degree[i]) q.push(i);
	}

	while (!q.empty()) {
		now = q.front();
		q.pop();
		printf("%d ", now);

		for (i = 0; i < graph[now].size(); i++) {
			int tmp = graph[now][i];
			degree[tmp]--;

			if (!degree[tmp])
				q.push(tmp);
		}
	}

	puts("");
	return 0;
}