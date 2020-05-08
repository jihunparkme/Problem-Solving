#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define f first
#define s second
#define MAX 2147000000
#define MIN -2147000000

int n, r, rst = 0, a[16], ch[16], prt[16];

void DFS(int cnt)
{
	int i;

	if (cnt == r)
	{
		for (i = 0; i < r; i++)
			printf("%d ",prt[i]);
		puts("");

		rst++;
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			if (ch[i] == 0)
			{
				prt[cnt] = a[i];
				ch[i] = 1;
				DFS(cnt + 1);
				ch[i] = 0;
			}
		}
	}

}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int i;

	scanf("%d %d", &n, &r);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	DFS(0);

	printf("%d\n", rst);

	return 0;
}