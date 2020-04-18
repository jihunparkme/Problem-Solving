#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>

typedef double dd;
const long double Eps = 1e-9;

double A, B, C;
int int_duf[128];
int deecimal_duf[128];

int toString(dd rst)
{
	dd temp1 = rst * 1000000;
	long long temp2 = (long long)round(temp1);

	// 정수를 배열에 저장(출력 시 정수는 거꾸로)
	int i = 0;
	while (temp2 != 0)
	{
		int_duf[i] = (long long)(temp2 % 10);
		temp2 = (long long)temp2 / 10;
		i++;
	}

	return i;
}

dd factorial(dd x)
{
	if (x <= 1) return 1;
	return x * factorial(x - 1);
}

dd myPow(dd x, dd n)
{
	dd rst = 1;
	for (int i = 0; i < n; i++)
		rst *= x;
	return rst;
}

dd mySin(dd x)
{
	dd rst = x;
	dd sign = -1;
	for (int i = 3; i <= 100; i += 2)
	{
		rst += sign * (myPow(x, i) / factorial(i));
		sign *= -1;
	}
	return rst;
}

dd calcu(dd m)
{
	//printf("%.15lf\n", mySin(m));
	return A * m + B * mySin(m) - C;
}

int main()
{
	scanf("%lf %lf %lf", &A, &B, &C);

	dd lo = 0, hi;
	while (1)
	{
		if (calcu(lo) < 0)
			lo++;
		else
		{
			lo--;
			hi = lo + 1;
			break;
		}
	}

	dd mid = (lo + hi) / 2.0;

	while (calcu(mid) < -Eps || calcu(mid) > Eps)
	{
		mid = (lo + hi) / 2.0;
		dd rst = calcu(mid);
		if (rst <= 0)
			lo = mid;
		else hi = mid;

		if (rst > -Eps && rst < Eps) break;
	}

	dd rst = (lo + hi) / 2.0;
	//dd rst = 49493.071183;
	//printf("%.10lf\n\n", (lo + hi) / 2.0);

	int intCount = toString(rst);

	// 정수 출력
	if (intCount <= 6) printf("0.");

	for (int j = 0; j < 6 - intCount; j++) printf("0");

	for (int i = intCount - 1; i >= 0; i--)
	{
		printf("%d", int_duf[i]);
		if (i - 6 == 0) printf(".");
	}
	printf("\n");
}
