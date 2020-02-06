#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

//int s[1001] = { 0, 0, 1, 1, 3, 5 };	// default Sequence
int s[1001] = { 0, 0, 1, 1, 3, 5 };	

int plusOper(int a, int b)
{
	int xr = a ^ b;
	int ad = a & b;
	ad = ad << 1;

	while ((ad&xr) != 0)
	{
		int txor = ad^xr;
		int tand = ad&xr;
		int uand = tand << 1;
		ad = uand;
		xr = txor;
	}
	return xr^ad;
}

int minOper(int a, int b)
{
	int first = a ^ b;
	int second = a ^ (a | b);

	first = first ^ second;

	return plusOper(first, plusOper((~second), 1));
}

int tenConvertTwo(int num)
{
	int result = 0;
	for (int i = 1; num>0; i *= 10)
	{
		int binary = num % 2;
		result += binary * i;
		num /= 2;
	}
	return result;
}

int main() {
	int n;
	scanf_s("%d", &n);

	for (int i = 6; i <= 1001; i++) {
		if (i % 2 == 1) {
			s[i] = tenConvertTwo(minOper(plusOper(s[i - 1], s[i - 1]), 1));	// È¦¼ö
		}
		else {
			s[i] = tenConvertTwo(plusOper(plusOper(s[i - 1], s[i - 1]), 1));
			// Â¦¼ö
		}
	}

	printf("%d\n", s[n]);

	return 0;
}
