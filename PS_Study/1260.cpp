#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;	// 정점 개수, 간선 개수
vector<int> ck;
vector<vector<int> > vt;

void DFS(int s)
{
	int i;
	printf("%d ", s);
	for (i = 0; i < vt[s].size(); i++) {
		if (!ck[vt[s][i]]) {
			ck[vt[s][i]] = 1;
			DFS(vt[s][i]);
		}
	}
}

void BFS(int s)
{
	int i;
	vector<int> ck2(N + 1);
	queue<int> q;

	q.push(V);
	ck2[V] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
	
		for (i = 0; i < vt[x].size(); i++) {
			if (!ck2[vt[x][i]]) {
				q.push(vt[x][i]);
				ck2[vt[x][i]] = 1;
			}
		}

		printf("%d ", x);
	}
}

int main(void)
{
	int i, a, b;
	// freopen("input.txt", "rt", stdin);
	scanf("%d %d %d", &N, &M, &V);

	vt.resize(N + 1);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	for (i = 1; i <= N; i++) 
		sort(vt[i].begin(), vt[i].end());
	
	// DFS
	ck.resize(N+ 1, 0);
	ck[V] = 1;
	DFS(V);

	puts("");

	// BFS
	BFS(V);

	return 0;
}