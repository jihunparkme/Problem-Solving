#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define MAX 2147000000
#define MIN -2147000000

int n, r, cnt = 0, ch[20];

void DFS(int s, int L)
{
	int i;

	if (L == r)
	{
		for (i = 0; i < r; i++)
		{
			printf("%d ", ch[i]);
		}

		puts("");
		cnt++;
	}
	else
	{
		for (i = s; i < n; i++)
		{
			ch[L] = i;
			DFS(i + 1, L + 1);
		}
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	scanf("%d %d", &n, &r);
	
	DFS(0, 0);

	printf("%d\n", cnt);

	return 0;
}