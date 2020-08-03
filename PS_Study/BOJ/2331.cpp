#include <cstdio>
using namespace std;
#define ll long long

int a, p, ck[250000];

int poww(int x, int y)
{
	int i, res = 1;
	for (i = 0; i < y; i++) 
		res *= x;

	return res;
}

void solve(int x, int idx)
{
	if (ck[x]) {
		printf("%d\n", ck[x] - 1);
		return;
	}

	ck[x] = idx;
	int tmp = 0, m;

	while (x != 0) {
		m = x % 10;
		tmp += poww(m, p);
		x /= 10;
	}

	solve(tmp, idx+1);
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &a, &p);

	solve(a, 1);

	return 0;
}