#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int map[8][8], cnt = 0;

void DFS(int x, int y)
{
	if (map[x][y] == 1)
		return;

	if (x > 7 || y > 7 || x < 1 || y < 1)
		return;
	else if (x == 7 && y == 7)
		cnt++;
	else
	{
		map[x][y] = 1;

		DFS(x, y - 1);
		DFS(x, y + 1);
		DFS(x - 1, y);
		DFS(x + 1, y);

		map[x][y] = 0;
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i,j ;

	for (j = 1; j <= 7; j++)
	{
		for (i = 1; i <= 7; i++)
			scanf("%d", &map[i][j]);
	}

	DFS(1, 1);

	printf("%d\n", cnt);

	return 0;
}