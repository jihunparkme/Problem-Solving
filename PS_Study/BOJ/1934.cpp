#include <cstdio>
using namespace std;

int GCD(int a, int b)
{
	while (b != 0) {
		int rest = a % b;
		a = b;
		b = rest;
	}

	return a;
}

int main(void)
{
	int tc,  a, b;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a * b / GCD(a, b));
	}

	return 0;
}