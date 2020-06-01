#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 5000

int main(void)
{
	int N, M, a, b, c, i, j, k;
	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &N, &M);
	vector<vector<int> > dis(N + 1, vector<int>(N + 1, MAX));
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		dis[a][b] = c;
	}

	for (i = 1; i <= N; i++)
		dis[i][i] = 0;

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (k == i) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if(dis[i][j] >= 5000)
				printf("M ");
			else
				printf("%d ", dis[i][j]);
		}
		puts("");
	}

	return 0;
}