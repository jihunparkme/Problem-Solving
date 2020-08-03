#include <cstdio>
#define ll long long
//ll DP[31] = { 0, 0, 3, };

int main(void)
{
	/*int n, i;
	scanf("%d", &n);
	if (n % 2 != 0) {
		printf("0\n");
		return 0;
	}

	for (i = 4; i <= n; i+=2) {
		DP[i] = DP[i - 2] * DP[2];
	}

	printf("%lld\n", DP[n]);
	 
	return 0;*/

    int N;
    int dp[31] = { 1,0,3 };
	scanf("%d", &N);

    if (N % 2 == 0)
        for (int i = 4; i <= N; i += 2) {
            dp[i] = dp[i - 2] * 3;

            for (int j = 4; i - j >= 0; j += 2)
                dp[i] += dp[i - j] * 2;
        }

	printf("%d\n", dp[N]);

    return 0;
}