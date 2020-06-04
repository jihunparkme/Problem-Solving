/*
 * Author: Jihun Park
 * Date: April 18, 2020
 * https://www.acmicpc.net/problem/17614
 */

#include <iostream>

using namespace std;

 #define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int N, i = 1, cnt = 0;;

int main()
{
	fio;

	cin >> N;

	do
	{
		int temp = i;

		while (temp > 0)
		{
			cnt = (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9) ? cnt + 1 : cnt;

			temp = temp / 10;
		}

		i++;
	} while (i <= N);

	cout << cnt;

	return 0;
}