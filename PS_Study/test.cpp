/*
 * Author: Jihun Park
 * Date: April 18, 2020
 * https://www.acmicpc.net/problem/17614
 */
 /*
  * reference : hkim77
  */


#include <cstdio>

using namespace std;

int i;

int func(int n)
{
	if (n < 2)
		return 0;

	int a1 = func(n / 3) + n % 3 + 1;
	int a2 = func(n / 2) + n % 2 + 1;

	return a1 < a2 ? a1 : a2;
}
int main()
{
	freopen("input.txt", "rt", stdin);

	int num;

	scanf("%d", &num);

	printf("%d", func(num));
}