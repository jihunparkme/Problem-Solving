/*
 * Author: Jihun Park
 * Date: April 19, 2020
 * https://www.acmicpc.net/problem/1463
 */

#include <cstdio>

int dp[1000001], N, i = 2;

int main()
{
	scanf("%d", &N);

	for (; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) 
			dp[i] = dp[i] > dp[i / 2] ? dp[i / 2] + 1 : dp[i];
		
		if (i % 3 == 0) 
			dp[i] = dp[i] > dp[i / 3] ? dp[i / 3] + 1 : dp[i];

	}

	printf("%d\n", dp[N]);

	return 0;
}

//int N, min = 1e6;
//
//void bruteForce(int x, int cnt)
//{
//	if (x == 1)
//		min = min < cnt ? min : cnt;
//	else
//	{
//		if (!(x % 3))
//			bruteForce(x / 3, cnt + 1);
//
//		if (!(x % 2))
//			bruteForce(x / 2, cnt + 1);
//
//		bruteForce(x - 1, cnt + 1);
//	}
//}