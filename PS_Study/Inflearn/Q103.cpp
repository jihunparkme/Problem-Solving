#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100
#define MIN -100

int main(void)
{
	int N, a, b, k, i, j, score = MAX, num = 0;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &N);
	vector<vector<int> > dis(N + 1, vector<int>(N + 1, MAX));
	vector<int> cand(N+1);

	while (true) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) break;
		dis[a][b] = 1;
		dis[b][a] = 1;
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
			cand[i] = max(cand[i], dis[i][j]);
		}
	}

	score = *min_element(cand.begin() + 1, cand.end());
	for (i = 1; i <= N; i++) 
		if (cand[i] == score) 
			num++;
	
	printf("%d %d\n", score, num);
	for (i = 1; i <= N; i++)
		if(cand[i] == score)
			printf("%d ", i);
	puts("");
	return 0;
}