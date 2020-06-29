#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define x first
#define y second

int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
int map[30][30];
vector<int> complex;

int main(void)
{
	int n, i, j, k, cnt;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%1d", &map[i][j]);

	queue<pair<int, int> > q;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j]) {
				q.push({ i, j });
				map[i][j] = 0;
				cnt = 0;

				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();
					cnt++;

					for (k = 0; k < 4; k++) {
						int xx = now.x + dx[k];
						int yy = now.y + dy[k];

						if (map[xx][yy]) {
							q.push({ xx, yy });
							map[xx][yy] = 0;
						}
					}
				}

				if(cnt)
					complex.push_back(cnt);
			}
		}
	}

	sort(complex.begin(), complex.end());
	printf("%ld\n", complex.size());
	for (i = 0; i < complex.size(); i++) 
		printf("%d\n", complex[i]);
	
	return 0;
}