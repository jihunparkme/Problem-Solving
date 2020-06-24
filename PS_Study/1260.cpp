#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;	// 정점 개수, 간선 개수
vector<int> ch;
vector<vector<int> > vt;

void DFS(int s)
{
	int i;
	if (ch[s]) return;
	
	ch[s] = 1;
	printf("%d ", s);
	for (i = 0; i < vt[s].size(); i++) {
		DFS(vt[s][i]);
	}
}

void BFS(int s)
{
	int i;
	vector<int> ch2(N + 1);
	queue<int> q;

	q.push(V);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (!ch2[x])
			printf("%d ", x);
		ch2[x] = 1;

		for (i = 0; i < vt[x].size(); i++) {
			if (!ch2[vt[x][i]])
				q.push(vt[x][i]);
		}
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
	ch.resize(N+ 1, 0);
	DFS(V);

	puts("");

	// BFS
	BFS(V);

	return 0;
}