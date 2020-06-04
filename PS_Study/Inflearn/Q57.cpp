#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void toBinary(int x)
{
	if (x == 0) return;
	else
	{
		toBinary(x / 2);
		printf("%d", x % 2);
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n;

	scanf("%d", &n);

	toBinary(n);

	return 0;
}