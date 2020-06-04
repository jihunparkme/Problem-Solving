#include <cstdio>
#include <vector>
using namespace std;
#define MAX 2147000000
#define MIN -2147000000

vector<int> lst, dp;
int res = MIN;

void Process(int num, int pt)
{
	int i, length = 1, ans = MIN;

	for (i = 1; i <= pt; i++)
	{
		if (lst[i] <= num && dp[i] > ans)
			ans = dp[i];
	}

	dp[pt] = ans + 1;

	if (dp[pt] > res)
		res = dp[pt];
}

int main(void)
{
	int n, i;
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	lst.resize(n+1, 0), dp.resize(n+1, 0);

	for (i = 1; i <= n; i++) 
		scanf("%d", &lst[i]);

	for (i = 1; i <= n; i++)
		Process(lst[i], i);

	printf("%d\n", res);

	return 0;
}