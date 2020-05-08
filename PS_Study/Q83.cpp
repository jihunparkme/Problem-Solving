#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define MAX 2147000000
#define MIN -2147000000

int rst[10], ch[10];

int Send()
{
	return rst[0] * 1000 + rst[1] * 100 + rst[2] * 10 + rst[3];
}

int More()
{
	return rst[4] * 1000 + rst[5] * 100 + rst[6] * 10 + rst[1];
}

int Money()
{
	return rst[4] * 10000 + rst[5] * 1000 + rst[2] * 100 + rst[1] * 10 + rst[7];
}

void DFS(int lv)
{
	int i;
	if (lv == 8)
	{
		if (Send() + More() == Money())
		{
			if (rst[0] != 0 && rst[4] != 0)
			{
				printf("  %d %d %d %d\n", rst[0], rst[1], rst[2], rst[3]);
				printf("+ %d %d %d %d\n", rst[4], rst[5], rst[6], rst[1]);
				printf("--------------\n");
				printf("%d %d %d %d %d\n", rst[4], rst[5], rst[2], rst[1], rst[7]);

			}
		}
	}
	else
	{
		for (i = 0; i <= 9; i++)
		{
			if (ch[i] == 0)
			{
				rst[lv] = i;
				ch[i] = 1;
				DFS(lv + 1);
				ch[i] = 0;
			}
		}
	}
}

int main(void)
{
	DFS(0);

	return 0;
}