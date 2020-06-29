#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define pos pair<int, int>
#define x first
#define y second

int w, h;
int map[55][55];
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void process() 
{
	int i, j, k, res = 0;
	memset(map, 0, sizeof(map));

	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	queue<pos> Q;
	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			if (map[i][j]) {
				Q.push({ i, j });
				map[i][j] = 0;

				while (!Q.empty()) {
					pos now = Q.front();
					Q.pop();

					for (k = 0; k < 8; k++) {
						int xx = now.x + dx[k];
						int yy = now.y + dy[k];

						if (map[xx][yy]) {
							Q.push({ xx, yy });
							map[xx][yy] = 0;
						}
					}
				}

				res++;
			}
		}
	}
	
	printf("%d\n", res);
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	while (scanf("%d %d", &w, &h), w && h) 
		process();

	return 0;
}