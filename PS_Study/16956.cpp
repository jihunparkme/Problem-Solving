#include <cstdio>

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int r, c;
char map[501][501];

void check()
{
	int x, y, i;

	for (x = 1; x <= r; x++)
	{
		for (y = 1; y <= c; y++)
		{
			if (map[x][y] == 'W')
			{
				for (i = 0; i < 4; i++)
				{
					int xx = x + dx[i];
					int yy = y + dy[i];

					if (map[xx][yy] == 'S')
					{
						printf("0\n");
						return;
					}

				}
			}
		}
	}

	printf("1\n");
	for (x = 1; x <= r; x++)
	{
		for (y = 1; y <= c; y++)
		{
			printf("%c", map[x][y]);
		}

		puts("");
	}

}

int main(void)
{
	int x, y;

	scanf("%d %d", &r, &c);
	for (x = 0; x <= r; x++)
	{
		for (y = 0; y <= c; y++)
		{
			scanf("%c ", map[x][y]);

			if (map[x][y] == '.')
				map[x][y] = 'D';
		}
	}


	check();

	return 0;
}