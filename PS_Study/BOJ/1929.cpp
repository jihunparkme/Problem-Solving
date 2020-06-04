#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

const int MAX_N = 1000000;
bool isPrime[MAX_N + 1];

int main(void)
{
	int a, b, i, j;
	memset(isPrime, 1, sizeof(isPrime));
	scanf("%d %d", &a, &b);

	isPrime[0] = isPrime[1] = false;
	int sqrt_n = int(sqrt(MAX_N));
	for (i = 2; i <= sqrt_n; i++) {
		if (isPrime[i]) {
			for (j = i * i; j <= MAX_N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (i = a; i <= b; i++) {
		if (isPrime[i]) printf("%d\n", i);
	}

	return 0;
}