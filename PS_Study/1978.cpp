#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

bool isPrime[1001];

int main(void)
{
	int n, i, j, a, cnt = 0;
	memset(isPrime, 1, sizeof(isPrime));
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);

	isPrime[0] = isPrime[1] = false;
	int sqrt_n = int(sqrt(1000));
	for (i = 2; i <= sqrt_n; i++) {
		if (isPrime[i]) {
			for (j = i * i; j <= 1000; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (i = 0; i < n; i++) {
		scanf("%d", &a);

		if (isPrime[a]) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}