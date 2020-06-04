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
	int a, b;
	scanf("%d %d", &a, &b);

	int gcd = GCD(a, b);
	printf("%d\n%d\n", gcd, a * b / gcd);

	return 0;
}