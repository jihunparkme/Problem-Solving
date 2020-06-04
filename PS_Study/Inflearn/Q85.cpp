#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int a[20], op[5], n, maxi = -2147000000, mini = 2147000000;

void DFS(int L, int res) {
	if (L == n) {
		if (res > maxi) maxi = res;
		if (res < mini) mini = res;
	}
	else {
		if (op[0] > 0) {
			op[0]--;
			DFS(L + 1, res + a[L]);
			op[0]++;
		}
		if (op[1] > 0) {
			op[1]--;
			DFS(L + 1, res - a[L]);
			op[1]++;
		}
		if (op[2] > 0) {
			op[2]--;
			DFS(L + 1, res * a[L]);
			op[2]++;
		}
		if (op[3] > 0) {
			op[3]--;
			DFS(L + 1, res / a[L]);
			op[3]++;
		}
	}
}


int main() {
	freopen("input.txt", "rt", stdin);
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}

	DFS(1, a[0]);

	printf("%d\n%d\n", maxi, mini);
	return 0;
}