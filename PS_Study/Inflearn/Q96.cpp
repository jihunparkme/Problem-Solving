#include <cstdio>
using namespace std;
#define MAX 2147000000
#define MIN -2147000000

int lst[101], dp[101];

int main(void)
{
	int n, i, j, mx, res = MIN; 
	// freopen("input.txt", "rt", stdin);
	scanf("%d\n", &n);

	for (i = 1; i <= n; i++)
		scanf("%d", &lst[i]);

	dp[1] = 1;
	for (i = 2; i <= n; i++){
		mx = 0;
			
		for (j = i; j >= 1; j--) {
			if (lst[i] > lst[j] && mx < dp[j]) 
				mx = dp[j];
		}

		dp[i] = mx + 1;
		if (res < dp[i])
			res = dp[i];
	}

	printf("%d\n", res);

	return 0;
}