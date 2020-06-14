#include <cstdio>
using namespace std;

int A[1001], DP[2][1001];

int main(void)
{
	int n, i, j, res = 0;
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);

		int tmp = 0;
		for (j = 1; j < i; j++) {
			if (A[i] > A[j] && DP[0][j] > tmp)
				tmp = DP[0][j];
		}

		DP[0][i] = tmp + 1;
	}

	for (i = n; i >= 1; i--) {
		int tmp = 0;
		for (j = n; j > i; j--) {
			if (A[i] > A[j] && DP[1][j] > tmp)
				tmp = DP[1][j];
		}

		DP[1][i] = tmp + 1;
		if (DP[0][i] + DP[1][i] - 1 > res)
			res = DP[0][i] + DP[1][i] - 1;
	}

	printf("%d\n", res);

	return 0;
}