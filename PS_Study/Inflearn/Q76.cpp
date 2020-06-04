#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int a[21];

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, r, i;
	a[1] = 1;

	scanf("%d %d", &n, &r);
	for (i = 2; i <= n; i++)
		a[i] = a[i - 1] * i;

	printf("%d\n", a[n] / (a[r] * a[n - r]));

	return 0;
}