#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int map[21][21];

int main() {
	int n, m, a, b, c, i, j;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}