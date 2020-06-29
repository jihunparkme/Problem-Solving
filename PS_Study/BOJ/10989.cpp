#include <cstdio>
using namespace std;

int cnt[10001];

int main(void)
{
	int n, i, j, a;
	// freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		cnt[a]++;
	}
	
	for (i = 1; i <= 10000; i++)
		if (cnt[i] > 0) {
			for (j = 0; j < cnt[i]; j++) {
				printf("%d\n", i);
			}
		}

	return 0;
}