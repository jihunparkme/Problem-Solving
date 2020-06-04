#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

void D(int x) {
	if (x > 7) return;
	else {
		D(x * 2);
		D(x * 2 + 1);
		printf("%d ", x);
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	D(1);
	return 0;
}