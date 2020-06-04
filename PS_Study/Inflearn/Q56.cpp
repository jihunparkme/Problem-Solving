#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void Solution(int x)
{
	if (x == 0)
		return;
	else
	{
		Solution(x - 1);

		printf( "%d ", x);
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n;

	scanf("%d", &n);

	Solution(n);

	return 0;
}