#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <quadmath.h>

typedef __float128 dd;
const __float128 Eps = 1e-12q;

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

int main()
{
	scanf("%lf %lf %lf", &A, &B, &C);

	dd l = 0, r = 200000, m;
	B /= A, C /= A;
	for (int i = 0; i < 1000; i++) {
		m = (l + r) / 2;
		dd y = m + B * sin(m);
		if (y < C) l = m;
		else r = m;
	}

	int intCount = toString(m);

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
