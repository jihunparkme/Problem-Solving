#include <cstdio>
using namespace std;

int arr[101];

int poww(int x, int y)
{
	int i, res = 1;
	for (i = 0; i < y; i++)
		res *= x;

	return res;
}

int main(void)
{
	int a, p, i, j;
	// freopen("input.txt", "rt", stdin);
	scanf("%d %d", &a, &p);

	arr[1] = a;
	for (i = 2; i <= 100; i++) {
		int n = arr[i-1];

		while (n != 0) {
			arr[i] += poww(n % 10, p);
			n /= 10;
		}

		for (j = 1; j < i; j++) {
			if (arr[i] == arr[j]) {
				printf("%d\n", j - 1);
				return 0;
			}
		}
	}

	return 0;
}