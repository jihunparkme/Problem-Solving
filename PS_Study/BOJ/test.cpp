#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int N, cnt;
int main() {
	scanf("%d", &N);
	while (N > 0)
	{
		if (!(N % 5)) break;
		N -= 3;
		cnt++;
	}
	printf("%d", (N < 0) ? -1 : N / 5 + cnt);
}

#include <iostream>
#include <string>
#define init() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

string str;
int main(void)
{
	init();

	getline(cin, str);
	int cnt = 0, len = str.length();

	for (int i = 1; i < len; i++)
	{
		if (str[i] == 32) cnt++;
	}
	if (str[len - 1] == 32) cnt--;

	cout << cnt + 1;
	return 0;
}
