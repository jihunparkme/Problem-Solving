#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int dist[101];

struct Edge {
	int s;
	int e;
	int val;
	Edge(int a, int b, int c) {
		s = a;
		e = b;
		val = c;
	}
};

int main() {
	freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;
	int i, n, m, a, b, c, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	}

	for (i = 1; i <= n; i++) {
		dist[i] = 2147000000;
	}

	dist[1] = 0;
	for (i = 1; i < n; i++) {
		for (j = 0; j < Ed.size(); j++) {
			int s = Ed[j].s;
			int e = Ed[j].e;
			int w = Ed[j].val;
			if (dist[s] != 2147000000 && dist[s] + w < dist[e]) {
				dist[e] = dist[s] + w;
			}
		}
	}

	for (j = 0; j < Ed.size(); j++) {
		int u = Ed[j].s;
		int v = Ed[j].e;
		int w = Ed[j].val;
		if (dist[u] != 2147000000 && dist[u] + w < dist[v]) {
			printf("-1\n");
			exit(0);
		}
	}
	printf("%d\n", dist[n]);

	return 0;
}